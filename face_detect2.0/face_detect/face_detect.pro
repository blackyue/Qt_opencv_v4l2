#-------------------------------------------------
#
# Project created by QtCreator 2021-11-16T16:00:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = face_detect
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#LIBS += /opt/wkspace/opencv/opencv-3.4.1/build/lib/libopencv_videoio.so
#LIBS += /opt/wkspace/opencv/opencv-3.4.1/build/lib/libopencv_shape.so
#LIBS += /opt/wkspace/opencv/opencv-3.4.1/build/lib/libopencv_imgcodecs.so
#LIBS += /opt/wkspace/opencv/opencv-3.4.1/build/lib/libopencv_imgproc.so.3.4

LIBS += /opt/wkspace/opencv/opencv-3.4.1/build/lib/lib*

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    recognize.cpp \
    fv4l2.cpp

HEADERS += \
        mainwindow.h \
    recognize.h \
    fv4l2.h

FORMS += \
        mainwindow.ui \
    recognize.ui

RESOURCES += \
    image.qrc

#INCLUDEPATH += /usr/share/ewaybot/include/Eigen \
#              /usr/share/ewaybot/include/Eigen/Eigen \
#                /usr/share/ewaybot/include/Eigen/include/Eigen \
#                /usr/share/ewaybot/include/Eigen/include/Eigen/Eigen \
#                /usr/share/ewaybot/include/Eigen/include/unsupported/Eigen



