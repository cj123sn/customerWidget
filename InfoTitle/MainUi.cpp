#include "MainUi.h"
#include "ui_MainUi.h"

MainUi::MainUi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainUi)
{
    ui->setupUi(this);
    ui->widget->setIconSize(64);
    ui->widget->setIconPath(":/res/png/4.jpg");
}

MainUi::~MainUi()
{
    delete ui;
}
