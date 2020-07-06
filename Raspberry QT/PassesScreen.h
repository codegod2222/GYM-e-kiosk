#ifndef PASSESSCREEN_H
#define PASSESSCREEN_H

#include <QDialog>
#include "AddOrEditPassScreen.h"
#include "../databse_access/KodokanDAO.h"

namespace Ui {
class PassesScreen;
}

class PassesScreen : public QDialog
{
    Q_OBJECT

public:
    explicit PassesScreen(QWidget *parent = nullptr);
    ~PassesScreen();

private slots:
    void on_powrot_clicked();

    void on_dodajKarnet_clicked();

    bool eventFilter(QObject*, QEvent*);

    void on_usunKarnet_clicked();

    void refreshTable();

    void on_edytujKarnet_clicked();

private:
    Ui::PassesScreen *ui;
    AddOrEditPassScreen *addOrEditPassScreen = nullptr;
    KodokanDAO *kodokanDAO;
};

#endif // PASSESSCREEN_H
