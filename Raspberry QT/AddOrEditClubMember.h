#ifndef ADDOREDITCLUBMEMBER_H
#define ADDOREDITCLUBMEMBER_H

#include <QDialog>
#include "Keyboard.h"
#include "../databse_access/UserDAO.h"
#include "../databse_access/KodokanDAO.h"
#include "LoopThread.h"

namespace Ui {
class AddOrEditClubMember;
}

class AddOrEditClubMember : public QDialog
{
    Q_OBJECT

public:
    explicit AddOrEditClubMember(QWidget *parent = nullptr, UserDAO *toEdit = nullptr);
    ~AddOrEditClubMember();

    bool eventFilter(QObject*, QEvent*);

    void mousePressEvent(QMouseEvent*);

private slots:
    void on_powrot_clicked();

    void on_zatwierdz_clicked();

    void przylozonoKarte(QString);

private:
    Ui::AddOrEditClubMember *ui;
    Keyboard *keyboard;
    UserDAO *toEdit;
    KodokanDAO *kodokanDAO;
    LoopThread *loopThread;
    bool threadRun;
};

#endif // ADDOREDITCLUBMEMBER_H
