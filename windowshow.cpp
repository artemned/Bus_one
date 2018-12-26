#include "windowshow.h"
#include "ui_windowshow.h"

WindowShow::WindowShow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowShow)
{
    ui->setupUi(this);
}

WindowShow::~WindowShow()
{
    delete ui;
}
