/********************************************************************************
** Form generated from reading UI file 'prompt.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROMPT_H
#define UI_PROMPT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_prompt
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *hm_label2;
    QLabel *yd_label2;
    QLabel *name_label;
    QLabel *time_label;
    QLabel *tem_label;

    void setupUi(QMainWindow *prompt)
    {
        if (prompt->objectName().isEmpty())
            prompt->setObjectName(QStringLiteral("prompt"));
        prompt->resize(1024, 600);
        centralwidget = new QWidget(prompt);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 1024, 600));
        label->setStyleSheet(QLatin1String("background-color: rgb(204, 43, 43);\n"
"image: url(:/new/prefix1/image/menu2.jpg);"));
        hm_label2 = new QLabel(centralwidget);
        hm_label2->setObjectName(QStringLiteral("hm_label2"));
        hm_label2->setGeometry(QRect(730, 70, 221, 61));
        QFont font;
        font.setPointSize(42);
        hm_label2->setFont(font);
        yd_label2 = new QLabel(centralwidget);
        yd_label2->setObjectName(QStringLiteral("yd_label2"));
        yd_label2->setGeometry(QRect(760, 120, 161, 71));
        QFont font1;
        font1.setPointSize(15);
        yd_label2->setFont(font1);
        name_label = new QLabel(centralwidget);
        name_label->setObjectName(QStringLiteral("name_label"));
        name_label->setGeometry(QRect(860, 210, 121, 41));
        QFont font2;
        font2.setPointSize(20);
        name_label->setFont(font2);
        name_label->setStyleSheet(QStringLiteral(""));
        time_label = new QLabel(centralwidget);
        time_label->setObjectName(QStringLiteral("time_label"));
        time_label->setGeometry(QRect(860, 290, 121, 31));
        time_label->setFont(font2);
        time_label->setStyleSheet(QStringLiteral(""));
        tem_label = new QLabel(centralwidget);
        tem_label->setObjectName(QStringLiteral("tem_label"));
        tem_label->setGeometry(QRect(860, 350, 121, 51));
        tem_label->setFont(font2);
        tem_label->setStyleSheet(QStringLiteral(""));
        prompt->setCentralWidget(centralwidget);

        retranslateUi(prompt);

        QMetaObject::connectSlotsByName(prompt);
    } // setupUi

    void retranslateUi(QMainWindow *prompt)
    {
        prompt->setWindowTitle(QApplication::translate("prompt", "MainWindow", 0));
        label->setText(QString());
        hm_label2->setText(QString());
        yd_label2->setText(QString());
        name_label->setText(QString());
        time_label->setText(QString());
        tem_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class prompt: public Ui_prompt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROMPT_H
