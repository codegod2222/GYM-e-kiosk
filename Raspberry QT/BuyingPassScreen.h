#ifndef BUYINGPASSSCREEN_H
#define BUYINGPASSSCREEN_H

#include <QDialog>

namespace Ui {
class BuyingPassScreen;
}

class BuyingPassScreen : public QDialog
{
    Q_OBJECT

public:
    explicit BuyingPassScreen(QWidget *parent = nullptr);
    ~BuyingPassScreen();

    void loop();

private slots:
    void on_powrot_clicked();

private:
    Ui::BuyingPassScreen *ui;
};

#endif // BUYINGPASSSCREEN_H
