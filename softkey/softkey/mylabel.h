#ifndef MYLABEL_H
#define MYLABEL_H

#include <QWidget>

//#include <QWidget>
//#include <QMouseEvent>
//#include <QToolButton>
//#include <QKeyEvent>
//#include <QEvent>
//#include <QtDebug>
//#include <QLabel>



#include <QLabel>
#include <QEvent>
#include <QtDebug>
#include <QKeyEvent>
#include <QDateTime>
#include <QMouseEvent>
#include <QToolButton>
#include <QMessageBox>

class mylabel : public QLabel
{
    Q_OBJECT
public:
    explicit mylabel(QWidget *parent = Q_NULLPTR);

    bool event(QEvent *e) override
    {
        if(e->type() == QEvent :: MouseButtonPress){
            emit close_key();
            return true;
        }
        return QLabel::event(e);
    }

signals:

    void close_key();

};

#endif // MYLABEL_H
