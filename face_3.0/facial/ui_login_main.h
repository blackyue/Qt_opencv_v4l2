/********************************************************************************
** Form generated from reading UI file 'login_main.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_MAIN_H
#define UI_LOGIN_MAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login_main
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *hm_label;
    QLabel *yd_label;
    QPushButton *num2_button;
    QPushButton *num3_button;
    QPushButton *num1_button_4;
    QPushButton *num0_button;
    QPushButton *delete_button;
    QPushButton *clear_button;
    QPushButton *num1_button;
    QLineEdit *pwd_le;
    QPushButton *enter_button;
    QPushButton *return_button_3;
    QPushButton *num4_button;
    QPushButton *num5_button;
    QPushButton *num6_button;
    QPushButton *num7_button;
    QPushButton *num8_button;
    QPushButton *num9_button;

    void setupUi(QMainWindow *login_main)
    {
        if (login_main->objectName().isEmpty())
            login_main->setObjectName(QStringLiteral("login_main"));
        login_main->resize(1024, 600);
        centralwidget = new QWidget(login_main);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 1024, 600));
        label->setStyleSheet(QLatin1String("background-color: rgb(248, 49, 49);\n"
"image: url(:/new/prefix1/image/menu7.jpg);"));
        hm_label = new QLabel(centralwidget);
        hm_label->setObjectName(QStringLiteral("hm_label"));
        hm_label->setGeometry(QRect(730, 60, 231, 81));
        QFont font;
        font.setPointSize(42);
        hm_label->setFont(font);
        yd_label = new QLabel(centralwidget);
        yd_label->setObjectName(QStringLiteral("yd_label"));
        yd_label->setGeometry(QRect(760, 120, 161, 69));
        QFont font1;
        font1.setPointSize(15);
        yd_label->setFont(font1);
        num2_button = new QPushButton(centralwidget);
        num2_button->setObjectName(QStringLiteral("num2_button"));
        num2_button->setGeometry(QRect(310, 260, 81, 51));
        num2_button->setStyleSheet(QStringLiteral("background-color: rgb(236, 65, 65);"));
        num2_button->setFlat(true);
        num3_button = new QPushButton(centralwidget);
        num3_button->setObjectName(QStringLiteral("num3_button"));
        num3_button->setGeometry(QRect(420, 260, 81, 51));
        num3_button->setStyleSheet(QStringLiteral("background-color: rgb(236, 65, 65);"));
        num3_button->setFlat(true);
        num1_button_4 = new QPushButton(centralwidget);
        num1_button_4->setObjectName(QStringLiteral("num1_button_4"));
        num1_button_4->setGeometry(QRect(740, 550, 81, 51));
        num1_button_4->setStyleSheet(QStringLiteral("background-color: rgb(236, 65, 65);"));
        num1_button_4->setFlat(true);
        num0_button = new QPushButton(centralwidget);
        num0_button->setObjectName(QStringLiteral("num0_button"));
        num0_button->setGeometry(QRect(310, 450, 81, 51));
        num0_button->setStyleSheet(QStringLiteral("background-color: rgb(236, 65, 65);"));
        num0_button->setFlat(true);
        delete_button = new QPushButton(centralwidget);
        delete_button->setObjectName(QStringLiteral("delete_button"));
        delete_button->setGeometry(QRect(420, 450, 81, 51));
        delete_button->setStyleSheet(QStringLiteral("background-color: rgb(236, 65, 65);"));
        delete_button->setFlat(true);
        clear_button = new QPushButton(centralwidget);
        clear_button->setObjectName(QStringLiteral("clear_button"));
        clear_button->setGeometry(QRect(210, 450, 81, 51));
        clear_button->setStyleSheet(QStringLiteral("background-color: rgb(236, 65, 65);"));
        clear_button->setFlat(true);
        num1_button = new QPushButton(centralwidget);
        num1_button->setObjectName(QStringLiteral("num1_button"));
        num1_button->setGeometry(QRect(200, 260, 81, 51));
        num1_button->setStyleSheet(QStringLiteral("background-color: rgb(236, 65, 65);"));
        num1_button->setFlat(true);
        pwd_le = new QLineEdit(centralwidget);
        pwd_le->setObjectName(QStringLiteral("pwd_le"));
        pwd_le->setGeometry(QRect(190, 200, 331, 41));
        QFont font2;
        font2.setPointSize(20);
        pwd_le->setFont(font2);
        pwd_le->setFocusPolicy(Qt::StrongFocus);
        enter_button = new QPushButton(centralwidget);
        enter_button->setObjectName(QStringLiteral("enter_button"));
        enter_button->setGeometry(QRect(250, 530, 211, 41));
        enter_button->setFlat(true);
        return_button_3 = new QPushButton(centralwidget);
        return_button_3->setObjectName(QStringLiteral("return_button_3"));
        return_button_3->setGeometry(QRect(950, 20, 51, 41));
        return_button_3->setFlat(true);
        num4_button = new QPushButton(centralwidget);
        num4_button->setObjectName(QStringLiteral("num4_button"));
        num4_button->setGeometry(QRect(200, 320, 81, 51));
        num4_button->setStyleSheet(QStringLiteral("background-color: rgb(236, 65, 65);"));
        num4_button->setFlat(true);
        num5_button = new QPushButton(centralwidget);
        num5_button->setObjectName(QStringLiteral("num5_button"));
        num5_button->setGeometry(QRect(310, 320, 81, 51));
        num5_button->setStyleSheet(QStringLiteral("background-color: rgb(236, 65, 65);"));
        num5_button->setFlat(true);
        num6_button = new QPushButton(centralwidget);
        num6_button->setObjectName(QStringLiteral("num6_button"));
        num6_button->setGeometry(QRect(420, 320, 81, 51));
        num6_button->setStyleSheet(QStringLiteral("background-color: rgb(236, 65, 65);"));
        num6_button->setFlat(true);
        num7_button = new QPushButton(centralwidget);
        num7_button->setObjectName(QStringLiteral("num7_button"));
        num7_button->setGeometry(QRect(210, 380, 81, 51));
        num7_button->setStyleSheet(QStringLiteral("background-color: rgb(236, 65, 65);"));
        num7_button->setFlat(true);
        num8_button = new QPushButton(centralwidget);
        num8_button->setObjectName(QStringLiteral("num8_button"));
        num8_button->setGeometry(QRect(310, 380, 81, 51));
        num8_button->setStyleSheet(QStringLiteral("background-color: rgb(236, 65, 65);"));
        num8_button->setFlat(true);
        num9_button = new QPushButton(centralwidget);
        num9_button->setObjectName(QStringLiteral("num9_button"));
        num9_button->setGeometry(QRect(420, 390, 81, 51));
        num9_button->setStyleSheet(QStringLiteral("background-color: rgb(236, 65, 65);"));
        num9_button->setFlat(true);
        login_main->setCentralWidget(centralwidget);

        retranslateUi(login_main);

        QMetaObject::connectSlotsByName(login_main);
    } // setupUi

    void retranslateUi(QMainWindow *login_main)
    {
        login_main->setWindowTitle(QApplication::translate("login_main", "MainWindow", 0));
        label->setText(QString());
        hm_label->setText(QString());
        yd_label->setText(QString());
        num2_button->setText(QString());
        num3_button->setText(QString());
        num1_button_4->setText(QString());
        num0_button->setText(QString());
        delete_button->setText(QString());
        clear_button->setText(QString());
        num1_button->setText(QString());
        pwd_le->setText(QString());
        enter_button->setText(QString());
        return_button_3->setText(QString());
        num4_button->setText(QString());
        num5_button->setText(QString());
        num6_button->setText(QString());
        num7_button->setText(QString());
        num8_button->setText(QString());
        num9_button->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class login_main: public Ui_login_main {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_MAIN_H
