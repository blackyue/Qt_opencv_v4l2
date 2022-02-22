#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *time_calender1;
    time_calender1 = new QTimer(this);
    connect(time_calender1,SIGNAL(timeout()),this,SLOT(timerupdate()));
    connect(time_calender1,SIGNAL(timeout()),this,SLOT(timerupdate2()));
    time_calender1->start(1000);

    facemark = face::FacemarkLBF::create();
    facemark->loadModel("/opt/wkspace/opencv/opencv-3.4.1/data/lbpcascades/lbfmodel.yaml");
    //加载关键点检测器（lbfmodel.yaml）

   // if(!face_cascade.load("/opt/wkspace/opencv/opencv-3.4.1/data/haarcascades_cuda/haarcascade_frontalface_alt2.xml"))
    if(!face_cascade.load("/opt/wkspace/opencv/opencv-3.4.1/data/haarcascades/haarcascade_frontalface_alt2.xml"))
        qDebug()<<"Error loading face cascade\n";
       //cout<<"Error loading face cascade\n";

    facefilenum = get_file_count("/var/c/qt/face_detect/photos/");
    timer = new QTimer(this);
   // image = new QImage();


    connect(timer,SIGNAL(timeout()),this,SLOT(readFrame()));
    

}

int MainWindow::count = 0;
int MainWindow::temp_count = 0;


void MainWindow::timerupdate(){
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("  hh     mm");
    ui->hm_label->setText(str);
    ui->hm_label->setStyleSheet("color:white");
}

void MainWindow::timerupdate2(){
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy/MM/dd   \ndddd");
    ui->ymd_label->setText(str);
    ui->ymd_label->setStyleSheet("color:white");
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //cap.open(0);
    camera.linux_v4l2_device_init("/dev/video0");
    camera.linux_v4l2_stream_start();
    timer->start(50);
}

void MainWindow::on_pushButton_2_clicked()
{
    timer->stop();
   // cap.release();
    camera.linux_v4l2_device_release();
    getcsv1();
    namein();
    facetrain();
    this->close();
    recognize *rec = new recognize();
    rec->show();
}



int MainWindow::get_file_count(char *root)
{
    DIR*dir;
    struct dirent*ptr;
    int total = 1;
    dir = opendir(root);
    if(dir==NULL){
        perror("fail to open dir");
        exit(1);
    }

    while((ptr=readdir(dir))!=NULL){
        //顺序读取每一个目录项；跳过“.”和“..”两个目录
        //“.”是当前目录，“..”是前一个目录，父目录
        if(strcmp(ptr->d_name,".")==0||strcmp(ptr->d_name,"..")==0)
            continue;
        if(ptr->d_type==DT_DIR)
            total++;
    }
    closedir(dir);
    return total;
}
void MainWindow::readFrame(){
    //cap>>frame;

    string filename;
    Mat gray,frame1,frame2;
    vector<Rect>faces;
    vector<vector<Point2f> >landmarks;
    //视频帧中可能有多张脸，所以我们应采用点的容器的容器。


    FreamBuffer Frame;
  //  QPixmap pix;

    camera.linux_v4l2_get_one_frame(&Frame);
    image = QImage::fromData(Frame.buf, Frame.length);  //将从摄像头获取的一帧图像存入QImage对象
    while(image.isNull());

    image = image.convertToFormat(QImage::Format_RGB888); //qt操作图像是QImage，opencv操作图像是Mat，该语句将QImage转换成Mat格式

    frame = Mat(image.height(), image.width(), CV_8UC3, image.bits(), image.bytesPerLine());


    cvtColor(frame,gray,COLOR_RGB2BGR);
    cvtColor(gray,gray,COLOR_BGR2GRAY);
    //rgb图像转化为灰度图像，三通道转为一通道后，运算量大大减少。色彩信息对检测没什么用。所以我们把它转成灰度图，并标准化。



   // cvtColor(frame,frame1,COLOR_BGR2RGB);
    //因为opencv中默认图像通道顺序为BGR，而Qt中默认图像颜色通道为RGB，因此转换过程中，需要对通道顺序进行调整：



    //QImage img((const uchar*)frame1.data,frame1.cols,frame1.rows,frame1.cols*frame1.channels(),QImage::Format_RGB888);
    //ui->open_lable->setPixmap(QPixmap::fromImage(img));
    //将图片放入label，使用setPixmap

    equalizeHist(gray,gray);
    //直方图均衡化的目的，就是把原始的直方图变换为在整个灰度范围（0~255）内均匀分布的形式，从而增加像素灰度值的动态范围，达到增强图像整体对比度的效果。

    face_cascade.detectMultiScale(gray,faces,1.1,4,0|CASCADE_SCALE_IMAGE,Size(90,90));
    if(faces.size()==1){
        Mat faceROI = gray(faces[0]);//提取脸部区域
        Mat myFace;
        cv::resize(faceROI,myFace,Size(92,112));//数据集图片大小
        count++;
        qDebug()<<"-----------------------count="<<count<<endl;
        if(50-count>=0){
            filename = format("/var/c/qt/face_detect/photos/s%d",facefilenum);
            if(access(filename.c_str(),0)!=-1){
                qDebug()<<filename.c_str()<<" is existed"<<endl;
            }else{
                if(mkdir(filename.c_str(),0777)==0){
                    qDebug() << "create " << filename.c_str() << "\n";
                       }
                else{
                    qDebug()<< "fail to create " << filename.c_str() << endl;
                }

            }

            filename = format("/var/c/qt/face_detect/photos/s%d/%d.jpg",facefilenum,count);
            imwrite(filename,myFace);
            temp_count = 50-count;
        }else{
            temp_count = 0;
        }
        ui->temp_label->setText(QString("%1").arg(temp_count));

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
    /*
    cvtColor(frame,frame2,COLOR_BGR2RGB);
    QImage img1((const uchar*)frame2.data,frame2.cols,frame2.rows,frame2.cols*frame2.channels(),QImage::Format_RGB888);
    ui->open_lable->setPixmap(QPixmap::fromImage(img1));
    */

    QImage img1((const uchar*)frame.data,frame.cols,frame.rows,frame.cols*frame.channels(),QImage::Format_RGB888);
    ui->open_lable->setAlignment(Qt::AlignCenter);  //居中显示
    img1.scaled(ui->open_lable->width(),ui->open_lable->height(),Qt::KeepAspectRatio);
    ui->open_lable->setScaledContents(true);
    ui->open_lable->setPixmap(QPixmap::fromImage(img1));


}


int MainWindow::getcsv1()
{
    qDebug()<<"int MainWindow::getcsv1()"<<endl;
    int dirnum = 1;
    remove("/var/c/qt/face_detect/photos/at.txt");
    while(1){
        char const dir_txt[] = ("/var/c/qt/face_detect/photos/at.txt");
        char str[128] = {0};
        char str_temp[] = ("/var/c/qt/face_detect/photos/s");
        sprintf(str,"%s%d",str_temp,dirnum);
        const char*ptr = str;
        if(access(ptr,0))
            break;
        scan_one_dir1(ptr,dirnum,dir_txt);
        dirnum++;
    }
    qDebug()<<"=======int MainWindow::getcsv1()========"<<endl;
    return 0;
}


void MainWindow::scan_one_dir1(const char*dir_name,int dirnum,const char *dir_txt){

    if(dir_name==NULL){
        qDebug()<<"dir_name is null!"<<endl;
        return ;
    }
    struct stat s;
    lstat(dir_name,&s); //读取dir_name下的文件，存储在stat结构体中
    if(!S_ISDIR(s.st_mode)) //判断是否是一个文件
        return;
    struct dirent *filename;
    DIR*dir;
    dir = opendir(dir_name);
    if(dir == NULL)
        return ;

    ofstream outfile;
    outfile.open(dir_txt,ios::app);
    while((filename = readdir(dir))!=NULL){
        if(strcmp(filename->d_name,"..")==0||
            strcmp(filename->d_name,".")==0)
            continue;
        char wholePath[128] = {0};
        sprintf(wholePath,"%s/%s;%d",dir_name,filename->d_name,dirnum);
        outfile<<wholePath<<endl;
    }
    outfile.close();
}

void MainWindow::read_csv1(const string &filename2,vector<Mat>&images,vector<int>&labels,char separator = ';'){
    std::ifstream file(filename2.c_str(),ifstream::in);
    if(!file){
        string error_message = "No valid input file was given, please check the given filename.";
        CV_Error(CV_StsBadArg, error_message);
    }
    string line,path,classlabels;
    while(getline(file,line)){
        stringstream lines(line);   //转换成字符串流
        getline(lines,path,separator);
        getline(lines,classlabels);
        if(!path.empty()&&!classlabels.empty()){
            images.push_back(imread(path,0)); //以灰度图的格式读入
            labels.push_back(atoi(classlabels.c_str()));
        }
    }
}

//训练自己的人脸模型
void MainWindow::facetrain(){
    double start1,start2,start3;
    double end1,end2,end3;
    string fn_csv = "/var/c/qt/face_detect/photos/at.txt";
    vector<Mat>images;
    vector<int>labels;

    try{
        read_csv1(fn_csv,images,labels,';');
    }
    catch(cv::Exception&e){
      //  cerr << "Error opening file \"" << fn_csv << "\". Reason: " << e.msg << endl;
        qDebug()<<"Error opening file "<<fn_csv.c_str()<<endl;
        exit(1);
    }
    //排除最后一张图片，作为测试照片
    Mat testSample = images[images.size()-1];
    int testLabel = labels[labels.size()-1];
    images.pop_back();
    labels.pop_back();

    //训练自己的模型
      start1 = (double)getTickCount();
      Ptr<cv::face::BasicFaceRecognizer> model = cv::face::EigenFaceRecognizer::create();
      model->train(images, labels);
      model->save("/var/c/qt/face_detect/MyFacePCAModel.xml");
      end1 = (double)((getTickCount()-start1)/getTickFrequency());

      start2 = (double)getTickCount();
      Ptr<cv::face::BasicFaceRecognizer> model1 = cv::face::FisherFaceRecognizer::create();
      model1->train(images, labels);
      model1->save("//var/c/qt/face_detect/MyFaceFisherModel.xml");
      end2 = (double)((getTickCount()-start2)/getTickFrequency());

      start3 = (double)getTickCount();
      Ptr<cv::face::LBPHFaceRecognizer> model2 = cv::face::LBPHFaceRecognizer::create();
      model2->train(images, labels);
      model2->save("/var/c/qt/face_detect/MyFaceLBPHModel.xml");
      end3 = (double(getTickCount()-start3)/getTickFrequency());

      //加载分类器
      int predictedLabel = model->predict(testSample);//加载分类器
      int predictedLabel1 = model1->predict(testSample);
      int predictedLabel2 = model2->predict(testSample);

      string result_message = format("Predicted class = %d / Actual class = %d.", predictedLabel, testLabel);
      string result_message1 = format("Predicted class = %d / Actual class = %d.", predictedLabel1, testLabel);
      string result_message2 = format("Predicted class = %d / Actual class = %d.", predictedLabel2, testLabel);
      cout << result_message << endl;
      cout << result_message1 << endl;
      cout << result_message2 << endl;

      qDebug()<<"PAC算法训练所用时间：\n"<<end1<<endl;
      qDebug()<<"LDA算法训练所用时间：\n"<<end2<<endl;
      qDebug()<<"LBP算法训练所用时间：\n"<<end3<<endl;
      //waitKey(0);


}


void MainWindow::drawPolyline(Mat &im, const vector<Point2f> &landmarks, const int start, const int end, bool isClosed){
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

void MainWindow::namein(){
    //remove("/var/c/qt/face_detect/photos/name.txt");
    QString str = ui->comboBox_name->currentText();
    QString str2 = ui->comboBox_id->currentText();
    std::string new_str = str.toStdString();
    std::string new_str2 = str2.toStdString();
    ofstream outfile;
    outfile.open("/var/c/qt/face_detect/photos/name.txt",ios::app);
    outfile<<new_str<<" "<<new_str2<<endl;

    outfile.close();
}


void MainWindow::drawLandmarks(Mat &im, vector<Point2f> &landmarks)
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





void MainWindow::on_rec_button_clicked()
{
    this->close();
    recognize *rec = new recognize();
    rec->show();
}


