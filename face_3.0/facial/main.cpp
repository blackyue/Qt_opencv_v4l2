#include "facial.h"
#include <QApplication>
#include <QtSql>
#include <QDebug>
#include <QTime>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QString create_sql_member="create table if not exists member (id int primary key,name varchar(30),post varchar(30),sex varchar(20))";

    QString create_sql_arrive="create table if not exists arrive(id int primary key,temperature double ,arrive_time varchar(70))";



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
        int id = 1004;
        QSqlQuery sql_query(db);

        sql_query.prepare(create_sql_member);
        if(!sql_query.exec())
        {
            qDebug()<<QObject::tr("Table member Create failed!");
            qDebug()<<sql_query.lastError();
        }
        else
        {
            qDebug()<<"Table member Created!";
        }

        sql_query.prepare(create_sql_arrive);
        if(!sql_query.exec())
        {
            qDebug()<<"Table arrive Create failed!";
        }
        else
        {
            qDebug()<<"Table arrive Created!";
        }


        QString select_all_sql="select * from member";

        /*

        QString delete_sql = "delete from arrive where id = ?";
        sql_query.prepare(delete_sql);
        sql_query.addBindValue(id);
        if(!sql_query.exec()){
             qDebug()<<sql_query.lastError();
        }
        else{
               qDebug()<<"deleted!";
        }



        QString delete_member_sql = "delete from member where id = ?";
        sql_query.prepare(delete_member_sql);
        sql_query.addBindValue(id);
        if(!sql_query.exec()){
             qDebug()<<sql_query.lastError();
        }
        else{
               qDebug()<<"deleted!";
        }

        */

        /*
        int id=1004;
        QString name="qiuqiu";
        QString post="master";
        QString sex="man";



        QString insert_sql="insert into member values(?,?,?,?)";


        sql_query.prepare(insert_sql);

        QVariantList GroupIDS;
        GroupIDS.append(id);

        QVariantList GroupNameS;
        GroupNameS.append(name);

        QVariantList GroupPostS;
        GroupPostS.append(post);

        QVariantList GroupSexS;
        GroupSexS.append(sex);

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

        */

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

    facial w;
    w.show();

    return a.exec();
}
