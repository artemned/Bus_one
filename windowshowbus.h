#ifndef WINDOWSHOWBUS_H
#define WINDOWSHOWBUS_H

#include <QDialog>

namespace Ui {
class WindowShowBus;
}

class WindowShowBus : public QDialog
{
    Q_OBJECT

public:
    explicit WindowShowBus(QWidget *parent = nullptr);
    ~WindowShowBus();
signals:
    void accep(QString str);//сигнал для отправки строки

private slots:
    void ButtonSend();
    void recep(QString str);

private:
    Ui::WindowShowBus *ui;
};

#endif // WINDOWSHOWBUS_H
