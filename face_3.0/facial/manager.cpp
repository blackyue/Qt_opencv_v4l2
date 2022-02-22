#include "manager.h"
#include "ui_manager.h"

manager *instance;
//通过建立自身类的指针，进行调用自身的成员函数，解决qt中普通函数无法调用界面中的控件的问题

/*
 *设置延迟函数
void sleep2(unsigned int msec)
{
    QTime reachTime = QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime() < reachTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
}
*/
//显示全部人员考勤信息函数
void show_all(){

    // 添加数据库--------------------------

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

    if(db.open()){

        QSqlQuery sql_query(db);
        QString select_sql=QString ("select * from member");
        sql_query.prepare(select_sql);

        if(!sql_query.exec())
        {
            qDebug()<<sql_query.lastError();
            qDebug()<<"select * from member failed!";
        }

        else{
            QMap<QString,int>ids;
            int i=0;
            int id;
            int k=-1,m=-1;   //计算行列
            QString name,post,sex;
            QTableWidgetItem *titem0,*titem1,*titem2,*titem3;//为某一行创建item



            while(sql_query.next())
            {
                ++k;
                id=sql_query.value(0).toInt();
                name=sql_query.value(1).toString();
                post=sql_query.value(2).toString();
                sex=sql_query.value(3).toString();
                qDebug()<<"id:"<<id<<" "<<"name:"<<name<<" "<<"post"<<post<<" "<<"sex:"<<sex<<endl;

                titem0 = new QTableWidgetItem;
                titem0->setText(name);
                titem0->setTextAlignment(Qt::AlignCenter); //文本居中显示
                manager::getinstance()->ui->attance_tw->setItem(k,++m,titem0);  //将item插入 QTableWidgetItem，坐标为第0行第0列

                titem1 = new QTableWidgetItem;
                titem1->setText(QString("%1").arg(id));
                titem1->setTextAlignment(Qt::AlignCenter); //文本居中显示
                manager::getinstance()->ui->attance_tw->setItem(k,++m,titem1);

                titem2 = new QTableWidgetItem;
                titem2->setText(post);
                titem2->setTextAlignment(Qt::AlignCenter); //文本居中显示
                manager::getinstance()->ui->attance_tw->setItem(k,++m,titem2);

                titem3 = new QTableWidgetItem;
                titem3->setText(sex);
                titem3->setTextAlignment(Qt::AlignCenter); //文本居中显示
                manager::getinstance()->ui->attance_tw->setItem(k,++m,titem3);

                m=-1;   //回到第一列准备重新遍历

                QString num = QString::number(id,10);  //将int类型转化为string类型，以十进制的方式
                qDebug()<<"id = "<<id;
                ids.insert(num,++i);


            }
            manager::getinstance()->ui->comboBox_1->clear();
            foreach (const QString &str,ids.keys()) {
                manager::getinstance()->ui->comboBox_1->addItem(str,ids.value(str));   //搜索记录将member表中有的编号放入下拉框中
            }
        }

        QString select_arrive=QString ("select * from arrive");
        sql_query.prepare(select_arrive);
        if(!sql_query.exec()){
            qDebug()<<sql_query.lastError();
            qDebug()<<"select * from arrive failed!";
        }
        else{
            int n=-1,j=3;  //计算行列
            double temperature;
            QString arrive_time;
            QTableWidgetItem *titem5,*titem6;

            while(sql_query.next()){
                ++n;
                temperature = sql_query.value(1).toDouble();
                arrive_time = sql_query.value(2).toString();

                titem5 = new QTableWidgetItem;
                titem5->setText(QString("%1").arg(temperature));
                titem5->setTextAlignment(Qt::AlignCenter); //文本居中显示
                manager::getinstance()->ui->attance_tw->setItem(n,++j,titem5);

                titem6 = new QTableWidgetItem;
                titem6->setText(arrive_time);
                titem6->setTextAlignment(Qt::AlignCenter); //文本居中显示
                manager::getinstance()->ui->attance_tw->setItem(n,++j,titem6);

                j=3;
            }
        }



    }

    db.close();
    //-----------------------------------

    //试验插入数据
    /*
    QMap<QString,int>id;
    id.insert("1001",1);
    id.insert("1002",2);
    id.insert("1003",3);
    id.insert("1004",4);

    ui->comboBox_1->clear();
    foreach (const QString &str,id.keys()) {
        ui->comboBox_1->addItem(str,id.value(str));
    }
    */
   //-------------------------------------------------------------------

}

manager::manager(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::manager)
{

    ui->setupUi(this);
    instance = this;
    //ui->main_tab->setStyleSheet("QTabBar::tab{width:150px;height:60px;}");
    ui->main_tab->setStyleSheet("QTabWidget::pane{border-top:0px;background:transparent;border:none;}\
                                    QTabBar::tab{width:190px;height:55px;background:transparent;margin-top:25px;}\
                                    QTabWidget::tab-bar{alignment:center;}");
   // ui->main_tab->setStyleSheet("QTabWidget::tab-bar{left:260px}");

     ui->attance_tw->setColumnCount(6);
     ui->attance_tw->setRowCount(8);
     QStringList header;
     header<<"姓名"<<"编号"<<"职务"<<"性别"<<"到达时间"<<"体温";
     ui->attance_tw->setHorizontalHeaderLabels(header);
     ui->attance_tw->horizontalHeader()->setStretchLastSection(true);   //设置表头充满表格的宽度
     ui->attance_tw->verticalHeader()->setVisible(false);   //设置垂直表头不可见
     ui->attance_tw->horizontalHeader()->setFixedHeight(48);    //设置表头高度
     ui->attance_tw->verticalHeader()->setDefaultSectionSize(45);   //设置每行高度
     ui->attance_tw->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);    //设置列间距相等

     ui->visit_tw->setColumnCount(5);
     ui->visit_tw->setRowCount(8);
     QStringList header_2;
     header_2<<"身份"<<"来访时间"<<"到达时间"<<"性别"<<"体温";
     ui->visit_tw->setHorizontalHeaderLabels(header_2);
     ui->visit_tw->horizontalHeader()->setStretchLastSection(true);   //设置表头充满表格的宽度
     ui->visit_tw->verticalHeader()->setVisible(false);   //设置垂直表头不可见
     ui->visit_tw->horizontalHeader()->setFixedHeight(48);    //设置表头高度
     ui->visit_tw->verticalHeader()->setDefaultSectionSize(45);   //设置每行高度
     ui->visit_tw->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);    //设置列间距相等

     show_all();
     //------------------------------------------------------------------

     // 添加数据库--------------------------
/*
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

     if(db.open()){

         QSqlQuery sql_query(db);
         QString select_sql=QString ("select * from member");
         sql_query.prepare(select_sql);

         if(!sql_query.exec())
         {
             qDebug()<<sql_query.lastError();
             qDebug()<<"select * from member failed!";
         }

         else{
             QMap<QString,int>ids;
             int i=0;
             int id;
             int k=-1,m=-1;   //计算行列
             QString name,post,sex;
             QTableWidgetItem *titem0,*titem1,*titem2,*titem3;//为某一行创建item



             while(sql_query.next())
             {
                 ++k;
                 id=sql_query.value(0).toInt();
                 name=sql_query.value(1).toString();
                 post=sql_query.value(2).toString();
                 sex=sql_query.value(3).toString();
                 qDebug()<<"id:"<<id<<" "<<"name:"<<name<<" "<<"post"<<post<<" "<<"sex:"<<sex<<endl;

                 titem0 = new QTableWidgetItem;
                 titem0->setText(name);
                 titem0->setTextAlignment(Qt::AlignCenter); //文本居中显示
                 ui->attance_tw->setItem(k,++m,titem0);  //将item插入 QTableWidgetItem，坐标为第0行第0列

                 titem1 = new QTableWidgetItem;
                 titem1->setText(QString("%1").arg(id));
                 titem1->setTextAlignment(Qt::AlignCenter); //文本居中显示
                 ui->attance_tw->setItem(k,++m,titem1);

                 titem2 = new QTableWidgetItem;
                 titem2->setText(post);
                 titem2->setTextAlignment(Qt::AlignCenter); //文本居中显示
                 ui->attance_tw->setItem(k,++m,titem2);

                 titem3 = new QTableWidgetItem;
                 titem3->setText(sex);
                 titem3->setTextAlignment(Qt::AlignCenter); //文本居中显示
                 ui->attance_tw->setItem(k,++m,titem3);

                 m=-1;   //回到第一列准备重新遍历

                 QString num = QString::number(id,10);  //将int类型转化为string类型，以十进制的方式
                 qDebug()<<"id = "<<id;
                 ids.insert(num,++i);


             }
             ui->comboBox_1->clear();
             foreach (const QString &str,ids.keys()) {
                 ui->comboBox_1->addItem(str,ids.value(str));   //搜索记录将member表中有的编号放入下拉框中
             }
         }

         QString select_arrive=QString ("select * from arrive");
         sql_query.prepare(select_arrive);
         if(!sql_query.exec()){
             qDebug()<<sql_query.lastError();
             qDebug()<<"select * from arrive failed!";
         }
         else{
             int n=-1,j=3;  //计算行列
             double temperature;
             QString arrive_time;
             QTableWidgetItem *titem5,*titem6;

             while(sql_query.next()){
                 ++n;
                 temperature = sql_query.value(1).toDouble();
                 arrive_time = sql_query.value(2).toString();

                 titem5 = new QTableWidgetItem;
                 titem5->setText(QString("%1").arg(temperature));
                 titem5->setTextAlignment(Qt::AlignCenter); //文本居中显示
                 ui->attance_tw->setItem(n,++j,titem5);

                 titem6 = new QTableWidgetItem;
                 titem6->setText(arrive_time);
                 titem6->setTextAlignment(Qt::AlignCenter); //文本居中显示
                 ui->attance_tw->setItem(n,++j,titem6);

                 j=3;
             }
         }



     }

     db.close();
     //-----------------------------------

     //试验插入数据
     /*
     QMap<QString,int>id;
     id.insert("1001",1);
     id.insert("1002",2);
     id.insert("1003",3);
     id.insert("1004",4);

     ui->comboBox_1->clear();
     foreach (const QString &str,id.keys()) {
         ui->comboBox_1->addItem(str,id.value(str));
     }
     */
    //-------------------------------------------------------------------




}
manager::~manager()
{
    delete ui;
}

void manager::on_return_button_1_clicked()
{
    login_main *l = new login_main();
    l->show();
    this->close();
}

void manager::on_return_button_2_clicked()
{
    login_main *l = new login_main();
    l->show();
    this->close();
}

void manager::on_return_button_3_clicked()
{
    login_main *l = new login_main();
    l->show();
    this->close();
}

void manager::on_check_bt_clicked()
{
    int id;
    QString name;
    QString post;
    QString sex;
    QTableWidgetItem *titem0,*titem1,*titem2,*titem3;//为某一行创建item

    ui->attance_tw->clear();
    id = ui->comboBox_1->currentText().toInt();

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

    if(db.open()){

        QSqlQuery sql_query(db);
        QString select_sql=QString ("select * from member where id = %1").arg(id);
        sql_query.prepare(select_sql);

        if(!sql_query.exec())
        {
            qDebug()<<sql_query.lastError();
            qDebug()<<"select * from member failed!";
        }

        else{

            while(sql_query.next())
            {
                name=sql_query.value(1).toString();
                post=sql_query.value(2).toString();
                sex=sql_query.value(3).toString();
                qDebug()<<"id:"<<id<<" "<<"name:"<<name<<" "<<"post"<<post<<" "<<"sex:"<<sex<<endl;

                titem0 = new QTableWidgetItem;
                titem0->setText(name);
                titem0->setTextAlignment(Qt::AlignCenter); //文本居中显示
                ui->attance_tw->setItem(0,0,titem0);  //将item插入 QTableWidgetItem，坐标为第0行第0列

                titem1 = new QTableWidgetItem;
                titem1->setText(QString("%1").arg(id));
                titem1->setTextAlignment(Qt::AlignCenter); //文本居中显示
                ui->attance_tw->setItem(0,1,titem1);

                titem2 = new QTableWidgetItem;
                titem2->setText(post);
                titem2->setTextAlignment(Qt::AlignCenter); //文本居中显示
                ui->attance_tw->setItem(0,2,titem2);

                titem3 = new QTableWidgetItem;
                titem3->setText(sex);
                titem3->setTextAlignment(Qt::AlignCenter); //文本居中显示
                ui->attance_tw->setItem(0,3,titem3);

            }
            if(!sql_query.exec())
            {
                qDebug()<<QObject::tr("Table member Create failed!");
                qDebug()<<sql_query.lastError();
            }
            else
            {
                qDebug()<<"Table member Created!";
            }


        }

        QString select_arrive=QString ("select * from arrive where id =  %1").arg(id);
        sql_query.prepare(select_arrive);
        if(!sql_query.exec()){
            qDebug()<<sql_query.lastError();
            qDebug()<<"select * from arrive failed!";
        }
        else{

            double temperature;
            QString arrive_time;
            QTableWidgetItem *titem5,*titem6;

            if(!sql_query.exec())
            {
                qDebug()<<QObject::tr("Table member Create failed!");
                qDebug()<<sql_query.lastError();
            }
            else
            {
                qDebug()<<"Table member Created!";
            }

            while(sql_query.next()){

                temperature = sql_query.value(1).toDouble();
                arrive_time = sql_query.value(2).toString();

                titem5 = new QTableWidgetItem;
                titem5->setText(QString("%1").arg(temperature));
                titem5->setTextAlignment(Qt::AlignCenter); //文本居中显示
                ui->attance_tw->setItem(0,4,titem5);

                titem6 = new QTableWidgetItem;
                titem6->setText(arrive_time);
                titem6->setTextAlignment(Qt::AlignCenter); //文本居中显示
                ui->attance_tw->setItem(0,5,titem6);


            }
        }



    }

    db.close();
}


manager* manager::getinstance()
{

    return instance;
}
void manager::on_all_bt_clicked()
{
    show_all();
}
