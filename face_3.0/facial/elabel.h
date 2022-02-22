#ifndef ELABEL_H
#define ELABEL_H

#include <QLabel>

class ELabel: public QLabel
{
    Q_OBJECT
public:
    ELabel(QWidget * parent = 0);

private:
protected:
    //重写点击后弹开的事件处理函数
    virtual void mouseReleaseEvent(QMouseEvent * ev);
    //重写点击压下去的事件处理函数
    virtual void mousePressEvent(QMouseEvent * ev);


signals:
    void released(void);
    void pressed(void);
};


#endif // ELABEL_H
