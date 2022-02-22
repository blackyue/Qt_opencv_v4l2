#include "elabel.h"

ELabel::ELabel(QWidget * parent) : QLabel(parent)
{ }

//重写点击后弹开的事件处理函数
void ELabel::mouseReleaseEvent(QMouseEvent * ev)
{
    Q_UNUSED(ev);
    emit released();
}

//重写点击后弹开的事件处理函数
void ELabel::mousePressEvent(QMouseEvent * ev)
{
    Q_UNUSED(ev);
    emit pressed();
}

