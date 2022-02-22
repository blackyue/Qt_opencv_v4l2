/********************************************************************************
** Form generated from reading UI file 'manager.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGER_H
#define UI_MANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_manager
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QTabWidget *main_tab;
    QWidget *tab_3;
    QWidget *tab;
    QLabel *label_2;
    QTableWidget *attance_tw;
    QPushButton *return_button_1;
    QComboBox *comboBox_1;
    QPushButton *check_bt;
    QPushButton *all_bt;
    QWidget *tab_2;
    QLabel *label_3;
    QTableWidget *visit_tw;
    QPushButton *return_button_2;
    QComboBox *comboBox_6;
    QPushButton *check_bt_2;
    QWidget *tab_4;
    QLabel *label_4;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QComboBox *comboBox_4;
    QComboBox *comboBox_5;
    QPushButton *return_button_3;

    void setupUi(QMainWindow *manager)
    {
        if (manager->objectName().isEmpty())
            manager->setObjectName(QStringLiteral("manager"));
        manager->resize(1024, 600);
        centralwidget = new QWidget(manager);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 1024, 600));
        label->setStyleSheet(QLatin1String("background-color: rgb(228, 27, 27);\n"
"image: url(:/new/prefix1/image/menu6.jpg);"));
        main_tab = new QTabWidget(centralwidget);
        main_tab->setObjectName(QStringLiteral("main_tab"));
        main_tab->setGeometry(QRect(0, 0, 1024, 600));
        main_tab->setFocusPolicy(Qt::TabFocus);
        main_tab->setLayoutDirection(Qt::LeftToRight);
        main_tab->setTabPosition(QTabWidget::West);
        main_tab->setMovable(false);
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        main_tab->addTab(tab_3, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 0, 834, 600));
        label_2->setStyleSheet(QLatin1String("background-color: rgb(217, 13, 13);\n"
"image: url(:/new/prefix1/image/menu63.jpg);"));
        attance_tw = new QTableWidget(tab);
        attance_tw->setObjectName(QStringLiteral("attance_tw"));
        attance_tw->setGeometry(QRect(23, 100, 791, 381));
        return_button_1 = new QPushButton(tab);
        return_button_1->setObjectName(QStringLiteral("return_button_1"));
        return_button_1->setGeometry(QRect(520, 50, 51, 41));
        return_button_1->setFlat(true);
        comboBox_1 = new QComboBox(tab);
        comboBox_1->setObjectName(QStringLiteral("comboBox_1"));
        comboBox_1->setGeometry(QRect(29, 58, 170, 37));
        comboBox_1->setStyleSheet(QStringLiteral("font: 15pt \"Ubuntu\";"));
        check_bt = new QPushButton(tab);
        check_bt->setObjectName(QStringLiteral("check_bt"));
        check_bt->setGeometry(QRect(200, 54, 51, 37));
        check_bt->setFlat(true);
        all_bt = new QPushButton(tab);
        all_bt->setObjectName(QStringLiteral("all_bt"));
        all_bt->setGeometry(QRect(270, 56, 100, 39));
        all_bt->setFlat(true);
        main_tab->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 0, 834, 600));
        label_3->setStyleSheet(QLatin1String("background-color: rgb(239, 0, 0);\n"
"image: url(:/new/prefix1/image/menu61.jpg);"));
        visit_tw = new QTableWidget(tab_2);
        visit_tw->setObjectName(QStringLiteral("visit_tw"));
        visit_tw->setGeometry(QRect(20, 100, 801, 381));
        return_button_2 = new QPushButton(tab_2);
        return_button_2->setObjectName(QStringLiteral("return_button_2"));
        return_button_2->setGeometry(QRect(520, 50, 51, 41));
        return_button_2->setFlat(true);
        comboBox_6 = new QComboBox(tab_2);
        comboBox_6->setObjectName(QStringLiteral("comboBox_6"));
        comboBox_6->setGeometry(QRect(28, 58, 170, 37));
        comboBox_6->setStyleSheet(QStringLiteral("font: 15pt \"Ubuntu\";"));
        check_bt_2 = new QPushButton(tab_2);
        check_bt_2->setObjectName(QStringLiteral("check_bt_2"));
        check_bt_2->setGeometry(QRect(199, 59, 51, 37));
        check_bt_2->setFlat(true);
        main_tab->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        label_4 = new QLabel(tab_4);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, -10, 834, 600));
        label_4->setStyleSheet(QLatin1String("background-color: rgb(244, 64, 64);\n"
"image: url(:/new/prefix1/image/menu62.jpg);"));
        comboBox = new QComboBox(tab_4);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(167, 130, 280, 29));
        comboBox_2 = new QComboBox(tab_4);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(167, 170, 280, 29));
        comboBox_3 = new QComboBox(tab_4);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setGeometry(QRect(167, 210, 280, 29));
        comboBox_4 = new QComboBox(tab_4);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));
        comboBox_4->setGeometry(QRect(167, 250, 280, 29));
        comboBox_5 = new QComboBox(tab_4);
        comboBox_5->setObjectName(QStringLiteral("comboBox_5"));
        comboBox_5->setGeometry(QRect(167, 290, 280, 29));
        return_button_3 = new QPushButton(tab_4);
        return_button_3->setObjectName(QStringLiteral("return_button_3"));
        return_button_3->setGeometry(QRect(520, 50, 51, 41));
        return_button_3->setFlat(true);
        main_tab->addTab(tab_4, QString());
        manager->setCentralWidget(centralwidget);

        retranslateUi(manager);

        main_tab->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(manager);
    } // setupUi

    void retranslateUi(QMainWindow *manager)
    {
        manager->setWindowTitle(QApplication::translate("manager", "MainWindow", 0));
        label->setText(QString());
        main_tab->setTabText(main_tab->indexOf(tab_3), QString());
        label_2->setText(QString());
        return_button_1->setText(QString());
        comboBox_1->clear();
        comboBox_1->insertItems(0, QStringList()
         << QApplication::translate("manager", "1001", 0)
         << QApplication::translate("manager", "1002", 0)
         << QApplication::translate("manager", "1003", 0)
         << QApplication::translate("manager", "1004", 0)
        );
        check_bt->setText(QString());
        all_bt->setText(QString());
        main_tab->setTabText(main_tab->indexOf(tab), QString());
        label_3->setText(QString());
        return_button_2->setText(QString());
        comboBox_6->clear();
        comboBox_6->insertItems(0, QStringList()
         << QApplication::translate("manager", "1001", 0)
         << QApplication::translate("manager", "1002", 0)
         << QApplication::translate("manager", "1003", 0)
         << QApplication::translate("manager", "1004", 0)
        );
        check_bt_2->setText(QString());
        main_tab->setTabText(main_tab->indexOf(tab_2), QString());
        label_4->setText(QString());
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("manager", "123", 0)
         << QApplication::translate("manager", "1234", 0)
         << QApplication::translate("manager", "12345", 0)
         << QApplication::translate("manager", "123456", 0)
         << QApplication::translate("manager", "0123456", 0)
        );
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("manager", "37", 0)
         << QApplication::translate("manager", "37.1", 0)
         << QApplication::translate("manager", "37.2", 0)
         << QApplication::translate("manager", "37.3", 0)
        );
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("manager", "8:30", 0)
         << QApplication::translate("manager", "8:40", 0)
         << QApplication::translate("manager", "8:50", 0)
         << QApplication::translate("manager", "9:00", 0)
        );
        comboBox_4->clear();
        comboBox_4->insertItems(0, QStringList()
         << QApplication::translate("manager", "192.168.1.111", 0)
         << QApplication::translate("manager", "192.168.1.112", 0)
         << QApplication::translate("manager", "192.168.1.113", 0)
        );
        comboBox_5->clear();
        comboBox_5->insertItems(0, QStringList()
         << QApplication::translate("manager", "60", 0)
         << QApplication::translate("manager", "70", 0)
         << QApplication::translate("manager", "80", 0)
        );
        return_button_3->setText(QString());
        main_tab->setTabText(main_tab->indexOf(tab_4), QString());
    } // retranslateUi

};

namespace Ui {
    class manager: public Ui_manager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGER_H
