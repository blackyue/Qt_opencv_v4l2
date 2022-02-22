#include "facial.h"
#include "ui_facial.h"
#include "ui_prompt.h"
#include "ui_prompt_2.h"
#include "ui_prompt_3.h"

void sleep(unsigned int msec)
{
    QTime reachTime = QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime() < reachTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
}


facial::facial(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::facial)
{

    ui->setupUi(this);
    QTimer  *timer_calender1;
    timer_calender1=new  QTimer(this);
    connect(timer_calender1,SIGNAL(timeout()),this,SLOT(timerupdate()));
    connect(timer_calender1,SIGNAL(timeout()),this,SLOT(timerupdate2()));
    timer_calender1->start(1000);


    connect(ui->main_label,SIGNAL(pressed()),this,SLOT(onPressed()));
    connect(ui->main_label,SIGNAL(released()),this,SLOT(onReleased()));


    time_delay=0;
    timer_count=new QTimer(this);
    connect(timer_count,SIGNAL(timeout()),this,SLOT(timeout_handler()));

    QFont ft;
    ft.setPointSize(20);
    ui->tem_label->setFont(ft);



}
void facial::onPressed()
{
   timer_count->start(1000);
}

void facial::onReleased()
{
    if(time_delay>=2)
    {
        login_main *admin = new login_main(this);
        admin->show();

        //this->close();
        this->hide();
    }
    time_delay=0;
    timer_count->stop();
}

void facial::timeout_handler()
{
    time_delay++;
    qDebug()<<"time_delay:"<<time_delay<<'\n';
}

facial::~facial()
{
    delete ui;
}

void facial::timerupdate()
{
    QDateTime time = QDateTime :: currentDateTime();
    QString str = time .toString(" hh    mm");
    ui->hm_label->setText(str);
    ui->hm_label->setStyleSheet("color:white;");
}

void facial::timerupdate2()
{
    QDateTime time = QDateTime :: currentDateTime();
    QString str = time.toString("yyyy/MM/dd \ndddd");
    ui->yd_label->setText(str);
    ui->yd_label->setStyleSheet("color:white;");
}

void facial::on_text_button1_clicked()
{
    w = new QMainWindow();
    pui = new Ui::prompt();
    pui->setupUi(w);
    w->show();
    this->close();

    QTimer  *timer_calender;
    timer_calender=new  QTimer(this);
    connect(timer_calender,SIGNAL(timeout()),this,SLOT(timerupdate3()));
    connect(timer_calender,SIGNAL(timeout()),this,SLOT(timerupdate4()));
    timer_calender->start(1000);


    timer_quit=new QTimer(this);
    connect(timer_quit,SIGNAL(timeout()),this,SLOT(timequit()));
    timer_quit->start(4000);



}
void facial::timequit()
{
    w->close();
    ui->name_label->clear();
    ui->tem_label->clear();
    ui->time_label->clear();
    this->show();
    timer_quit->stop();
}

void facial::timerupdate3()
{
    QDateTime time = QDateTime :: currentDateTime();
    QString str = time .toString(" hh    mm");
    pui->hm_label2->setText(str);
    pui->hm_label2->setStyleSheet("color:white;");
}

void facial::timerupdate4()
{
    QDateTime time = QDateTime :: currentDateTime();
    QString str = time.toString("yyyy/MM/dd \ndddd");
    pui->yd_label2->setText(str);
    pui->yd_label2->setStyleSheet("color:white;");
}


void facial::on_text_button2_clicked()
{
    ww = new QMainWindow();
    ppui = new Ui::prompt_2();
    ppui->setupUi(ww);
    ww->show();
    this->close();

    QTimer  *timer_calender;
    timer_calender=new  QTimer(this);
    connect(timer_calender,SIGNAL(timeout()),this,SLOT(timerupdate5()));
    connect(timer_calender,SIGNAL(timeout()),this,SLOT(timerupdate6()));
    timer_calender->start(1000);


    timer_quit2=new QTimer(this);
    connect(timer_quit2,SIGNAL(timeout()),this,SLOT(timequit2()));
    timer_quit2->start(4000);

}


void facial::timequit2()
{
    ww->close();
    this->show();
    timer_quit2->stop();
}

void facial::timerupdate5()
{
    QDateTime time = QDateTime :: currentDateTime();
    QString str = time .toString(" hh    mm");
    ppui->hm_label3->setText(str);
    ppui->hm_label3->setStyleSheet("color:white;");
}

void facial::timerupdate6()
{
    QDateTime time = QDateTime :: currentDateTime();
    QString str = time.toString("yyyy/MM/dd \ndddd");
    ppui->yd_label3->setText(str);
    ppui->yd_label3->setStyleSheet("color:white;");
}


void facial::on_text_button3_clicked()
{
    www = new QMainWindow();
    pppui = new Ui::prompt_3();
    pppui->setupUi(www);
    www->show();
    this->close();

    QTimer  *timer_calender;
    timer_calender=new  QTimer(this);
    connect(timer_calender,SIGNAL(timeout()),this,SLOT(timerupdate7()));
    connect(timer_calender,SIGNAL(timeout()),this,SLOT(timerupdate8()));
    timer_calender->start(1000);


    timer_quit3=new QTimer(this);
    connect(timer_quit3,SIGNAL(timeout()),this,SLOT(timequit3()));
    timer_quit3->start(4000);

}
void facial::timequit3()
{
    www->close();
    register1 *r = new register1();
    r->show();

    timer_quit3->stop();
}

void facial::timerupdate7()
{
    QDateTime time = QDateTime :: currentDateTime();
    QString str = time .toString(" hh    mm");
    pppui->hm_label4->setText(str);
    pppui->hm_label4->setStyleSheet("color:white;");
}

void facial::timerupdate8()
{
    QDateTime time = QDateTime :: currentDateTime();
    QString str = time.toString("yyyy/MM/dd \ndddd");
    pppui->yd_label4->setText(str);
    pppui->yd_label4->setStyleSheet("color:white;");
}

void facial::on_pass_button_clicked()
{
    int num,num2;
    int id=1004;
    double temperature=37.1;
    QString arrive_time=QDateTime::currentDateTime().toString("hh:mm:ss");

/*
    QSqlDatabase db;


    //关联数据库文件给连接对象
    if(QSqlDatabase::contains("dbConnection2"))
    {
        qDebug()<<"exist dbConnection2[register]";
        //如果数据库文件已存在连接列表，则返回给连接对象
        db = QSqlDatabase::database("dbConnection2");

    }
    else
    {
        qDebug()<<"No exist dbConnection2[register]";
        //如果没有存在连接列表，则新建一个连接对象
        db = QSqlDatabase::addDatabase("QSQLITE","dbConnection2");
        db.setDatabaseName("CashSystem.db");
    }
    */


    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("CashSystem.db");

    db.open();

    QSqlQuery sql_query(db);

/*
    QString drop_sql="drop table arrive";
    sql_query.prepare(drop_sql);
    if(!sql_query.exec())
    {
        qDebug()<<"drop table failed!";
        qDebug()<<sql_query.lastError();
    }
    else
    {
        qDebug()<<"drop table success!";
    }
    */




    if(temperature<=37.1)
    {
        QString select_exsit_sql = QString("select count(*) from member where id = %1").arg(id);
        qDebug()<<"--------------------------checking------------------------------\n";

        //qDebug()<<"id="<<id;
        sql_query.prepare(select_exsit_sql);

        if(!sql_query.exec())
        {
            qDebug()<<sql_query.lastError();
            qDebug()<<"select count from member failed!";
        }

        else
        {
            sql_query.next();
            num2=sql_query.value(0).toInt();
            qDebug()<<"num2="<<num2;
        }


        if(num2==0)
        {
            qDebug()<<sql_query.lastError();
            qDebug()<<"The user is not exist!"<<'\n';

            /*
            ui->name_label->setText("no name");
            ui->name_label->setStyleSheet("color:rgb(255,255,255);");
            ui->tem_label->setStyleSheet("color:rgb(255,255,255);");
            ui->tem_label->setNum(temperature);
            ui->time_label->setText(arrive_time);
            ui->time_label->setStyleSheet("color:rgb(255,255,255);");
            */

            sleep(3000);
            www = new QMainWindow();
            pppui = new Ui::prompt_3();
            pppui->setupUi(www);
            www->show();
            this->close();

            pppui->name_label->setText(name);
            pppui->name_label->setStyleSheet("color:rgb(255,255,255);");
            pppui->time_label->setText(arrive_time);
            pppui->time_label->setStyleSheet("color:rgb(255,255,255);");
            pppui->tem_label->setNum(temperature);
            pppui->tem_label->setStyleSheet("color:rgb(255,255,255);");



            QTimer  *timer_calender;
            timer_calender=new  QTimer(this);
            connect(timer_calender,SIGNAL(timeout()),this,SLOT(timerupdate7()));
            connect(timer_calender,SIGNAL(timeout()),this,SLOT(timerupdate8()));
            timer_calender->start(1000);


            timer_quit3=new QTimer(this);
            connect(timer_quit3,SIGNAL(timeout()),this,SLOT(timequit3()));
            timer_quit3->start(4000);

        }
        else
        {
                QString select_exsit_sql = QString("select count(*) from arrive where id = %1").arg(id);

                sql_query.prepare(select_exsit_sql);
                if(sql_query.exec())
                {
                    if(sql_query.next())
                    {

                        num = sql_query.value(0).toInt();
                        qDebug()<<"the num is "<<num;
                    }
                }
                else
                {
                    qDebug()<<"select count failed!";
                    qDebug()<<sql_query.lastError();
                }
                if(num==0)
                {


                    QString insert_arrive_sql="insert into arrive values(?,?,?)";

                    sql_query.prepare(insert_arrive_sql);

                    QVariantList Groupids;
                    Groupids.append(id);

                    QVariantList Grouptems;
                    Grouptems.append(temperature);

                    QVariantList Grouptimes;
                    Grouptimes.append(arrive_time);


                    sql_query.addBindValue(Groupids);
                    sql_query.addBindValue(Grouptems);
                    sql_query.addBindValue(Grouptimes);




                    if(!sql_query.execBatch())
                    {
                        qDebug()<<sql_query.lastError();
                        qDebug()<<"insert into arrive failed!";
                    }
                    else
                    {
                        qDebug()<<"insert into arrive success!";
                    }

                    QString select_all_sql="select * from arrive";
                    sql_query.prepare(select_all_sql);
                    int Id;
                    QString time;
                    double tem;

                    if(!sql_query.exec())
                    {
                        qDebug()<<sql_query.lastError();
                        qDebug()<<"select arrive failed!";
                    }
                    else
                    {
                        while(sql_query.next())
                        {
                            Id=sql_query.value(0).toInt();
                            tem=sql_query.value(1).toDouble();
                            time=sql_query.value(2).toString();
                            qDebug()<<QString("ID:%1    temperature:%2   arrive_time:%3  ").arg(Id).arg(tem).arg(time);


                        }
                    }
                    QString select_name_sql=QString("select name from member where id =%1").arg(id);
                    sql_query.prepare(select_name_sql);
                    if(sql_query.exec())
                    {
                        if(sql_query.next())
                        {

                            name=sql_query.value(0).toString();
                            qDebug()<<"name is "<<name;

                            /*
                            ui->name_label->setText(name);
                            ui->name_label->setStyleSheet("color:rgb(255,255,255);");
                            ui->tem_label->setStyleSheet("color:rgb(255,255,255);");
                            ui->tem_label->setNum(temperature);
                            ui->time_label->setText(arrive_time);
                            ui->time_label->setStyleSheet("color:rgb(255,255,255);");
                            */


                            sleep(3000);
                            w = new QMainWindow();
                            pui = new Ui::prompt();
                            pui->setupUi(w);
                            w->show();
                            this->close();

                            pui->name_label->setText(name);
                            pui->name_label->setStyleSheet("color:rgb(255,255,255);");
                            pui->time_label->setText(arrive_time);
                            pui->time_label->setStyleSheet("color:rgb(255,255,255);");
                            pui->tem_label->setNum(temperature);
                            pui->tem_label->setStyleSheet("color:rgb(255,255,255);");



                            QTimer  *timer_calender;
                            timer_calender=new  QTimer(this);
                            connect(timer_calender,SIGNAL(timeout()),this,SLOT(timerupdate3()));
                            connect(timer_calender,SIGNAL(timeout()),this,SLOT(timerupdate4()));
                            timer_calender->start(1000);


                            timer_quit=new QTimer(this);
                            connect(timer_quit,SIGNAL(timeout()),this,SLOT(timequit()));
                            timer_quit->start(4000);


                        }

                    }
                    else
                    {
                        qDebug()<<"111  select name from member failed!";
                        qDebug()<<sql_query.lastError();
                    }


                }

                else
                {

                    //QString update_sql="update arrive set temperature=37.0 where id=1001";
                    QString update_sql=QString("update arrive set temperature=%1,arrive_time='%2' where id =%3").arg(temperature).arg(arrive_time).arg(id);
                    sql_query.prepare(update_sql);
                    if(!sql_query.exec())
                    {
                        qDebug()<<"update failed!";
                        qDebug()<<sql_query.lastError();
                    }
                    else
                    {
                        qDebug()<<"update success!";

                        QString select_name_sql=QString("select name from member where id =%1").arg(id);
                        sql_query.prepare(select_name_sql);
                        if(sql_query.exec())
                        {
                            if(sql_query.next())
                            {

                                name=sql_query.value(0).toString();
                                qDebug()<<"name is "<<name;

                                /*
                                ui->name_label->setText(name);
                                ui->name_label->setStyleSheet("color:rgb(255,255,255);");
                                ui->tem_label->setStyleSheet("color:rgb(255,255,255);");
                                ui->tem_label->setNum(temperature);
                                ui->time_label->setText(arrive_time);
                                ui->time_label->setStyleSheet("color:rgb(255,255,255);");
                                */

                                sleep(3000);
                                w = new QMainWindow();
                                pui = new Ui::prompt();
                                pui->setupUi(w);
                                w->show();
                                this->close();

                                pui->name_label->setText(name);
                                pui->name_label->setStyleSheet("color:rgb(255,255,255);");
                                pui->time_label->setText(arrive_time);
                                pui->time_label->setStyleSheet("color:rgb(255,255,255);");
                                pui->tem_label->setNum(temperature);
                                pui->tem_label->setStyleSheet("color:rgb(255,255,255);");



                                QTimer  *timer_calender;
                                timer_calender=new  QTimer(this);
                                connect(timer_calender,SIGNAL(timeout()),this,SLOT(timerupdate3()));
                                connect(timer_calender,SIGNAL(timeout()),this,SLOT(timerupdate4()));
                                timer_calender->start(1000);


                                timer_quit=new QTimer(this);
                                connect(timer_quit,SIGNAL(timeout()),this,SLOT(timequit()));
                                timer_quit->start(4000);
                            }


                        }
                        else
                        {
                            qDebug()<<"select name from member failed!";
                            qDebug()<<sql_query.lastError();
                        }
                    }
                }
        }
    }

    else
    {



            ui->tem_label->setStyleSheet("color:rgb(255,255,255);");
            ui->tem_label->setNum(temperature);
            ui->time_label->setText(arrive_time);
            ui->time_label->setStyleSheet("color:rgb(255,255,255);");


            sleep(3000);

            ww = new QMainWindow();
            ppui = new Ui::prompt_2();
            ppui->setupUi(ww);
            ww->show();
            this->close();


            ppui->time_label->setText(arrive_time);
            ppui->time_label->setStyleSheet("color:rgb(255,255,255);");
            ppui->tem_label->setNum(temperature);
            ppui->tem_label->setStyleSheet("color:rgb(255,255,255);");


            QTimer  *timer_calender;
            timer_calender=new  QTimer(this);
            connect(timer_calender,SIGNAL(timeout()),this,SLOT(timerupdate5()));
            connect(timer_calender,SIGNAL(timeout()),this,SLOT(timerupdate6()));
            timer_calender->start(1000);


            timer_quit2=new QTimer(this);
            connect(timer_quit2,SIGNAL(timeout()),this,SLOT(timequit2()));
            timer_quit2->start(4000);


    }


    db.close();
}












