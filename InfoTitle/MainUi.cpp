#include "MainUi.h"
#include "ui_MainUi.h"

MainUi::MainUi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainUi)
{
    ui->setupUi(this);
    QStringList titles;
    titles<<"标题1"<<"标题2"<<"标题3"<<"标题4";
    ui->widget->addTitles(titles);
}

MainUi::~MainUi()
{
    delete ui;
}
