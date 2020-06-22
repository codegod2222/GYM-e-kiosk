#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QDialog>
#include <QLineEdit>

namespace Ui {
class Keyboard;
}

class Keyboard : public QDialog
{
    Q_OBJECT

public:
    explicit Keyboard(QWidget *parent = nullptr);
    ~Keyboard();

    void activate(QLineEdit *toEdit = nullptr);

private slots:

    void on_Q_clicked();

    void on_W_clicked();

    void on_BACKSPACE_clicked();

private:
    Ui::Keyboard *ui;
    QLineEdit *toEdit;
};

#endif // KEYBOARD_H
