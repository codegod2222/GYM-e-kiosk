#ifndef ADDOREDITCLUBMEMBER_H
#define ADDOREDITCLUBMEMBER_H

#include <QDialog>
#include "ClubMember.h"
#include "Keyboard.h"

namespace Ui {
class AddOrEditClubMember;
}

class AddOrEditClubMember : public QDialog
{
    Q_OBJECT

public:
    explicit AddOrEditClubMember(QWidget *parent = nullptr, ClubMember *toEdit = nullptr, std::vector<ClubMember> *czlonkowie = nullptr);
    ~AddOrEditClubMember();

    bool eventFilter(QObject*, QEvent*);

    void mousePressEvent(QMouseEvent*);

private slots:
    void on_powrot_clicked();

    void on_zatwierdz_clicked();

private:
    Ui::AddOrEditClubMember *ui;
    Keyboard *keyboard;
    ClubMember *toEdit;
    std::vector<ClubMember> *czlonkowie;
    //KodokanDAO *kodokanDAO;
};

#endif // ADDOREDITCLUBMEMBER_H
