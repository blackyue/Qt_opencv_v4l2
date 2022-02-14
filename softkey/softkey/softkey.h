#ifndef SOFTKEY_H
#define SOFTKEY_H

#include <QMainWindow>



#include <QLabel>
#include <QEvent>
#include <QtDebug>

#include <QKeyEvent>


#include <QMouseEvent>
#include <QToolButton>
#include <QMessageBox>




namespace Ui {
class softkey;
}

class softkey : public QMainWindow
{
    Q_OBJECT

public:
    explicit softkey(QWidget *parent = 0);
    ~softkey();

    bool eventFilter(QObject *watched, QEvent *event)override;

private:
    Ui::softkey *ui;
private slots:
     void hide_widget();
};


#endif // SOFTKEY_H
