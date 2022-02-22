/********************************************************************************
** Form generated from reading UI file 'prompt_2.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROMPT_2_H
#define UI_PROMPT_2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_prompt_2
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *hm_label3;
    QLabel *yd_label3;
    QLabel *name_label;
    QLabel *time_label;
    QLabel *tem_label;

    void setupUi(QMainWindow *prompt_2)
    {
        if (prompt_2->objectName().isEmpty())
            prompt_2->setObjectName(QStringLiteral("prompt_2"));
        prompt_2->resize(1024, 600);
        centralwidget = new QWidget(prompt_2);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 1024, 600));
        label->setStyleSheet(QLatin1String("background-color: rgb(239, 54, 54);\n"
"image: url(:/new/prefix1/image/menu3.jpg);"));
        hm_label3 = new QLabel(centralwidget);
        hm_label3->setObjectName(QStringLiteral("hm_label3"));
        hm_label3->setGeometry(QRect(730, 80, 221, 51));
        QFont font;
        font.setPointSize(42);
        hm_label3->setFont(font);
        yd_label3 = new QLabel(centralwidget);
        yd_label3->setObjectName(QStringLiteral("yd_label3"));
        yd_label3->setGeometry(QRect(760, 120, 161, 71));
        QFont font1;
        font1.setPointSize(15);
        yd_label3->setFont(font1);
        name_label = new QLabel(centralwidget);
        name_label->setObjectName(QStringLiteral("name_label"));
        name_label->setGeometry(QRect(860, 210, 121, 41));
        QFont font2;
        font2.setPointSize(20);
        name_label->setFont(font2);
        name_label->setStyleSheet(QStringLiteral(""));
        time_label = new QLabel(centralwidget);
        time_label->setObjectName(QStringLiteral("time_label"));
        time_label->setGeometry(QRect(860, 280, 121, 51));
        time_label->setFont(font2);
        time_label->setStyleSheet(QStringLiteral(""));
        tem_label = new QLabel(centralwidget);
        tem_label->setObjectName(QStringLiteral("tem_label"));
        tem_label->setGeometry(QRect(860, 350, 121, 51));
        tem_label->setFont(font2);
        tem_label->setStyleSheet(QStringLiteral(""));
        prompt_2->setCentralWidget(centralwidget);

        retranslateUi(prompt_2);

        QMetaObject::connectSlotsByName(prompt_2);
    } // setupUi

    void retranslateUi(QMainWindow *prompt_2)
    {
        prompt_2->setWindowTitle(QApplication::translate("prompt_2", "MainWindow", 0));
        label->setText(QString());
        hm_label3->setText(QString());
        yd_label3->setText(QString());
        name_label->setText(QString());
        time_label->setText(QString());
        tem_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class prompt_2: public Ui_prompt_2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROMPT_2_H
