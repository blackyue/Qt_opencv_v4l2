#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


/*
#include <sstream>
#include <fstream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/dnn/dnn.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/face.hpp>
#include <opencv2/face/facerec.hpp>
#include <opencv2/imgproc/types_c.h>
*/


#include <opencv2/face.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <QDebug>
#include <vector>
#include <QImage>
#include <QTime>
#include <QTimer>
#include <dirent.h>
#include <stddef.h>
#include <stdio.h>
#include <cstdlib>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "recognize.h"
#include "fv4l2.h"
#define COLOR Scalar(255, 200,0)

using namespace std;
using namespace cv;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:


    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    static int getcount(){return count;}
    static int gettemp_count(){return temp_count;}

private:
    int facefilenum;      //文件个数
    static int count;

    fv4l2 camera;
    static int temp_count; //还需要拍摄的张数
    Ui::MainWindow *ui;
    QTimer *timer;
    QImage image;
    VideoCapture cap;
    Mat frame;
    CascadeClassifier face_cascade;
    Ptr<face::Facemark> facemark;
    //创建Facemark对象，Facemark是使用智能指针（smart pointer，PTR），所以不需要考虑内存泄漏问题。
    int get_file_count(char *root);
    int getcsv1();
    void scan_one_dir1(const char *dir_name,int dirnum,const char*dir_txt);
    void namein();
    void facetrain();
    void read_csv1(const string&filename,vector<Mat>&images,vector<int>&lables,char separator);

private slots:
    void timerupdate();
    void timerupdate2();
    void readFrame();       //读取当前帧信息
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void drawPolyline(Mat &im,const vector<Point2f>&landmarks,const int start,const int end,bool isClosed = false);
    void drawLandmarks(Mat &im,vector<Point2f>&landmarks);
    void on_pushButton_3_clicked();
    void on_rec_button_clicked();
    void on_pushButton_4_clicked();
};

#endif // MAINWINDOW_H
