#ifndef CLUBMEMBERSSCREEN_H
#define CLUBMEMBERSSCREEN_H

#include <QDialog>
#include "ClubMember.h"
#include "AddOrEditClubMember.h"

namespace Ui {
class ClubMembersScreen;
}

class ClubMembersScreen : public QDialog
{
    Q_OBJECT

public:
    explicit ClubMembersScreen(QWidget *parent = nullptr);
    ~ClubMembersScreen();

private slots:

    bool eventFilter(QObject*, QEvent*);

    void refreshTable();

    void on_dodajCzlonka_clicked();

    void on_usunCzlonka_clicked();

    void on_edytujCzlonka_clicked();

    void on_powrot_clicked();

private:
    Ui::ClubMembersScreen *ui;
    std::vector<ClubMember> *czlonkowie;
    AddOrEditClubMember *addOrEditClubMember = nullptr;
};

#endif // CLUBMEMBERSSCREEN_H
