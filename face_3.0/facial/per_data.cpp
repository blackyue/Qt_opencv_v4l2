#include "per_data.h"
#include "ui_per_data.h"
#include <QtSql/qsql.h>
#include <QtSql/QSql>
#include <QtSql/qsql.h>
#include <QtSql/QtSql>

per_data::per_data(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::per_data)
{
    ui->setupUi(this);
    QTimer  *timer_calender1;
    timer_calender1=new  QTimer(this);
    connect(timer_calender1,SIGNAL(timeout()),this,SLOT(timerupdate()));
    connect(timer_calender1,SIGNAL(timeout()),this,SLOT(timerupdate2()));
    timer_calender1->start(1000);

    ui->data_tw->setColumnCount(5);
    ui->data_tw->setRowCount(9);

    QStringList header;
    header<<"姓名"<<"编号"<<"温度"<<"考勤时间"<<"考勤情况";
    ui->data_tw->setHorizontalHeaderLabels(header);
    ui->data_tw->horizontalHeader()->setStretchLastSection(true);   //设置表头充满表格的宽度
    ui->data_tw->verticalHeader()->setVisible(false);   //设置垂直表头不可见
    ui->data_tw->horizontalHeader()->setFixedHeight(48);    //设置表头高度
    ui->data_tw->verticalHeader()->setDefaultSectionSize(45);   //设置每行高度
    ui->data_tw->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);    //设置列间距相等





}

void per_data::timerupdate()
{
    QDateTime time = QDateTime :: currentDateTime();
    QString str = time .toString(" hh    mm");
    ui->hm_label->setText(str);
    ui->hm_label->setStyleSheet("color:white;");
}

void per_data::timerupdate2()
{
    QDateTime time = QDateTime :: currentDateTime();
    QString str = time.toString("yyyy/MM/dd \ndddd");
    ui->yd_label->setText(str);
    ui->yd_label->setStyleSheet("color:white;");
}

per_data::~per_data()
{
    delete ui;
}

void per_data::on_return_button_clicked()
{
    login_main *l = new login_main();
    l->show();
    this->close();
}

void per_data::on_select_button_clicked()
{
    /*
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("CashSystem.db");
*/

    QSqlDatabase db;


    //关联数据库文件给连接对象
    if(QSqlDatabase::contains("dbConnection2"))
    {
        qDebug()<<"exist dbConnection2[register]";
        //如果数据库文件已存在连接列表，则返回给连接对象
        db = QSqlDatabase::database("dbConnection2");
         db.setDatabaseName("CashSystem.db");

    }
    else
    {
        qDebug()<<"No exist dbConnection2[register]";
        //如果没有存在连接列表，则新建一个连接对象
        db = QSqlDatabase::addDatabase("QSQLITE","dbConnection2");
        db.setDatabaseName("CashSystem.db");
    }

    if(db.open())
    {

          QString name;
          int id;
          double temperature;
          QString arrive_time;
          QString grade;

          id=ui->select_cb->currentText().toInt();

          QSqlQuery sql_query(db);
          QString select_sql=QString ("select name from member where id = %1").arg(id);
          sql_query.prepare(select_sql);
          if(!sql_query.exec())
          {
              qDebug()<<sql_query.lastError();
              qDebug()<<"select name from member failed!";
          }
          else
          {
              while(sql_query.next())
              {
                  name=sql_query.value(0).toString();
                  qDebug()<<"name = "<<name;
                  QTableWidgetItem *titem0;
                  titem0 = new QTableWidgetItem;
                  titem0->setText(name);
                  ui->data_tw->setItem(0,0,titem0);
                  titem0->setTextAlignment(Qt::AlignCenter);


              }
          }

          QString select_sql_2=QString("select temperature,arrive_time from arrive where id=%1").arg(id);
          sql_query.prepare(select_sql_2);
          if(!sql_query.exec())
          {
              qDebug()<<sql_query.lastError();
              qDebug()<<"select temperature and arrive time from member failed!";
          }
          else
          {
              while(sql_query.next())
              {
                  temperature=sql_query.value(0).toDouble();
                  arrive_time=sql_query.value(1).toString();
                  qDebug()<<QString("temperature = %1  arrive_time = %2 ").arg(temperature).arg(arrive_time);
                  QTableWidgetItem *titem3,*titem4;


                  ui->data_tw->setItem(0,1,new QTableWidgetItem(QString("%1").arg(id)));

                  ui->data_tw->item(0,1)->setTextAlignment(Qt::AlignCenter);


                  ui->data_tw->setItem(0,2,new QTableWidgetItem(QString("%1").arg(temperature)));
                  ui->data_tw->item(0,2)->setTextAlignment(Qt::AlignCenter);


                  titem3 = new QTableWidgetItem;
                  titem3->setText(arrive_time);
                  ui->data_tw->setItem(0,3,titem3);
                  titem3->setTextAlignment(Qt::AlignCenter);


                  QString temp_time="2021-07-13 ";
                  QVariant arrive_time2=temp_time.append(arrive_time);
                  qDebug()<<"arrive_time2 ="<<arrive_time2;

                  QDateTime time = arrive_time2.toDateTime();
                  int ctime = time.toTime_t();
                  qDebug()<<"ctime="<<ctime;

                  QDateTime start = QDateTime ::fromString("2021-07-13 17:30:39","yyyy-MM-dd hh:mm:ss");
                  int stime=start.toTime_t();
                  qDebug()<<"stime="<<stime;


                  if(ctime-stime>0)
                  {
                      grade ="bad";
                  }
                  else
                  {
                      grade="good";
                  }


                  titem4 = new QTableWidgetItem;
                  titem4->setText(grade);
                  ui->data_tw->setItem(0,4,titem4);
                  titem4->setTextAlignment(Qt::AlignCenter);


              }
          }
    }
    db.close();
}
