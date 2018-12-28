#include "JSwitchTitle.h"

#include <QHBoxLayout>
#include <QDebug>
#include <QPropertyAnimation>
#include <QLabel>
#include <QPushButton>

JSwitchTitle::JSwitchTitle(QWidget *parent) : QWidget(parent)
{
    m_pHLayout = new QHBoxLayout(this);
    qDebug()<<"w"<<this->width();
    qDebug()<<"h"<<this->height();
    m_pHLayout->setContentsMargins(20,9,20,9);
    m_pLine = new QLabel(this);
    m_pLine->setStyleSheet("background-color: rgb(55, 174, 254);");
    m_pLine->hide();
    m_pLabMv = new QPropertyAnimation(m_pLine,"geometry");
    //m_pLine->hide();

}

void JSwitchTitle::addTitles(QStringList titles)
{
    foreach(QString title,titles)
    {
        QPushButton* pBtn = new QPushButton(this);
        pBtn->setStyleSheet("QPushButton{color:rgb(68,68,68);font-size:17px;font-family:微软雅黑;border:none}"
                            "QPushButton:hover{color:rgb(40,143,231);}");
        pBtn->setText(title);
        pBtn->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
        connect(pBtn,&QPushButton::clicked,this,&JSwitchTitle::slotTitleClicked);
        m_pHLayout->addWidget(pBtn);
        m_btns.append(pBtn);
    }


}

void JSwitchTitle::slotTitleClicked()
{
    QPushButton* pBtn = dynamic_cast<QPushButton*>(sender());

    QPoint labTopLeft = pBtn->geometry().bottomLeft();

    QSize labSize;
    labSize.setWidth(pBtn->width());
    labSize.setHeight(3);

    m_pLabMv->stop();
    if(!m_pLine->isVisible())
    {
        m_pLine->resize(labSize);
        m_pLine->move(labTopLeft);
        m_lineNew = QRect(labTopLeft,labSize);
        m_lineOld = m_lineNew;
        m_pLine->show();
    }
    else
    {
        m_pLabMv->setDuration(500);
        m_lineNew = QRect(labTopLeft,labSize);
        m_pLabMv->setStartValue(m_lineOld);
        m_pLabMv->setEndValue(m_lineNew);
        m_pLabMv->setEasingCurve(QEasingCurve::OutBounce);  // 缓和曲线风格
        m_pLabMv->start();
        m_lineOld = m_lineNew;
    }
}

