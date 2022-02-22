#include "recognize.h"
#include "ui_recognize.h"

static Ptr<cv::face::FaceRecognizer>modelPCA = cv::face::EigenFaceRecognizer::create();

recognize::recognize(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::recognize)
{
    ui->setupUi(this);
    QTimer * time_calender1;
    time_calender1 = new QTimer(this);
    connect(time_calender1,SIGNAL(timeout()),this,SLOT(timeupdate1()));
    connect(time_calender1,SIGNAL(timeout()),this,SLOT(timeupdate2()));
    time_calender1->start(1000);
    
    facemark = face::FacemarkLBF::create();
    facemark->loadModel("/opt/wkspace/opencv/opencv-3.4.1/data/lbpcascades/lbfmodel.yaml");
    //加载关键点检测器（lbfmodel.yaml）

    modelPCA->read("/var/c/qt/face_detect/MyFacePCAModel.xml");
    //人脸识别模型

   // if(!face_cascade.load("/opt/wkspace/opencv/opencv-3.4.1/data/haarcascades_cuda/haarcascade_frontalface_alt2.xml"))
    if(!face_cascade.load("/opt/wkspace/opencv/opencv-3.4.1/data/haarcascades/haarcascade_frontalface_alt2.xml"))
        qDebug()<<"Error loading face cascade\n";
       //cout<<"Error loading face cascade\n";


    //image = new QImage();
    /*使用opencv自带的库函数打开摄像头
    connect(timer,SIGNAL(timeout()),this,SLOT(readFrame()));
    cap.open(0);
    timer->start(200);
    */


    //使用v4l2驱动打开摄像头

    camera.linux_v4l2_device_init("/dev/video0");
    camera.linux_v4l2_stream_start();

    mtimer = new QTimer();
    connect(mtimer, SIGNAL(timeout()), this, SLOT(readFrame()));
    mtimer->start(50);

}

recognize::~recognize()
{
    delete ui;
}



void recognize::timeupdate1(){
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("  hh     mm");
    ui->hm_label->setText(str);
    ui->hm_label->setStyleSheet("color:white");       
}
void recognize::timeupdate2(){
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy/MM/dd   \ndddd");
    ui->ymd_label->setText(str);
    ui->ymd_label->setStyleSheet("color:white");
}

void recognize::readFrame(){
    FreamBuffer Frame;
  //  QPixmap pix;

    camera.linux_v4l2_get_one_frame(&Frame);
    image = QImage::fromData(Frame.buf, Frame.length);  //将从摄像头获取的一帧图像存入QImage对象
    while(image.isNull());

    image = image.convertToFormat(QImage::Format_RGB888); //qt操作图像是QImage，opencv操作图像是Mat，该语句将QImage转换成Mat格式

    frame = Mat(image.height(), image.width(), CV_8UC3, image.bits(), image.bytesPerLine());

    Mat gray,frame1,frame2;
    vector<Rect>faces;
    vector<vector<Point2f> >landmarks;
    //视频帧中可能有多张脸，所以我们应采用点的容器的容器。


    cvtColor(frame,gray,COLOR_RGB2BGR);
    cvtColor(gray,gray,COLOR_BGR2GRAY);

    //rgb图像转化为灰度图像，三通道转为一通道后，运算量大大减少。色彩信息对检测没什么用。所以我们把它转成灰度图，并标准化。



    //cvtColor(frame,frame1,COLOR_BGR2RGB);
    //因为opencv中默认图像通道顺序为BGR，而Qt中默认图像颜色通道为RGB，因此转换过程中，需要对通道顺序进行调整：



    //QImage img((const uchar*)frame1.data,frame1.cols,frame1.rows,frame1.cols*frame1.channels(),QImage::Format_RGB888);
    //ui->open_lable->setPixmap(QPixmap::fromImage(img));
    //将图片放入label，使用setPixmap

    equalizeHist(gray,gray);
    //直方图均衡化的目的，就是把原始的直方图变换为在整个灰度范围（0~255）内均匀分布的形式，从而增加像素灰度值的动态范围，达到增强图像整体对比度的效果。

    face_cascade.detectMultiScale(gray,faces,1.1,4,0|CASCADE_SCALE_IMAGE,Size(90,90));


    if(faces.size()==1)
    {
        Mat face,face_test;
        bool flag = 0;
        int predictPCA = 0,row = 1;
        string name;
        string id;
       // fstream file;
        string line;
        face = gray(faces[0]);
        if(face.rows>=120){
            cv::resize(face,face_test,Size(92,112));
        }
        if(!face_test.empty()){
            predictPCA = modelPCA->predict(face_test);
            qDebug()<<"===========predictPCA:"<<predictPCA<<endl;
        }
        //file.open("/var/c/qt/face_detect/photos/name.txt",ios::in);
        std::ifstream file("/var/c/qt/face_detect/photos/name.txt", std::ios::in);


        while(getline(file, line)){
            qDebug()<<"===========getline(file, line)"<<endl;
            if(row == predictPCA){
                flag = true;
                std::stringstream word(line);
                word>>name;
                word>>id;
                mtimer->stop();
                //cap.release();
                camera.linux_v4l2_device_release();
                break;
            }
            else
                row++;
        }

        file.close();

        if(flag==true){
            ui->name_label->setText(name.c_str());
            ui->id_label->setText(id.c_str());
        }else{
            ui->name_label->setText("no name");
        }
    }


    for(size_t i =0;i<faces.size();i++){

        Point center(faces[i].x+faces[i].width/2,faces[i].y+faces[i].height/2);
        //获得每张脸部中心的xy像素坐标
        ellipse(frame,center,Size(faces[i].width/2,faces[i].height/2),0,0,360,Scalar(255,0,255),4,8,0);

    }


    bool success = facemark->fit(frame,faces,landmarks);
    if(success){

        for(int i=0;i<landmarks.size();i++){
            drawLandmarks(frame,landmarks[i]);
        }

    }
    //cvtColor(frame,frame2,COLOR_BGR2RGB);
    QImage img1((const uchar*)frame.data,frame.cols,frame.rows,frame.cols*frame.channels(),QImage::Format_RGB888);
    ui->open_lable->setAlignment(Qt::AlignCenter);  //居中显示
    img1.scaled(ui->open_lable->width(),ui->open_lable->height(),Qt::KeepAspectRatio);
    ui->open_lable->setScaledContents(true);
    ui->open_lable->setPixmap(QPixmap::fromImage(img1));
}

void recognize::drawPolyline(Mat &im, const vector<Point2f> &landmarks, const int start, const int end, bool isClosed){
    vector<Point>points;
    for(int i=start;i<=end;i++){
        points.push_back(Point(landmarks[i].x,landmarks[i].y));
    }
    polylines(im,points,isClosed,COLOR,2,16);
   // qDebug()<<"huaxianhuaxian"<<endl;
    /*
    src：要处理的图像。
    points：点集。
    isClosed：布尔型，True表示的是线段闭合，False表示的是仅保留线段。
    color：线段颜色，格式是（B,G,R）值。
    thickness：数值型，厚度，默认值为1，如果对封闭图形，正方形，三角形等传入-1,则会填充整个图形。

    */
}
void recognize::drawLandmarks(Mat &im, vector<Point2f> &landmarks)
{

    // Draw face for the 68-point model.
    if (landmarks.size() == 68)
    {

     // qDebug()<<"jiancejiance\n";
      drawPolyline(im, landmarks, 0, 16);           // Jaw line
      drawPolyline(im, landmarks, 17, 21);          // Left eyebrow
      drawPolyline(im, landmarks, 22, 26);          // Right eyebrow
      drawPolyline(im, landmarks, 27, 30);          // Nose bridge
      drawPolyline(im, landmarks, 30, 35, true);    // Lower nose
      drawPolyline(im, landmarks, 36, 41, true);    // Left eye
      drawPolyline(im, landmarks, 42, 47, true);    // Right Eye
      drawPolyline(im, landmarks, 48, 59, true);    // Outer lip
      drawPolyline(im, landmarks, 60, 67, true);    // Inner lip
    }
    else
    { // If the number of points is not 68, we do not know which
      // points correspond to which facial features. So, we draw
      // one dot per landamrk.
      for(int i = 0; i < landmarks.size(); i++)
      {
        circle(im,landmarks[i],3, COLOR, FILLED);
      }
    }

}





void recognize::on_closebt_clicked()
{
    camera.linux_v4l2_device_release();
}
