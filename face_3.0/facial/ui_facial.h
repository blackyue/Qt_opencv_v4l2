/********************************************************************************
** Form generated from reading UI file 'facial.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FACIAL_H
#define UI_FACIAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "elabel.h"

QT_BEGIN_NAMESPACE

class Ui_facial
{
public:
    QWidget *centralWidget;
    ELabel *main_label;
    QLabel *hm_label;
    QLabel *yd_label;
    QPushButton *text_button1;
    QPushButton *text_button2;
    QPushButton *text_button3;
    QPushButton *pass_button;
    QLabel *name_label;
    QLabel *time_label;
    QLabel *label;
    QLabel *tem_label;
    QLabel *face_lb;

    void setupUi(QMainWindow *facial)
    {
        if (facial->objectName().isEmpty())
            facial->setObjectName(QStringLiteral("facial"));
        facial->resize(1024, 600);
        centralWidget = new QWidget(facial);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        main_label = new ELabel(centralWidget);
        main_label->setObjectName(QStringLiteral("main_label"));
        main_label->setGeometry(QRect(0, 0, 1024, 600));
        main_label->setStyleSheet(QLatin1String("background-color: rgb(254, 117, 117);\n"
"background-image: url(:/new/prefix1/image/menu5.jpg);"));
        hm_label = new QLabel(centralWidget);
        hm_label->setObjectName(QStringLiteral("hm_label"));
        hm_label->setGeometry(QRect(720, 70, 251, 61));
        QFont font;
        font.setPointSize(42);
        hm_label->setFont(font);
        yd_label = new QLabel(centralWidget);
        yd_label->setObjectName(QStringLiteral("yd_label"));
        yd_label->setGeometry(QRect(760, 130, 161, 71));
        QFont font1;
        font1.setPointSize(15);
        yd_label->setFont(font1);
        text_button1 = new QPushButton(centralWidget);
        text_button1->setObjectName(QStringLiteral("text_button1"));
        text_button1->setGeometry(QRect(30, 560, 31, 27));
        text_button2 = new QPushButton(centralWidget);
        text_button2->setObjectName(QStringLiteral("text_button2"));
        text_button2->setGeometry(QRect(70, 560, 31, 27));
        text_button3 = new QPushButton(centralWidget);
        text_button3->setObjectName(QStringLiteral("text_button3"));
        text_button3->setGeometry(QRect(120, 560, 31, 27));
        pass_button = new QPushButton(centralWidget);
        pass_button->setObjectName(QStringLiteral("pass_button"));
        pass_button->setGeometry(QRect(170, 560, 31, 27));
        name_label = new QLabel(centralWidget);
        name_label->setObjectName(QStringLiteral("name_label"));
        name_label->setGeometry(QRect(860, 310, 121, 41));
        QFont font2;
        font2.setPointSize(20);
        name_label->setFont(font2);
        name_label->setStyleSheet(QStringLiteral(""));
        time_label = new QLabel(centralWidget);
        time_label->setObjectName(QStringLiteral("time_label"));
        time_label->setGeometry(QRect(858, 290, 121, 31));
        time_label->setFont(font2);
        time_label->setStyleSheet(QStringLiteral(""));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(910, 390, 121, 41));
        QFont font3;
        font3.setPointSize(22);
        label->setFont(font3);
        label->setStyleSheet(QStringLiteral(""));
        tem_label = new QLabel(centralWidget);
        tem_label->setObjectName(QStringLiteral("tem_label"));
        tem_label->setGeometry(QRect(860, 350, 121, 51));
        tem_label->setFont(font2);
        tem_label->setStyleSheet(QStringLiteral(""));
        face_lb = new QLabel(centralWidget);
        face_lb->setObjectName(QStringLiteral("face_lb"));
        face_lb->setGeometry(QRect(90, 130, 530, 360));
        face_lb->setStyleSheet(QStringLiteral("background-color: rgb(189, 189, 189);"));
        facial->setCentralWidget(centralWidget);

        retranslateUi(facial);

        QMetaObject::connectSlotsByName(facial);
    } // setupUi

    void retranslateUi(QMainWindow *facial)
    {
        facial->setWindowTitle(QApplication::translate("facial", "facial", 0));
        main_label->setText(QString());
        hm_label->setText(QApplication::translate("facial", "<html><head/><body><p><span style=\" color:#ffffff;\"><br/></span></p></body></html>", 0));
        yd_label->setText(QString());
        text_button1->setText(QString());
        text_button2->setText(QString());
        text_button3->setText(QString());
        pass_button->setText(QString());
        name_label->setText(QString());
        time_label->setText(QString());
        label->setText(QString());
        tem_label->setText(QString());
        face_lb->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class facial: public Ui_facial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FACIAL_H
