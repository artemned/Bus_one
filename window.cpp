#include "window.h"
#include "ui_window.h"

Window::Window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);

    connect(ui->pushBone,SIGNAL(clicked()),this,SLOT(ButtonSend()));
    connect(ui->pushBtwo,SIGNAL(clicked()),this,SLOT(ButtonClose()));
}

Window::~Window()
{
    delete ui;
}

void Window::ButtonSend()
{
    emit acception(ui->lineEone->text());
    ui->lineEone->clear();
}

void Window::ButtonClose()
{
    close();
}
