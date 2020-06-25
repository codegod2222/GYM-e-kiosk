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
    explicit BuyingPassScreen(QWidget *parent = nullptr, bool logged = false);
    ~BuyingPassScreen();

    bool eventFilter(QObject*, QEvent*);

private:
    QString wybranyKarnet;
    QString wybranaPlatnosc;

private slots:
    void on_powrot_clicked();

    void on_gotowka_clicked();

    void on_karta_clicked();

    void on_online_clicked();

    void potwierdzZakup(QString, QString);

    void odbierzPotwierdzenie();
signals:
    void wyslijDaneDoPotwierdzenia(QString karnet, QString rodzajPlatnosci, BuyingPassScreen*);

private:
    Ui::BuyingPassScreen *ui;

};

#endif // BUYINGPASSSCREEN_H
