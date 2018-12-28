#ifndef JWIDGET_H
#define JWIDGET_H

#include <QWidget>

class JWidget : public QWidget
{
    Q_OBJECT
public:
    explicit JWidget(QWidget *parent = 0);

    void setIconPath(QString sPath); // 设置icon路径 用了update
    void setRotate(int nRotate); // 设置图标旋转角度
    void setIconSize(int nSize);
    void setBorderColor(QString sLeftColor = "", QString sRightColor = "", QString sTopColor = "", QString sBottomColor = "");
    void setLeftRightBorderColor(QString sLeftColor = "", QString sRightColor = "");
    void setTopBottomColor(QString sTopColor = "", QString sBottomColor = "");
    void setLeftBorderColor(QString sColor);
    void setRightBorderColor(QString sColor);
    void setTopBorderColor(QString sColor);
    void setBottomBorderColor(QString sColor);
    void clearBorderColor();
    void updateWidget();
    void setIconEnable(bool bEnable);
    void setIconPressState(bool bPress);
    void setBackgroundColor(QString sColor);

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

signals:
    void sigIconClick();

private:
    bool m_bPress;
    bool m_bEnable;
    QString m_sIconPath;
    int m_nRotate; // 旋转角度
    int m_nIconSize;
    QString m_sLeftBorderColor;
    QString m_sRightBorderColor;
    QString m_sTopBorderColor;
    QString m_sBottomBorderColor;
    QString m_sBackgroundColor;
    bool m_bSvgPic = false;
};

#endif // JWIDGET_H
