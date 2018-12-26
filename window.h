#ifndef WINDOW_H
#define WINDOW_H

#include <QDialog>

namespace Ui {
class Window;
}

class Window : public QDialog
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = nullptr);
    ~Window();
signals:
    void acception(QString str);
    void quit();

private slots:
    void ButtonSend();
    void ButtonClose();

private:
    Ui::Window *ui;
};

#endif // WINDOW_H
