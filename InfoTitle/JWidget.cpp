#include "JWidget.h"
#include <QPainter>
#include <QDebug>
#include <QSvgRenderer>

JWidget::JWidget(QWidget *parent)
    : QWidget(parent)
    , m_bPress(false)
    , m_bEnable(true)
    , m_sIconPath("")
    , m_nRotate(0)
    , m_nIconSize(20)
    , m_sLeftBorderColor("")
    , m_sRightBorderColor("")
    , m_sTopBorderColor("")
    , m_sBottomBorderColor("")
    , m_sBackgroundColor("")
{

}

void JWidget::setIconPath(QString sPath)
{
    m_sIconPath = sPath;
    if(m_sIconPath.endsWith(".svg"))
        m_bSvgPic = true;
    else
        m_bSvgPic = false;
    updateWidget();
}

void JWidget::setRotate(int nRotate)
{
    m_nRotate = nRotate;
}

void JWidget::setIconSize(int nSize)
{
    m_nIconSize = nSize;
    update();
}

void JWidget::setBorderColor(QString sLeftColor, QString sRightColor, QString sTopColor, QString sBottomColor)
{
    m_sLeftBorderColor = sLeftColor;
    m_sRightBorderColor = sRightColor;
    m_sTopBorderColor = sTopColor;
    m_sBottomBorderColor = sBottomColor;
}

void JWidget::setLeftRightBorderColor(QString sLeftColor, QString sRightColor)
{
    m_sLeftBorderColor = sLeftColor;
    m_sRightBorderColor = sRightColor;
}

void JWidget::setTopBottomColor(QString sTopColor, QString sBottomColor)
{
    m_sTopBorderColor = sTopColor;
    m_sBottomBorderColor = sBottomColor;
}

void JWidget::setLeftBorderColor(QString sColor)
{
    m_sLeftBorderColor = sColor;
}

void JWidget::setRightBorderColor(QString sColor)
{
    m_sRightBorderColor = sColor;
}

void JWidget::setTopBorderColor(QString sColor)
{
    m_sTopBorderColor = sColor;
}

void JWidget::setBottomBorderColor(QString sColor)
{
    m_sBottomBorderColor = sColor;
}

void JWidget::clearBorderColor()
{
    m_sLeftBorderColor = "";
    m_sRightBorderColor = "";
    m_sTopBorderColor = "";
    m_sBottomBorderColor = "";
    update();
}

void JWidget::updateWidget()
{
    update();
}

void JWidget::setIconEnable(bool bEnable)
{
    m_bEnable = bEnable;
}

void JWidget::setIconPressState(bool bPress)
{
    m_bPress = bPress;
}

void JWidget::setBackgroundColor(QString sColor)
{
    m_sBackgroundColor = sColor;
}

void JWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);
    if (m_bEnable)
    {
        painter.setOpacity(m_bPress ? 0.5 : 1.0); // 设置透明度
    }
    else
    {
        painter.setOpacity(0.2); // 设置透明度
    }

    if (!m_sBackgroundColor.isEmpty())
    {
        painter.setPen(QPen(QColor(m_sBackgroundColor)));
        painter.setBrush(QBrush(QColor(m_sBackgroundColor)));
        painter.drawRect(0, 0, this->rect().width()-1, this->rect().height()-1);
    }

    if (m_nRotate > 0)
    {
        QTransform transform;
        transform.translate(this->width()/2, this->height()/2); //把中心点移动到 50，50
        transform.rotate(m_nRotate); //旋转45度
        transform.translate(-this->width()/2, -this->height()/2);//把中心点设置回默认的位置
        painter.save();
        painter.setWorldTransform(transform);
    }

    if(m_bSvgPic)
    {
        QSvgRenderer svgRender;
        svgRender.load(m_sIconPath);
        svgRender.render(&painter ,QRectF((this->width() - m_nIconSize)/2,(this->height() - m_nIconSize)/2,m_nIconSize ,m_nIconSize));
    }
    else
    {
        QPixmap pic;
        pic.load(m_sIconPath);
        painter.drawPixmap(QRect((this->width() - m_nIconSize)/2,(this->height() - m_nIconSize)/2,m_nIconSize ,m_nIconSize),m_sIconPath);
    }


    if (m_nRotate > 0)
    {
        painter.restore();
    }

    painter.setOpacity(1);
    int nPenWidth = 1;
    int nOff = 1; // 偏移量
    if (!m_sLeftBorderColor.isEmpty())
    {
        QPen pen;
        pen.setWidth(nPenWidth);
        pen.setColor(m_sLeftBorderColor);
        painter.setPen(pen);
        painter.drawLine(0,nOff,0,this->height()-2*nOff);
    }
    if (!m_sRightBorderColor.isEmpty())
    {
        QPen pen;
        pen.setWidth(nPenWidth);
        pen.setColor(m_sRightBorderColor);
        painter.setPen(pen);
        painter.drawLine(this->width()-nPenWidth,nOff,this->width()-nPenWidth,this->height()-2*nOff);
    }
    if (!m_sTopBorderColor.isEmpty())
    {
        QPen pen;
        pen.setWidth(nPenWidth);
        pen.setColor(m_sTopBorderColor);
        painter.setPen(pen);
        painter.drawLine(0,0,this->width(),0);
    }
    if (!m_sBottomBorderColor.isEmpty())
    {
        QPen pen;
        pen.setWidth(nPenWidth);
        pen.setColor(m_sBottomBorderColor);
        painter.setPen(pen);
        painter.drawLine(nPenWidth,this->height()-nPenWidth,this->width(),this->height()-nPenWidth);
    }
}

void JWidget::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
    m_bPress = true;
    update();
}

void JWidget::mouseReleaseEvent(QMouseEvent *event)
{
    QWidget::mouseReleaseEvent(event);
    m_bPress = false;
    update();
    if (m_bEnable)
    {
        emit sigIconClick();
    }
}
