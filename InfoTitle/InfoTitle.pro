#-------------------------------------------------
#
# Project created by QtCreator 2018-12-27T17:15:40
#
#-------------------------------------------------

QT       += core gui
QT	 += svg
CONFIG	 += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = InfoTitle
TEMPLATE = app


SOURCES += main.cpp\
        MainUi.cpp \
    JWidget.cpp

HEADERS  += MainUi.h \
    JWidget.h

FORMS    += MainUi.ui

RESOURCES += \
    res.qrc
