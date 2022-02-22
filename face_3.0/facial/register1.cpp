#include "register1.h"

#include "mylabel.h"
#include "ui_register1.h"

register1::register1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::register1)
{
    ui->setupUi(this);
    QTimer  *timer_calender1;
    timer_calender1=new  QTimer(this);
    connect(timer_calender1,SIGNAL(timeout()),this,SLOT(timerupdate()));
    connect(timer_calender1,SIGNAL(timeout()),this,SLOT(timerupdate2()));
    timer_calender1->start(1000);


    ui->myWidget->hide();

     //给QLineEdit控件安装事件过滤器
    //QObject::installEventFilter()允许对象拦截指向另一个对象的事件。

    ui->id_lineEdit->installEventFilter(this);
    ui->name_lineEdit->installEventFilter(this);


    connect(ui->backgroundlabel,&mylabel::close_key,this,&register1::hide_widget);

}
void register1::hide_widget()
{
    ui->myWidget->hide();
}
bool register1::eventFilter(QObject *watched, QEvent *event)
{

    if ( (watched == ui->id_lineEdit) && (event->type() == QEvent::MouseButtonPress) )
    {
        ui->myWidget->show();
        ui->id_lineEdit->setFocus();
    }
    else if ( (watched == ui->name_lineEdit) && (event->type() == QEvent::MouseButtonPress) )
    {
        ui->myWidget->show();
        ui->name_lineEdit->setFocus();
    }

    return QMainWindow::eventFilter(watched,event);
}

register1::~register1()
{
    delete ui;
}

void register1::timerupdate()
{
    QDateTime time = QDateTime :: currentDateTime();
    QString str = time .toString(" hh    mm");
    ui->hm_label->setText(str);
    ui->hm_label->setStyleSheet("color:white;");
}

void register1::timerupdate2()
{
    QDateTime time = QDateTime :: currentDateTime();
    QString str = time.toString("yyyy/MM/dd \ndddd");
    ui->yd_label->setText(str);
    ui->yd_label->setStyleSheet("color:white;");
}



void register1::on_boy_button_1_clicked()
{
    sex_check ="man";
}


void register1::on_girl_button_1_clicked()
{
    sex_check="woman";
}

void register1::on_employee_check_clicked()
{

    //创建连接对象
    QSqlDatabase db;
    if(QSqlDatabase::contains("dbConnection2"))
    {
        qDebug()<<"exist dbConnection[main]";
        db=QSqlDatabase::database("dbConnection2");
    }
    else
    {
        qDebug()<<"No exsit dbConnection[main]";
        db = QSqlDatabase::addDatabase("QSQLITE","dbConnection2");
        db.setDatabaseName("CashSystem.db");
    }

    if(db.open())
    {

        //int id=ui->comboBox->currentText().toInt();
        int id = ui->id_lineEdit->text().toInt();
       // QString name="feizai";
        QString name = ui->name_lineEdit->text();
        QString post=ui->comboBox_2->currentText();

        QSqlQuery sql_query(db);


        QString insert_sql="insert into member values(?,?,?,?)";
        QString select_all_sql="select * from member";

        sql_query.prepare(insert_sql);
        /*
        QVariant ID =id;
        QVariant Name = name;
        QVariant Post = post;
        QVariant Sex = sex;

        sql_query.addBindValue(ID);
        sql_query.addBindValue(Name);
        sql_query.addBindValue(Post);
        sql_query.addBindValue(Sex);
        */
        QVariantList GroupIDS;
        GroupIDS.append(id);

        QVariantList GroupNameS;
        GroupNameS.append(name);

        QVariantList GroupPostS;
        GroupPostS.append(post);

        QVariantList GroupSexS;
        GroupSexS.append(sex_check);

        sql_query.addBindValue(GroupIDS);
        sql_query.addBindValue(GroupNameS);
        sql_query.addBindValue(GroupPostS);
        sql_query.addBindValue(GroupSexS);

        if(!sql_query.execBatch())
        {
            qDebug()<<sql_query.lastError();
        }
        else
        {
            qDebug()<<"insert record success!\n";
        }


        sql_query.prepare(select_all_sql);
        int Id;
        QString user;
        QString job;
        QString sex2;
        if(!sql_query.exec())
        {
            qDebug()<<sql_query.lastError();
        }
        else
        {
            while(sql_query.next())
            {
                Id=sql_query.value(0).toInt();
                user=sql_query.value(1).toString();
                job=sql_query.value(2).toString();
                sex2=sql_query.value(3).toString();
                qDebug()<<QString("ID:%1    Name:%2   Job:%3   Sex:%4").arg(Id).arg(user).arg(job).arg(sex2);
            }
        }

    }
    db.close();

}

void register1::on_cancel_bt_2_clicked()
{
    facial *f = new facial();
    f->show();
    this->close();
}
