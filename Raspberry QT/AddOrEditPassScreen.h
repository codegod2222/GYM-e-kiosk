#ifndef ADDOREDITPASSSCREEN_H
#define ADDOREDITPASSSCREEN_H

#include <QDialog>
#include "Keyboard.h"
#include "../databse_access/KodokanDAO.h"

namespace Ui {
class AddOrEditPassScreen;
}

class AddOrEditPassScreen : public QDialog
{
    Q_OBJECT

public:
    explicit AddOrEditPassScreen(QWidget *parent = nullptr, SubscriptionType *toEdit = nullptr);
    ~AddOrEditPassScreen();

    bool eventFilter(QObject*, QEvent*);

    void mousePressEvent(QMouseEvent*);

private slots:
    void on_powrot_clicked();

    void on_zatwierdz_clicked();

private:
    Ui::AddOrEditPassScreen *ui;
    Keyboard *keyboard;
    SubscriptionType *toEdit;
    KodokanDAO *kodokanDAO;
};

#endif // ADDOREDITPASSSCREEN_H
