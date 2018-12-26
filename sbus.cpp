#include "sbus.h"
#include "ui_sbus.h"

Sbus::Sbus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sbus)
 {
    ui->setupUi(this);

    connect(ui->Show_,SIGNAL(clicked()),this,SLOT(ButtonSend()));//когда нажимаю на кнопку
    connect(ui->push,SIGNAL(clicked()),this,SLOT(ButtonClose()));
}

Sbus::~Sbus()
{
    delete ui;
}
void Sbus::ButtonSend()
{
    emit accep(ui->line_->text());
    ui->line_->clear();
}

void Sbus::ButtonClose()
{
    close();
}

void Sbus::reciver(QString str)
{
    ui->sh->setText(str);

}
