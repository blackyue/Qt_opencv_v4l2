#ifndef REGISTER1_H
#define REGISTER1_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <QString>
#include <QtSql>
#include <QLabel>
#include <QEvent>
#include <QtDebug>

#include <QKeyEvent>


#include <QMouseEvent>
#include <QToolButton>
#include <QMessageBox>
#include "facial.h"

namespace Ui {
class register1;
}

class register1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit register1(QWidget *parent = 0);
    ~register1();
    QString sex_check;
    bool eventFilter(QObject *watched, QEvent *event)override;

private:
    Ui::register1 *ui;

public slots:

    void timerupdate();
    void timerupdate2();
private slots:

    void on_boy_button_1_clicked();
    void on_employee_check_clicked();
    void on_girl_button_1_clicked();
    void on_cancel_bt_2_clicked();
    void hide_widget();
};

#endif // REGISTER1_H
