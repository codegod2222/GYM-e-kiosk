#ifndef COMPANYINFOSCREEN_H
#define COMPANYINFOSCREEN_H

#include <QDialog>
#include "Keyboard.h"

namespace Ui {
class CompanyInfoScreen;
}

class CompanyInfoScreen : public QDialog
{
    Q_OBJECT

public:
    explicit CompanyInfoScreen(QWidget *parent = nullptr);
    ~CompanyInfoScreen();

    bool eventFilter(QObject*, QEvent*);

    void mousePressEvent(QMouseEvent*);

private slots:
    void on_powrot_clicked();

private:
    Ui::CompanyInfoScreen *ui;
    Keyboard *keyboard;
};

#endif // COMPANYINFOSCREEN_H
