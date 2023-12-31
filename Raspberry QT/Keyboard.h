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

    static Keyboard* getKeyboard();
    void activate(int type, QLineEdit *toEdit = nullptr, QPushButton *toClick = nullptr);
    void setType(int);
    void changeType();
    void changeKeys();

    // The copy constructor and assignment operator
    // are defined as deleted, which means that you
    // can't make a copy of singleton.
    Keyboard( Keyboard const& ) = delete;
    Keyboard& operator=( Keyboard const& ) = delete;

private:

    explicit Keyboard(QWidget *parent = nullptr);
    ~Keyboard();

private slots:

    void on_Q_clicked();

    void on_W_clicked();

    void on_BACKSPACE_clicked();

    void on_E_clicked();

    void on_R_clicked();

    void on_T_clicked();

    void on_Y_clicked();

    void on_U_clicked();

    void on_I_clicked();

    void on_O_clicked();

    void on_P_clicked();

    void on_A_clicked();

    void on_S_clicked();

    void on_D_clicked();

    void on_F_clicked();

    void on_G_clicked();

    void on_H_clicked();

    void on_J_clicked();

    void on_K_clicked();

    void on_L_clicked();

    void on_CAPS_clicked();

    void on_Z_clicked();

    void on_X_clicked();

    void on_C_clicked();

    void on_V_clicked();

    void on_B_clicked();

    void on_N_clicked();

    void on_M_clicked();

    void on_NUMERYCZNA_clicked();

    void on_PRZECINEK_clicked();

    void on_SPACE_clicked();

    void on_KROPKA_clicked();

    void on_ENTER_clicked();

private:
    Ui::Keyboard *ui;
    QPushButton *toClick;
    QLineEdit *toEdit;
    int type = 0;
    static Keyboard* instance;
public:
    static int ile;
};

#endif // KEYBOARD_H
