#ifndef ADDOREDITPASSSCREEN_H
#define ADDOREDITPASSSCREEN_H

#include <QDialog>
#include "Keyboard.h"
#include "Pass.h"

namespace Ui {
class AddOrEditPassScreen;
}

class AddOrEditPassScreen : public QDialog
{
    Q_OBJECT

public:
    explicit AddOrEditPassScreen(QWidget *parent = nullptr, Pass *toEdit = nullptr, std::vector<Pass> *karnety = nullptr);
    ~AddOrEditPassScreen();

    bool eventFilter(QObject*, QEvent*);

    void mousePressEvent(QMouseEvent*);

private slots:
    void on_powrot_clicked();

    void on_zatwierdz_clicked();

private:
    Ui::AddOrEditPassScreen *ui;
    Keyboard *keyboard;
    Pass *toEdit;
    std::vector<Pass> *karnety;
    //KodokanDAO *kodokanDAO;
};

#endif // ADDOREDITPASSSCREEN_H
