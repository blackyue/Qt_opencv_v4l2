#include "softkey.h"
#include "mylabel.h"
#include "ui_softkey.h"

softkey::softkey(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::softkey)
{

    ui->setupUi(this);

    ui->myWidget->hide();

     //给QLineEdit控件安装事件过滤器
        //QObject::installEventFilter()允许对象拦截指向另一个对象的事件。
    ui->userEdit->installEventFilter(this);
    ui->passwordEdit->installEventFilter(this);
   

    connect(ui->backgroundlabel,&mylabel::close_key,this,&softkey::hide_widget);


}
void softkey::hide_widget()
{
    ui->myWidget->hide();
}
bool softkey::eventFilter(QObject *watched, QEvent *event)
{

    if ( (watched == ui->userEdit) && (event->type() == QEvent::MouseButtonPress) )
    {
        ui->myWidget->show();
        ui->userEdit->setFocus();
    }
    else if ( (watched == ui->passwordEdit) && (event->type() == QEvent::MouseButtonPress) )
    {
        ui->myWidget->show();
        ui->passwordEdit->setFocus();
    }

    return QMainWindow::eventFilter(watched,event);
}

softkey::~softkey()
{
    delete ui;
}
