#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "AdministrationScreen.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    AdministrationScreen *temp = new AdministrationScreen();
    temp->move(0,0);
    temp->show();
    this->hide();
}
