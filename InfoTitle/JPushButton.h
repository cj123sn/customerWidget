#ifndef JPUSHBUTTON_H
#define JPUSHBUTTON_H

#include <QPushButton>

class JPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit JPushButton(QWidget *parent = 0);

signals:
    void sigEnter();

public slots:

protected:
    virtual void enterEvent(QEvent* event) Q_DECL_OVERRIDE;

};

#endif // JPUSHBUTTON_H
