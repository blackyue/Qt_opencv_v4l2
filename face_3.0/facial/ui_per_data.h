/********************************************************************************
** Form generated from reading UI file 'per_data.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PER_DATA_H
#define UI_PER_DATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_per_data
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *hm_label;
    QLabel *yd_label;
    QTableWidget *data_tw;
    QPushButton *return_button;
    QComboBox *select_cb;
    QPushButton *select_button;

    void setupUi(QMainWindow *per_data)
    {
        if (per_data->objectName().isEmpty())
            per_data->setObjectName(QStringLiteral("per_data"));
        per_data->resize(1024, 600);
        centralwidget = new QWidget(per_data);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 1024, 600));
        label->setStyleSheet(QLatin1String("background-color: rgb(223, 32, 32);\n"
"image: url(:/new/prefix1/image/menu8.jpg);"));
        hm_label = new QLabel(centralwidget);
        hm_label->setObjectName(QStringLiteral("hm_label"));
        hm_label->setGeometry(QRect(730, 80, 201, 41));
        QFont font;
        font.setPointSize(42);
        hm_label->setFont(font);
        yd_label = new QLabel(centralwidget);
        yd_label->setObjectName(QStringLiteral("yd_label"));
        yd_label->setGeometry(QRect(760, 120, 161, 71));
        QFont font1;
        font1.setPointSize(15);
        yd_label->setFont(font1);
        data_tw = new QTableWidget(centralwidget);
        data_tw->setObjectName(QStringLiteral("data_tw"));
        data_tw->setGeometry(QRect(30, 150, 651, 421));
        QFont font2;
        font2.setPointSize(16);
        data_tw->setFont(font2);
        return_button = new QPushButton(centralwidget);
        return_button->setObjectName(QStringLiteral("return_button"));
        return_button->setGeometry(QRect(460, 90, 51, 41));
        return_button->setFlat(true);
        select_cb = new QComboBox(centralwidget);
        select_cb->setObjectName(QStringLiteral("select_cb"));
        select_cb->setGeometry(QRect(20, 83, 221, 48));
        QFont font3;
        font3.setPointSize(18);
        select_cb->setFont(font3);
        select_cb->setFrame(true);
        select_button = new QPushButton(centralwidget);
        select_button->setObjectName(QStringLiteral("select_button"));
        select_button->setGeometry(QRect(240, 84, 51, 48));
        select_button->setFlat(true);
        per_data->setCentralWidget(centralwidget);

        retranslateUi(per_data);

        QMetaObject::connectSlotsByName(per_data);
    } // setupUi

    void retranslateUi(QMainWindow *per_data)
    {
        per_data->setWindowTitle(QApplication::translate("per_data", "MainWindow", 0));
        label->setText(QString());
        hm_label->setText(QString());
        yd_label->setText(QString());
        return_button->setText(QString());
        select_cb->clear();
        select_cb->insertItems(0, QStringList()
         << QApplication::translate("per_data", "1001", 0)
         << QApplication::translate("per_data", "1002", 0)
         << QApplication::translate("per_data", "1003", 0)
        );
        select_button->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class per_data: public Ui_per_data {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PER_DATA_H
