#ifndef SBUS_H
#define SBUS_H

#include <QDialog>

namespace Ui {
class Sbus;
}

class Sbus : public QDialog
{
    Q_OBJECT

public:
    explicit Sbus(QWidget *parent = nullptr);
    ~Sbus();
    signals:
    void accep(QString str);
    void quit();
public slots:
    void reciver(QString);

private slots:
    void ButtonSend();
    void ButtonClose();



private:
    Ui::Sbus *ui;
};

#endif // SBUS_H
