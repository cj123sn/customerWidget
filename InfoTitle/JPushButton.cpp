#include "JPushButton.h"

JPushButton::JPushButton(QWidget *parent) : QPushButton(parent)
{
    this->setFlat(true);
}

void JPushButton::enterEvent(QEvent *event)
{
    QPushButton::enterEvent(event);
    emit sigEnter();
}

