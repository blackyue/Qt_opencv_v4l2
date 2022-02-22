#-------------------------------------------------
#
# Project created by QtCreator 2020-07-15T15:03:29
#
#-------------------------------------------------

QT       += core gui
QT       += core gui sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = facial
TEMPLATE = app


SOURCES += main.cpp\
        facial.cpp \
    register1.cpp \
    login_main.cpp \
    elabel.cpp \
    per_data.cpp \
    manager.cpp \
    mylabel.cpp \
    softkeys.cpp

HEADERS  += facial.h \
    register1.h \
    login_main.h \
    elabel.h \
    per_data.h \
    manager.h \
    mylabel.h \
    softkeys.h

FORMS    += facial.ui \
    prompt.ui \
    prompt_2.ui \
    prompt_3.ui \
    register1.ui \
    login_main.ui \
    per_data.ui \
    manager.ui

RESOURCES += \
    image.qrc
