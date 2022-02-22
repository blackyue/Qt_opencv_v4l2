#ifndef LOGIN_MAIN_H
#define LOGIN_MAIN_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>
#include <QTime>
#include <QString>
#include <QDebug>
#include "per_data.h"
#include "manager.h"
#include "facial.h"

namespace Ui {
class login_main;
}

class login_main : public QMainWindow
{
    Q_OBJECT

public:
    explicit login_main(QWidget *parent = 0);
    ~login_main();
public slots:

    void timerupdate();
    void timerupdate2();

private slots:
    void on_num1_button_clicked();

    void on_num2_button_clicked();

    void on_num3_button_clicked();

    void on_delete_button_clicked();

    void on_num0_button_clicked();

    void on_clear_button_clicked();

    void on_enter_button_clicked();

    void on_return_button_3_clicked();

    void on_num4_button_clicked();

    void on_num5_button_clicked();

    void on_num6_button_clicked();

    void on_num7_button_clicked();

    void on_num8_button_clicked();

    void on_num9_button_clicked();

private:
    Ui::login_main *ui;
    QString pwd;
};

#endif // LOGIN_MAIN_H
