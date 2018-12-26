#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bus.h"
#include "bus_manager.h"
#include <QtWidgets>
#include <QString>
#include <string>
#include <sstream>
#include <utility>
#include <QLabel>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QTextEdit>
//#include <QtDebug>
#include <QTextEdit>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    setWindowTitle("Bus Manager");
    QPixmap pixed(":/prefix/img/bus.jpg" );
    QPalette palser;
   palser.setBrush(backgroundRole(),QBrush(QPixmap(":/prefix/img/bus.jpg")));
    setPalette(palser);
    setAutoFillBackground(true);
    resize(pixed.size());
    setFixedSize(pixed.size());
     setWindowFlags(Qt::Window );

}

MainWindow::~MainWindow()
{
    delete ui;
}


//static QString out_bus;
static Query q;
static ifstream file("C:/developersQt/project/Bus_one/exe.txt");
static BusManager bm(file);


void add_(QString& s)
{
    string str=s.toStdString();
    istringstream d(str);//вывели всю строку в поток.
    d>>q.bus;
    d>>q.stop;
     q.time_bus.clear();
    //will be default one stop
    while(!d.eof())
    {
       d>>q.time;
       q.time_bus.push_back(q.time);

    }
       //int count=find_space(q.time);//колличество остановок
    q.stops.clear();


        q.stops.push_back({q.stop,q.time_bus});
       //chislo_ostanovok--;
    //}
    bm.AddBus(q.bus,q.stops);//добавили наш автобус и его маршруты.


}
void remove(QString& rem) // method for remove route
{
    string st=rem.toStdString();
    stringstream s(std::move(st));
    string bus;
    string stop;
    s>>bus>>stop;

//    bm.Delete(bus,stop);

}
void MainWindow::reception(QString str)
{
    add_(str);
}

void MainWindow::reception_two(QString str)
{

    string stopss=str.toStdString();
    ostringstream os;
    os<<bm.GetBusesForStop(std::move(stopss));
    auto a=(os.str());
    out_bus=QString::fromStdString(a);
    emit retr(out_bus);
  //  qDebug()<<out_bus;

}
void MainWindow::reception_three(QString str)
{

    string buss=str.toStdString();
    ostringstream os;
    os<<bm.GetStopsForBus(std::move(buss));
    auto a=(os.str());
    out_bus=QString::fromStdString(a);
    emit retr(out_bus);
    //qDebug()<<out_bus;

}
void MainWindow::cl()
{
  QApplication::quit();
}

void MainWindow::on_actionAdd_Track_triggered()
{
    dig=new Window(this);
    dig->setWindowTitle("Add bus and stop");
    QPixmap pixell(":/prefix/img/forbus.jpg" );
    QPalette palls;
   palls.setBrush(dig->backgroundRole(),QBrush(QPixmap(":/prefix/img/bf.jpg")));
    dig->setPalette(palls);
    dig->setAutoFillBackground(true);
    dig->resize(pixell.size());
    dig->setFixedSize(pixell.size());
    dig->setWindowFlags(Qt::Window);

  // work: open window for add
    connect(dig,SIGNAL(acception(QString)),this,SLOT(reception(QString))); //receptoin function from doughter class
    connect(dig,SIGNAL(quit()),this,SLOT(cl()));

    dig->exec();

}

void MainWindow::on_actionShow_Bus_triggered()
{


       Sb=new Sbus(this);
       Sb->setWindowTitle("Show Buses throughewt stop");
       QPixmap pix(":/prefix/img/forbus.jpg" );
       QPalette pal;
      pal.setBrush(Sb->backgroundRole(),QBrush(QPixmap(":/prefix/img/forbus.jpg")));
       Sb->setPalette(pal);
       Sb->setAutoFillBackground(true);
       Sb->resize(pix.size());
       Sb->setFixedSize(pix.size());
        Sb->setWindowFlags(Qt::Window );//if add flags to end,that all work.
      // Sb->show();

 connect(Sb,SIGNAL(accep(QString)),this,SLOT(reception_two(QString)));//соединяем сигнал для вызова метода
            //getbusesforstop
 connect(this,SIGNAL(retr(QString)),Sb,SLOT(reciver(QString)));//отправляем полученное обратно
 connect(Sb,SIGNAL(quit()),this,SLOT(cl()));
    Sb->exec();
}

void MainWindow::on_actionShow_stop_triggered()
{



       Bs=new Bstop(this);
       Bs->setWindowTitle("Show Stops for Bus");
       QPixmap pixel(":/prefix/img/forbus.jpg" );
       QPalette pall;
      pall.setBrush(Bs->backgroundRole(),QBrush(QPixmap(":/prefix/img/forbus.jpg")));
       Bs->setPalette(pall);
       Bs->setAutoFillBackground(true);
       Bs->resize(pixel.size());
       Bs->setFixedSize(pixel.size());
       Bs->setWindowFlags(Qt::Window);



 connect(Bs,SIGNAL(accep_bus(QString)),this,SLOT(reception_three(QString)));//соединяем сигнал для вызова метода
            //getbusesforstop
 connect(this,SIGNAL(retr(QString)),Bs,SLOT(reciver_bus(QString)));//отправляем полученное обратно
  //connect(Bs,SIGNAL(quit_bus()),this,SLOT(cl()));
         Bs->exec();
}








