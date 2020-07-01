#include "AddOrEditClubMember.h"
#include "ui_AddOrEditClubMember.h"

AddOrEditClubMember::AddOrEditClubMember(QWidget *parent, ClubMember *toEdit, std::vector<ClubMember> *czlonkowie) :
    QDialog(parent),
    ui(new Ui::AddOrEditClubMember)
{
    ui->setupUi(this);
}

AddOrEditClubMember::~AddOrEditClubMember()
{
    delete ui;
}
