#include "fv4l2.h"


/* V4L2
步骤：
1.打开视频设备文件
2.视频采集的参数初始化，设置视频图像的采集窗口、采集的点阵大小和格式
3.申请若干视频采集的帧缓冲区
4.将缓冲区从内核映射到用户空间
5.将申请的帧缓冲区在视频采集输入队列排队
6.启动视频采集，驱动开始视频数据采集
7.从视频采集输出队列取出帧缓冲区
8.将帧缓冲区重新放入视频采集输入队列
9.停止视频采集
*/


fv4l2::fv4l2()
{
    

}

int  fv4l2::linux_v4l2_device_init(string device_name){
    fd = open(device_name.c_str(),O_RDWR);      //打开视频设备文件
    if(fd<0){
        printf("open camera failed\n");
        return -1;
    }
    printf("open camera success\n");
    printf("------------------------------------\n");
    struct v4l2_capability cap;


    if(ioctl(fd,VIDIOC_QUERYCAP,&cap)==-1){  //VIDIOC_QUERYCAP  查询摄像头信息,通过结构 v4l2_capability 获取设备支持的操作模式

        printf("query device info failed\n");
        return -2;
    }
    printf("device's information:\n");
    printf("driver name: %s\ncard name: %s\nbus_info: %s\n\
version: %d\ncapabilities: %d\n",\
           cap.driver,cap.card,cap.bus_info,cap.version,cap.capabilities);
    printf("------------------------------------\n");


    //列举摄像头所支持像素格式。使用命令VIDIOC_ENUM_FMT，获取到的信息通过结构体v4l2_fmtdesc查询。
    struct v4l2_fmtdesc fmtdesc;
    fmtdesc.index = 0;
    fmtdesc.type = V4L2_BUF_TYPE_VIDEO_CAPTURE; //视频捕捉模式
    printf("support format:\n");
    while(ioctl(fd,VIDIOC_ENUM_FMT,&fmtdesc)!=-1){
        printf("v4l2 format：%s\n",fmtdesc.description);
        printf("flags:%d\n",fmtdesc.flags);
        printf("pixelformat:%d\n",fmtdesc.pixelformat);
        fmtdesc.index++;
    }
    printf("-------------------------------------\n");

    int ret;
    //设置摄像头帧格式
    ret = linux_v4l2_set_format();
    if(ret<0){
        printf("set format failed\n");
        return -3;
    }
    return 0;
}


//设置摄像头帧格式
int fv4l2::linux_v4l2_set_format(){
    char fmtstr[8];
    struct v4l2_format fmt;
    memset(&fmt,0,sizeof(struct v4l2_format));
    fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;

    fmt.fmt.pix.pixelformat = V4L2_PIX_FMT_MJPEG;//支持YUV和MJPEG，选择MJPEG
    //fmt.fmt.pix.pixelformat = V4L2_PIX_FMT_YUYV;
    fmt.fmt.pix.width = PIXWIDTH;
    fmt.fmt.pix.height = PIXHEIGHT;
    fmt.fmt.pix.field = V4L2_FIELD_INTERLACED;
    if(ioctl(fd, VIDIOC_S_FMT, &fmt) == -1){

        printf("VIDIOC_S_FMT failed\n");
        return -3;
    }
    printf("VIDIOC_S_FMT success\n");
    printf("-------------------------------------\n");

    //为了确保设置的格式作用到摄像头上，再通过命令VIDIOC_G_FMT将摄像头设置读取回来。
    if(ioctl(fd,VIDIOC_G_FMT,&fmt)==-1){
        printf("VIDIOC_G_FMT failed\n");
        return -4;
    }
    printf("VIDIOC_G_FMT success\n");
    memset(fmtstr,0,8);
    memcpy(fmtstr,&fmt.fmt.pix.pixelformat,4);
    printf("current format: %s\n", fmtstr);
    printf("width: %ld,  height: %ld,  colorspace: %ld, type: %ld\n",\
              fmt.fmt.pix.width, fmt.fmt.pix.height, fmt.fmt.pix.colorspace,\
              fmt.type);
    printf("pix field: %d\n", fmt.fmt.pix.field);
    printf("--------------------------------------\n");
    return 0;

}


//申请缓存区。使用参数VIDIOC_REQBUFS和结构体v4l2_requestbuffers。
//v4l2_requestbuffers结构中定义了缓存的数量，系统会据此申请对应数量的视频缓存
int fv4l2::linux_v4l2_init_mmap(){
    struct v4l2_requestbuffers req;
    memset(&req,0,sizeof(struct v4l2_requestbuffers));
    req.count = BUFFERCOUNT;
    req.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    req.memory = V4L2_MEMORY_MMAP;
    if(ioctl(fd,VIDIOC_REQBUFS,&req)==-1){
        printf("VIDIOC_REQBUFS failed\n");
        ::close(fd);

        return -5;
    }
    printf("VIDIOC_REQBUFS success\n");
    printf("--------------------------------------\n");
    unsigned int n_buffers = 0;
    buffers = (struct buffer*)calloc(req.count,sizeof(struct buffer));//将四个已申请到的缓冲帧映射到应用程序，用buffers指针记录
    for(n_buffers = 0;n_buffers<req.count;n_buffers++){
        struct v4l2_buffer buf;                 //命令通过结构 v4l2_buffer 查询驱动申请的内存区信息：
        memset(&buf,0,sizeof(buf));
        buf.index = n_buffers;
        buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        buf.memory = V4L2_MEMORY_MMAP;
        if(ioctl(fd,VIDIOC_QUERYBUF,&buf)==-1){  //VIDIOC_QUERYBUF   向驱动提出申请内存的请求

            printf("VIDIOC_QUERYBUF failed\n");
            ::close(fd);
            return -6;
        }
        printf("VIDIOC_QUERYBUF success\n");

        //帧缓冲区映射到用户空间
        buffers[n_buffers].length = buf.length;
        buffers[n_buffers].start = mmap(NULL,buf.length,\
                                       PROT_READ|PROT_WRITE,\
                                       MAP_SHARED,\
                                       fd,buf.m.offset);
        if(buffers[n_buffers].start == MAP_FAILED){
            printf("memory map failed\n");
            ::close(fd);
            return -7;

        }
        printf("memory map success\n");

        if(ioctl(fd,VIDIOC_QBUF,&buf)==-1){     //将空闲的内存加入可捕获视频的队列
            printf("VIDIOC_QBUF failed\n");
            ::close(fd);
            return -8;
        }
        printf("VIDIOC_QBUF success\n");
        printf("buffer:%d\n address:%p\n length:%d\n",\
               n_buffers,buffers[n_buffers].start,buffers[n_buffers].length);

    }
    return 0;
}

int fv4l2::linux_v4l2_stream_start(){
    int ret = 0;
    ret = linux_v4l2_init_mmap();
    if(ret<0){
        printf("------------------------------------\n");
        return -1;
    }
    enum v4l2_buf_type type;
    type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    if(ioctl(fd,VIDIOC_STREAMON,&type)==-1){    //打开视频流
        printf("VIDIOC_STREAMON failed\n");
        return -9;
    }
    printf("VIDIOC_STREAMON success\n");
    return 0;
}

int fv4l2::linux_v4l2_get_one_frame(FreamBuffer *freambuf_t){
    fd_set fds;
    struct timeval tv;
    FD_ZERO(&fds);
    FD_SET(fd,&fds);
    tv.tv_sec = 2;
    tv.tv_usec = 0;
    int ret;
    ret = select(fd+1,&fds,NULL,NULL,&tv);
    
    //将帧缓冲添加到队列
    struct v4l2_buffer one_buf;
    memset(&one_buf,0,sizeof(one_buf));
    one_buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    one_buf.memory = V4L2_MEMORY_MMAP;

    if(ioctl(fd,VIDIOC_DQBUF,&one_buf)==-1){    // 将已经捕获好视频的内存拉出已捕获视频的队列
        printf("VIDIOC_DQBUF failed!\n");
        return -10;
    }
    memcpy(freambuf_t->buf,(char *)buffers[one_buf.index].start,one_buf.bytesused);//bytesused buf中已经使用的字节数
    freambuf_t->length = one_buf.bytesused;

    if(ioctl(fd,VIDIOC_QBUF,&one_buf)==-1){
        printf("VIDIOC_QBUF failed\n");
        return -1;
    }
    return 0;
}

int fv4l2::linux_v4l2_device_release(){
    int i;
    //释放映射缓冲区
    
    for(i=0;i<BUFFERCOUNT;i++){
        munmap(buffers[i].start,buffers[i].length);
    }
    printf("munmap success\n");
    ::close(fd);
    printf("camera release finished\n");
    return 0;
}
















