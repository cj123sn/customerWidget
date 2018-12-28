#ifndef JSWITCHTITLE_H
#define JSWITCHTITLE_H

#include <QWidget>

class QHBoxLayout;
class QLabel;
class QPushButton;
class QPropertyAnimation;

class JSwitchTitle : public QWidget
{
    Q_OBJECT
public:
    explicit JSwitchTitle(QWidget *parent = 0);
    void addTitles(QStringList titles);

signals:

public slots:
    void slotTitleClicked();
private:
    QHBoxLayout* m_pHLayout;
    bool m_bDrawLine = false;
    QRect m_lineNew;
    QRect m_lineOld;
    QLabel* m_pLine;
    QList<QPushButton*> m_btns;
    QPropertyAnimation* m_pLabMv;
};

#endif // JSWITCHTITLE_H
