/********************************************************************************
** Form generated from reading UI file 'MainUi.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINUI_H
#define UI_MAINUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "SwitchTitle/JSwitchTitle.h"

QT_BEGIN_NAMESPACE

class Ui_MainUi
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    JSwitchTitle *widget;

    void setupUi(QWidget *MainUi)
    {
        if (MainUi->objectName().isEmpty())
            MainUi->setObjectName(QStringLiteral("MainUi"));
        MainUi->resize(905, 551);
        MainUi->setFocusPolicy(Qt::StrongFocus);
        MainUi->setStyleSheet(QStringLiteral(""));
        pushButton = new QPushButton(MainUi);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(80, 280, 75, 23));
        pushButton_2 = new QPushButton(MainUi);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(80, 320, 75, 23));
        widget = new JSwitchTitle(MainUi);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(300, 180, 401, 101));
        widget->setStyleSheet(QLatin1String("QWidget#widget{\n"
"	border:2px solid red;\n"
"}"));

        retranslateUi(MainUi);

        QMetaObject::connectSlotsByName(MainUi);
    } // setupUi

    void retranslateUi(QWidget *MainUi)
    {
        MainUi->setWindowTitle(QApplication::translate("MainUi", "MainUi", 0));
        pushButton->setText(QApplication::translate("MainUi", "PushButton", 0));
        pushButton_2->setText(QApplication::translate("MainUi", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class MainUi: public Ui_MainUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINUI_H
