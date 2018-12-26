#include "windowshowbus.h"
#include "ui_windowshowbus.h"

WindowShowBus::WindowShowBus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowShowBus)
{
    ui->setupUi(this);
     connect(ui->show,SIGNAL(clicked()),this,SLOT(ButtonSend()));
}

WindowShowBus::~WindowShowBus()
{
    delete ui;
}

void WindowShowBus::ButtonSend()
{
    emit accep(ui->line_->text());
    ui->line_->clear();
}

void WindowShowBus::recep(QString str)
{
    ui->textEdit->setText(str);
}
