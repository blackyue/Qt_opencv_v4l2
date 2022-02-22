#include "login_main.h"
#include "ui_login_main.h"

login_main::login_main(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login_main)
{

    ui->setupUi(this);

    QTimer  *timer_calender1;
    timer_calender1=new  QTimer(this);
    connect(timer_calender1,SIGNAL(timeout()),this,SLOT(timerupdate()));
    connect(timer_calender1,SIGNAL(timeout()),this,SLOT(timerupdate2()));
    timer_calender1->start(1000);
    ui->pwd_le->setStyleSheet("border-radius:7px;background-color:rgb(255,255,255);");
    ui->num1_button->setGeometry(220,260,58,58);
    ui->num1_button->setStyleSheet("border-radius:29px;");
    pwd.clear();

}

login_main::~login_main()
{
    delete ui;
}

void login_main::timerupdate()
{
    QDateTime time = QDateTime :: currentDateTime();
    QString str = time .toString(" hh    mm");
    ui->hm_label->setText(str);
    ui->hm_label->setStyleSheet("color:white;");
}

void login_main::timerupdate2()
{
    QDateTime time = QDateTime :: currentDateTime();
    QString str = time.toString("yyyy/MM/dd \ndddd");
    ui->yd_label->setText(str);
    ui->yd_label->setStyleSheet("color:white;");
}



void login_main::on_num1_button_clicked()
{

        pwd.append("1");
        ui->pwd_le->setText(pwd);

}

void login_main::on_num2_button_clicked()
{

        pwd.append("2");
        ui->pwd_le->setText(pwd);

}

void login_main::on_num3_button_clicked()
{

        pwd.append("3");
        ui->pwd_le->setText(pwd);

}


void login_main::on_delete_button_clicked()
{

        pwd=pwd.left(pwd.size()-1);
        ui->pwd_le->setText(pwd);

}

void login_main::on_num0_button_clicked()
{

        pwd.append("0");
        ui->pwd_le->setText(pwd);

}

void login_main::on_clear_button_clicked()
{


        pwd.clear();
        ui->pwd_le->clear();

}

void login_main::on_enter_button_clicked()
{
    if(pwd.isEmpty())
    {
        QMessageBox::warning(this,"出错提示","密码不能为空!");
        return ;
    }
    if(pwd=="000")
    {
        per_data *per=new per_data();
        per->show();
        this->close();
    }
    if(pwd=="123")
    {
          manager *m=new manager();
          m->show();
          this->close();
    }
    if(pwd!="000"&&pwd!="123")
    {
        QMessageBox::warning(this,"出错提示","不是正确密码!");
        return ;
    }

}

void login_main::on_return_button_3_clicked()
{
    facial *f = new facial();
    f->show();
    this->close();
}

void login_main::on_num4_button_clicked()
{
    pwd.append("4");
    ui->pwd_le->setText(pwd);

}

void login_main::on_num5_button_clicked()
{
    pwd.append("5");
    ui->pwd_le->setText(pwd);

}

void login_main::on_num6_button_clicked()
{
    pwd.append("6");
    ui->pwd_le->setText(pwd);

}

void login_main::on_num7_button_clicked()
{
    pwd.append("7");
    ui->pwd_le->setText(pwd);

}


void login_main::on_num8_button_clicked()
{
    pwd.append("8");
    ui->pwd_le->setText(pwd);

}

void login_main::on_num9_button_clicked()
{
    pwd.append("9");
    ui->pwd_le->setText(pwd);

}
