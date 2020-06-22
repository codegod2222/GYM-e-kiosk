#include "Keyboard.h"
#include "ui_Keyboard.h"

Keyboard::Keyboard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Keyboard)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

Keyboard::~Keyboard()
{
    delete ui;
}

void Keyboard::activate(QLineEdit *toEdit)
{
    this->toEdit = toEdit;
}

void Keyboard::on_Q_clicked()
{
    toEdit->insert(ui->Q->text());
}

void Keyboard::on_W_clicked()
{
    toEdit->insert(ui->W->text());
}

void Keyboard::on_BACKSPACE_clicked()
{
    toEdit->backspace();
}
