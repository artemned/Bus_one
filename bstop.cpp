#include "bstop.h"
#include "ui_bstop.h"
#include <QTextCodec>
#include <QtDebug>
#include <QTextBrowser>

Bstop::Bstop(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Bstop)
{
    ui->setupUi(this);
    connect(ui->Show_bus,SIGNAL(clicked()),this,SLOT(ButtonSendBus()));//когда нажимаю на кнопку
    connect(ui->pushBtwo,SIGNAL(clicked()),this,SLOT(ButtonCloseBus()));//когда нажимаешь кнопку окно закрыввается
}

Bstop::~Bstop()
{
    delete ui;
}
void Bstop::ButtonSendBus()
{
    emit accep_bus(ui->line_bus->text());
    ui->line_bus->clear();
}

void Bstop::ButtonCloseBus()
{
    close();
}

void Bstop::reciver_bus(QString str)
{
     //qDebug()<<str;
     ui->textB->setText(str);
}


