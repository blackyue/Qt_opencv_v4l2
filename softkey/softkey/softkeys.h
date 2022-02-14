#ifndef SOFTKEYS_H
#define SOFTKEYS_H

#include <QWidget>
#include <QLabel>
#include <QEvent>
#include <QtDebug>
#include <QProcess>
#include <QKeyEvent>
#include <QDateTime>
#include <QMouseEvent>
#include <QToolButton>
#include <QMessageBox>









class softkeys : public QToolButton
{
    Q_OBJECT
public:
    explicit softkeys(QWidget *parent = Q_NULLPTR);



public slots:
     void button_clicked(bool);
};

#endif // SOFTKEYS_H
