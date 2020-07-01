#ifndef PASSESSCREEN_H
#define PASSESSCREEN_H

#include <QDialog>
#include "Pass.h"
#include "AddOrEditPassScreen.h"

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
    std::vector<Pass> *karnety;
    AddOrEditPassScreen *addOrEditPassScreen = nullptr;
};

#endif // PASSESSCREEN_H
