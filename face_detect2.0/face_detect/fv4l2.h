#ifndef FV4L2_H
#define FV4L2_H

#include <QMainWindow>
#include <stdio.h>
#include <linux/videodev2.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <string>
#include <QTimer>
using namespace std;

#define BUFFERCOUNT 4
#define PIXWIDTH    530
#define PIXHEIGHT   360

struct buffer{
    void *start;
    unsigned int length;
};

typedef struct Fream_BUffer{
    unsigned char buf[PIXHEIGHT*PIXWIDTH*3];
    int length;
}FreamBuffer;


class fv4l2
{
public:
    fv4l2();
    int linux_v4l2_device_init(string device_name);
    
    int linux_v4l2_set_format();
    
    int linux_v4l2_init_mmap();
    
    int linux_v4l2_stream_start();
    
    int linux_v4l2_get_one_frame(FreamBuffer * freambuf_t);
    
    int linux_v4l2_device_release();
private:
   
    int fd;
    struct buffer *buffers;

   
};

#endif // FV4L2_H
