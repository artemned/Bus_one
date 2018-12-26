#include "windowshowstop.h"
#include "ui_windowshowstop.h"

WindowShowStop::WindowShowStop(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowShowStop)
{
    ui->setupUi(this);
}

WindowShowStop::~WindowShowStop()
{
    delete ui;
}
