#ifndef PER_DATA_H
#define PER_DATA_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <QString>
#include <QDebug>
#include <QLabel>
#include "login_main.h"

namespace Ui {
class per_data;
}

class per_data : public QMainWindow
{
    Q_OBJECT

public:
    explicit per_data(QWidget *parent = 0);
    ~per_data();

private:
    Ui::per_data *ui;
public slots:

    void timerupdate();
    void timerupdate2();
private slots:
    void on_return_button_clicked();
    void on_select_button_clicked();
};

#endif // PER_DATA_H
