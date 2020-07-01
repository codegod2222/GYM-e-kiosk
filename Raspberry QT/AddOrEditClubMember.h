#ifndef ADDOREDITCLUBMEMBER_H
#define ADDOREDITCLUBMEMBER_H

#include <QDialog>
#include "ClubMember.h"

namespace Ui {
class AddOrEditClubMember;
}

class AddOrEditClubMember : public QDialog
{
    Q_OBJECT

public:
    explicit AddOrEditClubMember(QWidget *parent = nullptr, ClubMember *toEdit = nullptr, std::vector<ClubMember> *czlonkowie = nullptr);
    ~AddOrEditClubMember();

private:
    Ui::AddOrEditClubMember *ui;
};

#endif // ADDOREDITCLUBMEMBER_H
