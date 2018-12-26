#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "window.h"
#include "sbus.h"
#include "bstop.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
   void retr(QString str);
public slots:
    void reception(QString str);
    void reception_two(QString str);
    void reception_three(QString str);
    void cl();



private slots:






    void on_actionShow_Bus_triggered();
    void on_actionAdd_Track_triggered();
 void on_actionShow_stop_triggered();



private:
    Ui::MainWindow *ui;
    Window * dig;//указатели для добавления
    Sbus *Sb;//указатель форм для остановок
    Bstop *Bs;//указатель форм для автобусов
    QString out_bus;//переменная для передачи в формы
    //переменная для передачи в форму
};

#endif // MAINWINDOW_H
