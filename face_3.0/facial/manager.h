#ifndef MANAGER_H
#define MANAGER_H

#include <QMainWindow>
#include "login_main.h"

namespace Ui {
class manager;
}

class manager : public QMainWindow
{
    Q_OBJECT

public:
    explicit manager(QWidget *parent = 0);
    Ui::manager *ui;
    static manager* getinstance();
    ~manager();

private slots:
    void on_return_button_1_clicked();

    void on_return_button_2_clicked();

    void on_return_button_3_clicked();

    void on_check_bt_clicked();

    void on_all_bt_clicked();



};

#endif // MANAGER_H
