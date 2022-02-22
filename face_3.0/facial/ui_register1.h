/********************************************************************************
** Form generated from reading UI file 'register1.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER1_H
#define UI_REGISTER1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include <mylabel.h>
#include <softkeys.h>

QT_BEGIN_NAMESPACE

class Ui_register1
{
public:
    QWidget *centralwidget;
    mylabel *backgroundlabel;
    QLabel *hm_label;
    QLabel *yd_label;
    QTabWidget *tabWidget;
    QWidget *tab;
    mylabel *label_2;
    QComboBox *comboBox_2;
    QPushButton *boy_button_1;
    QPushButton *girl_button_1;
    QPushButton *employee_check;
    QPushButton *cancel_bt_2;
    QLabel *label_4;
    QLineEdit *id_lineEdit;
    QLineEdit *name_lineEdit;
    QWidget *tab_2;
    mylabel *label_3;
    QComboBox *comboBox_3;
    QComboBox *comboBox_4;
    QPushButton *boy_button_2;
    QPushButton *girl_button_2;
    QPushButton *visit_check;
    QPushButton *cancel_bt;
    QWidget *myWidget;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    softkeys *toolButton_42;
    softkeys *toolButton_43;
    softkeys *toolButton_44;
    softkeys *toolButton_45;
    softkeys *toolButton_46;
    softkeys *toolButton_47;
    softkeys *toolButton_48;
    softkeys *toolButton_49;
    softkeys *toolButton_50;
    softkeys *toolButton_51;
    softkeys *toolButton_52;
    softkeys *toolButton_53;
    softkeys *toolButton_54;
    softkeys *toolButton_55;
    softkeys *toolButton_56;
    softkeys *toolButton_57;
    softkeys *toolButton_58;
    softkeys *toolButton_59;
    softkeys *toolButton_60;
    softkeys *toolButton_61;
    softkeys *toolButton_62;
    softkeys *toolButton_63;
    softkeys *toolButton_64;
    softkeys *toolButton_65;
    softkeys *toolButton_66;
    softkeys *toolButton_67;
    softkeys *toolButton_68;
    softkeys *toolButton_69;
    softkeys *toolButton_70;
    softkeys *toolButton_71;
    softkeys *toolButton_72;
    softkeys *toolButton_73;
    softkeys *toolButton_74;
    softkeys *toolButton_75;
    softkeys *toolButton_76;
    softkeys *toolButton_77;
    softkeys *toolButton_78;
    softkeys *toolButton_79;
    softkeys *toolButton_80;
    softkeys *toolButton_81;

    void setupUi(QMainWindow *register1)
    {
        if (register1->objectName().isEmpty())
            register1->setObjectName(QStringLiteral("register1"));
        register1->resize(1024, 600);
        centralwidget = new QWidget(register1);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        backgroundlabel = new mylabel(centralwidget);
        backgroundlabel->setObjectName(QStringLiteral("backgroundlabel"));
        backgroundlabel->setGeometry(QRect(0, 0, 1024, 600));
        backgroundlabel->setStyleSheet(QLatin1String("background-color: rgb(237, 26, 26);\n"
"image: url(:/new/prefix1/image/menu5.jpg);"));
        hm_label = new QLabel(centralwidget);
        hm_label->setObjectName(QStringLiteral("hm_label"));
        hm_label->setGeometry(QRect(730, 80, 221, 51));
        QFont font;
        font.setPointSize(42);
        hm_label->setFont(font);
        yd_label = new QLabel(centralwidget);
        yd_label->setObjectName(QStringLiteral("yd_label"));
        yd_label->setGeometry(QRect(760, 120, 161, 71));
        QFont font1;
        font1.setPointSize(15);
        yd_label->setFont(font1);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 100, 691, 470));
        QFont font2;
        font2.setPointSize(18);
        tabWidget->setFont(font2);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label_2 = new mylabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 0, 691, 451));
        label_2->setStyleSheet(QLatin1String("background-color: rgb(244, 73, 73);\n"
"image: url(:/new/prefix1/image/menu51.jpg);"));
        comboBox_2 = new QComboBox(tab);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(440, 180, 171, 38));
        boy_button_1 = new QPushButton(tab);
        boy_button_1->setObjectName(QStringLiteral("boy_button_1"));
        boy_button_1->setGeometry(QRect(460, 310, 31, 33));
        boy_button_1->setStyleSheet(QStringLiteral("background-color: rgb(99, 112, 241);"));
        boy_button_1->setFlat(true);
        girl_button_1 = new QPushButton(tab);
        girl_button_1->setObjectName(QStringLiteral("girl_button_1"));
        girl_button_1->setGeometry(QRect(553, 310, 31, 33));
        girl_button_1->setStyleSheet(QStringLiteral("background-color: rgb(99, 112, 241);"));
        girl_button_1->setFlat(true);
        employee_check = new QPushButton(tab);
        employee_check->setObjectName(QStringLiteral("employee_check"));
        employee_check->setGeometry(QRect(530, 370, 101, 41));
        employee_check->setFlat(true);
        cancel_bt_2 = new QPushButton(tab);
        cancel_bt_2->setObjectName(QStringLiteral("cancel_bt_2"));
        cancel_bt_2->setGeometry(QRect(380, 370, 101, 41));
        cancel_bt_2->setFlat(true);
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(375, 120, 91, 41));
        QFont font3;
        font3.setPointSize(13);
        label_4->setFont(font3);
        id_lineEdit = new QLineEdit(tab);
        id_lineEdit->setObjectName(QStringLiteral("id_lineEdit"));
        id_lineEdit->setGeometry(QRect(440, 60, 171, 38));
        name_lineEdit = new QLineEdit(tab);
        name_lineEdit->setObjectName(QStringLiteral("name_lineEdit"));
        name_lineEdit->setGeometry(QRect(440, 120, 171, 38));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label_3 = new mylabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 0, 691, 451));
        label_3->setStyleSheet(QLatin1String("background-color: rgb(211, 90, 90);\n"
"image: url(:/new/prefix1/image/menu52.jpg);"));
        comboBox_3 = new QComboBox(tab_2);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setGeometry(QRect(480, 80, 171, 38));
        comboBox_4 = new QComboBox(tab_2);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));
        comboBox_4->setGeometry(QRect(480, 190, 171, 38));
        boy_button_2 = new QPushButton(tab_2);
        boy_button_2->setObjectName(QStringLiteral("boy_button_2"));
        boy_button_2->setGeometry(QRect(460, 310, 31, 33));
        boy_button_2->setStyleSheet(QStringLiteral("background-color: rgb(99, 112, 241);"));
        boy_button_2->setFlat(true);
        girl_button_2 = new QPushButton(tab_2);
        girl_button_2->setObjectName(QStringLiteral("girl_button_2"));
        girl_button_2->setGeometry(QRect(555, 310, 31, 33));
        girl_button_2->setStyleSheet(QStringLiteral("background-color: rgb(99, 112, 241);"));
        girl_button_2->setFlat(true);
        visit_check = new QPushButton(tab_2);
        visit_check->setObjectName(QStringLiteral("visit_check"));
        visit_check->setGeometry(QRect(530, 370, 101, 41));
        visit_check->setFlat(true);
        cancel_bt = new QPushButton(tab_2);
        cancel_bt->setObjectName(QStringLiteral("cancel_bt"));
        cancel_bt->setGeometry(QRect(380, 370, 101, 41));
        cancel_bt->setFlat(true);
        tabWidget->addTab(tab_2, QString());
        myWidget = new QWidget(centralwidget);
        myWidget->setObjectName(QStringLiteral("myWidget"));
        myWidget->setGeometry(QRect(70, 340, 611, 271));
        gridLayoutWidget_2 = new QWidget(myWidget);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(30, 30, 561, 231));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(1);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        toolButton_42 = new softkeys(gridLayoutWidget_2);
        toolButton_42->setObjectName(QStringLiteral("toolButton_42"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolButton_42->sizePolicy().hasHeightForWidth());
        toolButton_42->setSizePolicy(sizePolicy);
        QFont font4;
        font4.setPointSize(17);
        toolButton_42->setFont(font4);

        gridLayout_2->addWidget(toolButton_42, 3, 0, 1, 1);

        toolButton_43 = new softkeys(gridLayoutWidget_2);
        toolButton_43->setObjectName(QStringLiteral("toolButton_43"));
        sizePolicy.setHeightForWidth(toolButton_43->sizePolicy().hasHeightForWidth());
        toolButton_43->setSizePolicy(sizePolicy);
        toolButton_43->setFont(font4);

        gridLayout_2->addWidget(toolButton_43, 0, 3, 1, 1);

        toolButton_44 = new softkeys(gridLayoutWidget_2);
        toolButton_44->setObjectName(QStringLiteral("toolButton_44"));
        sizePolicy.setHeightForWidth(toolButton_44->sizePolicy().hasHeightForWidth());
        toolButton_44->setSizePolicy(sizePolicy);
        toolButton_44->setFont(font4);

        gridLayout_2->addWidget(toolButton_44, 3, 3, 1, 1);

        toolButton_45 = new softkeys(gridLayoutWidget_2);
        toolButton_45->setObjectName(QStringLiteral("toolButton_45"));
        sizePolicy.setHeightForWidth(toolButton_45->sizePolicy().hasHeightForWidth());
        toolButton_45->setSizePolicy(sizePolicy);
        toolButton_45->setFont(font4);

        gridLayout_2->addWidget(toolButton_45, 1, 6, 1, 1);

        toolButton_46 = new softkeys(gridLayoutWidget_2);
        toolButton_46->setObjectName(QStringLiteral("toolButton_46"));
        sizePolicy.setHeightForWidth(toolButton_46->sizePolicy().hasHeightForWidth());
        toolButton_46->setSizePolicy(sizePolicy);
        toolButton_46->setFont(font4);

        gridLayout_2->addWidget(toolButton_46, 2, 1, 1, 1);

        toolButton_47 = new softkeys(gridLayoutWidget_2);
        toolButton_47->setObjectName(QStringLiteral("toolButton_47"));
        sizePolicy.setHeightForWidth(toolButton_47->sizePolicy().hasHeightForWidth());
        toolButton_47->setSizePolicy(sizePolicy);
        toolButton_47->setFont(font4);

        gridLayout_2->addWidget(toolButton_47, 0, 7, 1, 1);

        toolButton_48 = new softkeys(gridLayoutWidget_2);
        toolButton_48->setObjectName(QStringLiteral("toolButton_48"));
        sizePolicy.setHeightForWidth(toolButton_48->sizePolicy().hasHeightForWidth());
        toolButton_48->setSizePolicy(sizePolicy);
        toolButton_48->setFont(font4);

        gridLayout_2->addWidget(toolButton_48, 1, 8, 1, 1);

        toolButton_49 = new softkeys(gridLayoutWidget_2);
        toolButton_49->setObjectName(QStringLiteral("toolButton_49"));
        sizePolicy.setHeightForWidth(toolButton_49->sizePolicy().hasHeightForWidth());
        toolButton_49->setSizePolicy(sizePolicy);
        toolButton_49->setFont(font4);

        gridLayout_2->addWidget(toolButton_49, 1, 9, 1, 1);

        toolButton_50 = new softkeys(gridLayoutWidget_2);
        toolButton_50->setObjectName(QStringLiteral("toolButton_50"));
        sizePolicy.setHeightForWidth(toolButton_50->sizePolicy().hasHeightForWidth());
        toolButton_50->setSizePolicy(sizePolicy);
        toolButton_50->setFont(font4);

        gridLayout_2->addWidget(toolButton_50, 2, 5, 1, 1);

        toolButton_51 = new softkeys(gridLayoutWidget_2);
        toolButton_51->setObjectName(QStringLiteral("toolButton_51"));
        sizePolicy.setHeightForWidth(toolButton_51->sizePolicy().hasHeightForWidth());
        toolButton_51->setSizePolicy(sizePolicy);
        toolButton_51->setFont(font4);

        gridLayout_2->addWidget(toolButton_51, 3, 7, 1, 1);

        toolButton_52 = new softkeys(gridLayoutWidget_2);
        toolButton_52->setObjectName(QStringLiteral("toolButton_52"));
        sizePolicy.setHeightForWidth(toolButton_52->sizePolicy().hasHeightForWidth());
        toolButton_52->setSizePolicy(sizePolicy);
        toolButton_52->setFont(font4);

        gridLayout_2->addWidget(toolButton_52, 1, 0, 1, 1);

        toolButton_53 = new softkeys(gridLayoutWidget_2);
        toolButton_53->setObjectName(QStringLiteral("toolButton_53"));
        sizePolicy.setHeightForWidth(toolButton_53->sizePolicy().hasHeightForWidth());
        toolButton_53->setSizePolicy(sizePolicy);
        toolButton_53->setFont(font4);

        gridLayout_2->addWidget(toolButton_53, 0, 5, 1, 1);

        toolButton_54 = new softkeys(gridLayoutWidget_2);
        toolButton_54->setObjectName(QStringLiteral("toolButton_54"));
        sizePolicy.setHeightForWidth(toolButton_54->sizePolicy().hasHeightForWidth());
        toolButton_54->setSizePolicy(sizePolicy);
        toolButton_54->setFont(font4);

        gridLayout_2->addWidget(toolButton_54, 1, 3, 1, 1);

        toolButton_55 = new softkeys(gridLayoutWidget_2);
        toolButton_55->setObjectName(QStringLiteral("toolButton_55"));
        sizePolicy.setHeightForWidth(toolButton_55->sizePolicy().hasHeightForWidth());
        toolButton_55->setSizePolicy(sizePolicy);
        toolButton_55->setFont(font4);

        gridLayout_2->addWidget(toolButton_55, 1, 2, 1, 1);

        toolButton_56 = new softkeys(gridLayoutWidget_2);
        toolButton_56->setObjectName(QStringLiteral("toolButton_56"));
        sizePolicy.setHeightForWidth(toolButton_56->sizePolicy().hasHeightForWidth());
        toolButton_56->setSizePolicy(sizePolicy);
        toolButton_56->setFont(font4);

        gridLayout_2->addWidget(toolButton_56, 0, 8, 1, 1);

        toolButton_57 = new softkeys(gridLayoutWidget_2);
        toolButton_57->setObjectName(QStringLiteral("toolButton_57"));
        sizePolicy.setHeightForWidth(toolButton_57->sizePolicy().hasHeightForWidth());
        toolButton_57->setSizePolicy(sizePolicy);
        toolButton_57->setFont(font4);

        gridLayout_2->addWidget(toolButton_57, 0, 6, 1, 1);

        toolButton_58 = new softkeys(gridLayoutWidget_2);
        toolButton_58->setObjectName(QStringLiteral("toolButton_58"));
        sizePolicy.setHeightForWidth(toolButton_58->sizePolicy().hasHeightForWidth());
        toolButton_58->setSizePolicy(sizePolicy);
        toolButton_58->setFont(font4);

        gridLayout_2->addWidget(toolButton_58, 3, 1, 1, 1);

        toolButton_59 = new softkeys(gridLayoutWidget_2);
        toolButton_59->setObjectName(QStringLiteral("toolButton_59"));
        sizePolicy.setHeightForWidth(toolButton_59->sizePolicy().hasHeightForWidth());
        toolButton_59->setSizePolicy(sizePolicy);
        toolButton_59->setFont(font4);

        gridLayout_2->addWidget(toolButton_59, 2, 4, 1, 1);

        toolButton_60 = new softkeys(gridLayoutWidget_2);
        toolButton_60->setObjectName(QStringLiteral("toolButton_60"));
        sizePolicy.setHeightForWidth(toolButton_60->sizePolicy().hasHeightForWidth());
        toolButton_60->setSizePolicy(sizePolicy);
        toolButton_60->setFont(font4);

        gridLayout_2->addWidget(toolButton_60, 0, 2, 1, 1);

        toolButton_61 = new softkeys(gridLayoutWidget_2);
        toolButton_61->setObjectName(QStringLiteral("toolButton_61"));
        sizePolicy.setHeightForWidth(toolButton_61->sizePolicy().hasHeightForWidth());
        toolButton_61->setSizePolicy(sizePolicy);
        toolButton_61->setFont(font4);

        gridLayout_2->addWidget(toolButton_61, 1, 5, 1, 1);

        toolButton_62 = new softkeys(gridLayoutWidget_2);
        toolButton_62->setObjectName(QStringLiteral("toolButton_62"));
        sizePolicy.setHeightForWidth(toolButton_62->sizePolicy().hasHeightForWidth());
        toolButton_62->setSizePolicy(sizePolicy);
        toolButton_62->setFont(font4);

        gridLayout_2->addWidget(toolButton_62, 2, 0, 1, 1);

        toolButton_63 = new softkeys(gridLayoutWidget_2);
        toolButton_63->setObjectName(QStringLiteral("toolButton_63"));
        sizePolicy.setHeightForWidth(toolButton_63->sizePolicy().hasHeightForWidth());
        toolButton_63->setSizePolicy(sizePolicy);
        toolButton_63->setFont(font4);

        gridLayout_2->addWidget(toolButton_63, 3, 8, 1, 1);

        toolButton_64 = new softkeys(gridLayoutWidget_2);
        toolButton_64->setObjectName(QStringLiteral("toolButton_64"));
        sizePolicy.setHeightForWidth(toolButton_64->sizePolicy().hasHeightForWidth());
        toolButton_64->setSizePolicy(sizePolicy);
        toolButton_64->setFont(font4);

        gridLayout_2->addWidget(toolButton_64, 2, 2, 1, 1);

        toolButton_65 = new softkeys(gridLayoutWidget_2);
        toolButton_65->setObjectName(QStringLiteral("toolButton_65"));
        sizePolicy.setHeightForWidth(toolButton_65->sizePolicy().hasHeightForWidth());
        toolButton_65->setSizePolicy(sizePolicy);
        toolButton_65->setFont(font4);

        gridLayout_2->addWidget(toolButton_65, 3, 5, 1, 1);

        toolButton_66 = new softkeys(gridLayoutWidget_2);
        toolButton_66->setObjectName(QStringLiteral("toolButton_66"));
        sizePolicy.setHeightForWidth(toolButton_66->sizePolicy().hasHeightForWidth());
        toolButton_66->setSizePolicy(sizePolicy);
        toolButton_66->setFont(font4);

        gridLayout_2->addWidget(toolButton_66, 2, 3, 1, 1);

        toolButton_67 = new softkeys(gridLayoutWidget_2);
        toolButton_67->setObjectName(QStringLiteral("toolButton_67"));
        sizePolicy.setHeightForWidth(toolButton_67->sizePolicy().hasHeightForWidth());
        toolButton_67->setSizePolicy(sizePolicy);
        toolButton_67->setFont(font4);

        gridLayout_2->addWidget(toolButton_67, 1, 1, 1, 1);

        toolButton_68 = new softkeys(gridLayoutWidget_2);
        toolButton_68->setObjectName(QStringLiteral("toolButton_68"));
        toolButton_68->setEnabled(true);
        sizePolicy.setHeightForWidth(toolButton_68->sizePolicy().hasHeightForWidth());
        toolButton_68->setSizePolicy(sizePolicy);
        toolButton_68->setFont(font4);

        gridLayout_2->addWidget(toolButton_68, 0, 4, 1, 1);

        toolButton_69 = new softkeys(gridLayoutWidget_2);
        toolButton_69->setObjectName(QStringLiteral("toolButton_69"));
        sizePolicy.setHeightForWidth(toolButton_69->sizePolicy().hasHeightForWidth());
        toolButton_69->setSizePolicy(sizePolicy);
        toolButton_69->setFont(font4);

        gridLayout_2->addWidget(toolButton_69, 3, 6, 1, 1);

        toolButton_70 = new softkeys(gridLayoutWidget_2);
        toolButton_70->setObjectName(QStringLiteral("toolButton_70"));
        sizePolicy.setHeightForWidth(toolButton_70->sizePolicy().hasHeightForWidth());
        toolButton_70->setSizePolicy(sizePolicy);
        toolButton_70->setFont(font4);

        gridLayout_2->addWidget(toolButton_70, 2, 8, 1, 1);

        toolButton_71 = new softkeys(gridLayoutWidget_2);
        toolButton_71->setObjectName(QStringLiteral("toolButton_71"));
        sizePolicy.setHeightForWidth(toolButton_71->sizePolicy().hasHeightForWidth());
        toolButton_71->setSizePolicy(sizePolicy);
        toolButton_71->setFont(font4);

        gridLayout_2->addWidget(toolButton_71, 3, 4, 1, 1);

        toolButton_72 = new softkeys(gridLayoutWidget_2);
        toolButton_72->setObjectName(QStringLiteral("toolButton_72"));
        sizePolicy.setHeightForWidth(toolButton_72->sizePolicy().hasHeightForWidth());
        toolButton_72->setSizePolicy(sizePolicy);
        toolButton_72->setFont(font4);

        gridLayout_2->addWidget(toolButton_72, 1, 7, 1, 1);

        toolButton_73 = new softkeys(gridLayoutWidget_2);
        toolButton_73->setObjectName(QStringLiteral("toolButton_73"));
        sizePolicy.setHeightForWidth(toolButton_73->sizePolicy().hasHeightForWidth());
        toolButton_73->setSizePolicy(sizePolicy);
        toolButton_73->setFont(font4);

        gridLayout_2->addWidget(toolButton_73, 3, 2, 1, 1);

        toolButton_74 = new softkeys(gridLayoutWidget_2);
        toolButton_74->setObjectName(QStringLiteral("toolButton_74"));
        sizePolicy.setHeightForWidth(toolButton_74->sizePolicy().hasHeightForWidth());
        toolButton_74->setSizePolicy(sizePolicy);
        toolButton_74->setFont(font4);
        toolButton_74->setIconSize(QSize(25, 25));

        gridLayout_2->addWidget(toolButton_74, 0, 1, 1, 1);

        toolButton_75 = new softkeys(gridLayoutWidget_2);
        toolButton_75->setObjectName(QStringLiteral("toolButton_75"));
        sizePolicy.setHeightForWidth(toolButton_75->sizePolicy().hasHeightForWidth());
        toolButton_75->setSizePolicy(sizePolicy);
        toolButton_75->setFont(font4);

        gridLayout_2->addWidget(toolButton_75, 2, 7, 1, 1);

        toolButton_76 = new softkeys(gridLayoutWidget_2);
        toolButton_76->setObjectName(QStringLiteral("toolButton_76"));
        sizePolicy.setHeightForWidth(toolButton_76->sizePolicy().hasHeightForWidth());
        toolButton_76->setSizePolicy(sizePolicy);
        toolButton_76->setFont(font4);

        gridLayout_2->addWidget(toolButton_76, 2, 6, 1, 1);

        toolButton_77 = new softkeys(gridLayoutWidget_2);
        toolButton_77->setObjectName(QStringLiteral("toolButton_77"));
        sizePolicy.setHeightForWidth(toolButton_77->sizePolicy().hasHeightForWidth());
        toolButton_77->setSizePolicy(sizePolicy);
        toolButton_77->setFont(font4);

        gridLayout_2->addWidget(toolButton_77, 2, 9, 1, 1);

        toolButton_78 = new softkeys(gridLayoutWidget_2);
        toolButton_78->setObjectName(QStringLiteral("toolButton_78"));
        sizePolicy.setHeightForWidth(toolButton_78->sizePolicy().hasHeightForWidth());
        toolButton_78->setSizePolicy(sizePolicy);
        toolButton_78->setFont(font4);

        gridLayout_2->addWidget(toolButton_78, 3, 9, 1, 1);

        toolButton_79 = new softkeys(gridLayoutWidget_2);
        toolButton_79->setObjectName(QStringLiteral("toolButton_79"));
        sizePolicy.setHeightForWidth(toolButton_79->sizePolicy().hasHeightForWidth());
        toolButton_79->setSizePolicy(sizePolicy);
        toolButton_79->setFont(font4);

        gridLayout_2->addWidget(toolButton_79, 0, 9, 1, 1);

        toolButton_80 = new softkeys(gridLayoutWidget_2);
        toolButton_80->setObjectName(QStringLiteral("toolButton_80"));
        sizePolicy.setHeightForWidth(toolButton_80->sizePolicy().hasHeightForWidth());
        toolButton_80->setSizePolicy(sizePolicy);
        toolButton_80->setFont(font4);

        gridLayout_2->addWidget(toolButton_80, 1, 4, 1, 1);

        toolButton_81 = new softkeys(gridLayoutWidget_2);
        toolButton_81->setObjectName(QStringLiteral("toolButton_81"));
        sizePolicy.setHeightForWidth(toolButton_81->sizePolicy().hasHeightForWidth());
        toolButton_81->setSizePolicy(sizePolicy);
        toolButton_81->setFont(font4);
        toolButton_81->setIconSize(QSize(25, 25));

        gridLayout_2->addWidget(toolButton_81, 0, 0, 1, 1);

        register1->setCentralWidget(centralwidget);

        retranslateUi(register1);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(register1);
    } // setupUi

    void retranslateUi(QMainWindow *register1)
    {
        register1->setWindowTitle(QApplication::translate("register1", "MainWindow", 0));
        backgroundlabel->setText(QString());
        hm_label->setText(QString());
        yd_label->setText(QString());
        label_2->setText(QString());
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("register1", "master", 0)
         << QApplication::translate("register1", "employee", 0)
        );
        boy_button_1->setText(QString());
        girl_button_1->setText(QString());
        employee_check->setText(QString());
        cancel_bt_2->setText(QString());
        label_4->setText(QApplication::translate("register1", "\345\247\223\345\220\215\357\274\232", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("register1", "\346\231\256\351\200\232\344\272\272\345\221\230", 0));
        label_3->setText(QString());
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("register1", "1\345\260\217\346\227\266", 0)
         << QApplication::translate("register1", "2\345\260\217\346\227\266", 0)
         << QApplication::translate("register1", "3\345\260\217\346\227\266", 0)
         << QApplication::translate("register1", "4\345\260\217\346\227\266", 0)
         << QApplication::translate("register1", "5\345\260\217\346\227\266", 0)
         << QApplication::translate("register1", "6\345\260\217\346\227\266", 0)
         << QApplication::translate("register1", "7\345\260\217\346\227\266", 0)
        );
        comboBox_4->clear();
        comboBox_4->insertItems(0, QStringList()
         << QApplication::translate("register1", "6:00\345\267\246\345\217\263", 0)
         << QApplication::translate("register1", "7:00\345\267\246\345\217\263", 0)
         << QApplication::translate("register1", "8:00\345\267\246\345\217\263", 0)
         << QApplication::translate("register1", "9:00\345\267\246\345\217\263", 0)
         << QApplication::translate("register1", "10:00\345\267\246\345\217\263", 0)
         << QApplication::translate("register1", "11:00\345\267\246\345\217\263", 0)
         << QApplication::translate("register1", "12:00\345\267\246\345\217\263", 0)
         << QApplication::translate("register1", "13:00\345\267\246\345\217\263", 0)
         << QApplication::translate("register1", "14:00\345\267\246\345\217\263", 0)
         << QApplication::translate("register1", "15:00\345\267\246\345\217\263", 0)
         << QApplication::translate("register1", "16:00\345\267\246\345\217\263", 0)
         << QApplication::translate("register1", "17:00\345\267\246\345\217\263", 0)
         << QApplication::translate("register1", "18:00\345\267\246\345\217\263", 0)
        );
        boy_button_2->setText(QString());
        girl_button_2->setText(QString());
        visit_check->setText(QString());
        cancel_bt->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("register1", "\350\256\277\345\256\242", 0));
        toolButton_42->setText(QApplication::translate("register1", "z", 0));
        toolButton_43->setText(QApplication::translate("register1", "4", 0));
        toolButton_44->setText(QApplication::translate("register1", "v", 0));
        toolButton_45->setText(QApplication::translate("register1", "u", 0));
        toolButton_46->setText(QApplication::translate("register1", "s", 0));
        toolButton_47->setText(QApplication::translate("register1", "8", 0));
        toolButton_48->setText(QApplication::translate("register1", "o", 0));
        toolButton_49->setText(QApplication::translate("register1", "p", 0));
        toolButton_50->setText(QApplication::translate("register1", "h", 0));
        toolButton_51->setText(QApplication::translate("register1", ",", 0));
        toolButton_52->setText(QApplication::translate("register1", "q", 0));
        toolButton_53->setText(QApplication::translate("register1", "6", 0));
        toolButton_54->setText(QApplication::translate("register1", "r", 0));
        toolButton_55->setText(QApplication::translate("register1", "e", 0));
        toolButton_56->setText(QApplication::translate("register1", "9", 0));
        toolButton_57->setText(QApplication::translate("register1", "7", 0));
        toolButton_58->setText(QApplication::translate("register1", "x", 0));
        toolButton_59->setText(QApplication::translate("register1", "g", 0));
        toolButton_60->setText(QApplication::translate("register1", "3", 0));
        toolButton_61->setText(QApplication::translate("register1", "y", 0));
        toolButton_62->setText(QApplication::translate("register1", "a", 0));
        toolButton_63->setText(QApplication::translate("register1", ".", 0));
        toolButton_64->setText(QApplication::translate("register1", "d", 0));
        toolButton_65->setText(QApplication::translate("register1", "n", 0));
        toolButton_66->setText(QApplication::translate("register1", "f", 0));
        toolButton_67->setText(QApplication::translate("register1", "w", 0));
        toolButton_68->setText(QApplication::translate("register1", "5", 0));
        toolButton_69->setText(QApplication::translate("register1", "m", 0));
        toolButton_70->setText(QApplication::translate("register1", "l", 0));
        toolButton_71->setText(QApplication::translate("register1", "b", 0));
        toolButton_72->setText(QApplication::translate("register1", "i", 0));
        toolButton_73->setText(QApplication::translate("register1", "c", 0));
        toolButton_74->setText(QApplication::translate("register1", "2", 0));
        toolButton_75->setText(QApplication::translate("register1", "k", 0));
        toolButton_76->setText(QApplication::translate("register1", "j", 0));
        toolButton_77->setText(QApplication::translate("register1", "<-", 0));
        toolButton_78->setText(QApplication::translate("register1", "/", 0));
        toolButton_79->setText(QApplication::translate("register1", "0", 0));
        toolButton_80->setText(QApplication::translate("register1", "t", 0));
        toolButton_81->setText(QApplication::translate("register1", "1", 0));
    } // retranslateUi

};

namespace Ui {
    class register1: public Ui_register1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER1_H
