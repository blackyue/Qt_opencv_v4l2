#ifndef FACIAL_H
#define FACIAL_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <QString>
#include <QDebug>
#include <QLabel>
#include <QtSql>
#include "elabel.h"
#include "register1.h"
#include "login_main.h"


namespace Ui {
class facial;
class prompt;
class prompt_2;
class prompt_3;
}

class facial : public QMainWindow
{
    Q_OBJECT

public:
    explicit facial(QWidget *parent = 0);
    ~facial();
public slots:

    void timerupdate();
    void timerupdate2();
    void timerupdate3();
    void timerupdate4();
    void timerupdate5();
    void timerupdate6();
    void timerupdate7();
    void timerupdate8();
    void timequit();
    void timequit2();
    void timequit3();

private slots:
    void on_text_button1_clicked();

    void on_text_button2_clicked();

    void on_text_button3_clicked();

    void timeout_handler();

    void onPressed();

    void onReleased();

    //void on_insert_bt_clicked();
    
    void on_pass_button_clicked();

private:
    Ui::facial *ui;
    Ui::prompt *pui;
    QMainWindow *w;
    Ui::prompt_2 *ppui;
    QMainWindow *ww;
    Ui::prompt_3*pppui;
    QMainWindow *www;

    QTimer *timer_quit;
    QTimer *timer_quit2;
    QTimer *timer_quit3;
    QTimer *timer_count;

    int time_delay;
    

    QString name;
    QString grade;

    
    
};

#endif // FACIAL_H
