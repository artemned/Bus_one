#include <QTextCodec>
#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include "bus.h"
#include "bus_manager.h"
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    //w.setFixedSize(918, 618);
      //QBrush br(Qt::TexturePattern);
        //br.setTextureImage(QImage(":/prefix/img/bus.jpg"));
        //QPalette plt = w.palette();
        //plt.setBrush(QPalette::Background, br);
        //w.setPalette(plt);
   // w.sizeIncrement();


    w.show();

    return a.exec();
}
