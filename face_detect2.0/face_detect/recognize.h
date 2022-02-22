#ifndef RECOGNIZE_H
#define RECOGNIZE_H

#include <QMainWindow>

#include <sstream>
#include <fstream>
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

#include "fv4l2.h"

#define COLOR Scalar(255, 200,0)

using namespace std;
using namespace cv;

namespace Ui {
class recognize;
}

class recognize : public QMainWindow
{
    Q_OBJECT

public:
    explicit recognize(QWidget *parent = 0);
    ~recognize();

private:
    Ui::recognize *ui;
    
    QTimer *mtimer;
    //QTimer *timer;
    QImage image;
    VideoCapture cap;
    Mat frame;
    CascadeClassifier face_cascade;
    Ptr<face::Facemark> facemark;
    //创建Facemark对象，Facemark是使用智能指针（smart pointer，PTR），所以不需要考虑内存泄漏问题。
    
    fv4l2 camera;
    
private slots:
    void timeupdate1();
    void timeupdate2();

    
    void readFrame();       //读取当前帧信息
    void drawPolyline(Mat &im,const vector<Point2f>&landmarks,const int start,const int end,bool isClosed = false);
    void drawLandmarks(Mat &im,vector<Point2f>&landmarks);
    void on_closebt_clicked();
};

#endif // RECOGNIZE_H
