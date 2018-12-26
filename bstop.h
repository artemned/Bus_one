#ifndef BSTOP_H
#define BSTOP_H

#include <QDialog>

namespace Ui {
class Bstop;
}

class Bstop : public QDialog
{
    Q_OBJECT

public:
    explicit Bstop(QWidget *parent = nullptr);
    ~Bstop();

signals:
void accep_bus(QString str);
void quit_bus();
public slots:
void reciver_bus(QString);

private slots:
void ButtonSendBus();
void ButtonCloseBus();

private:
    Ui::Bstop *ui;
};

#endif // BSTOP_H
