#include "TakePictureScreen.h"
#include "ui_TakePictureScreen.h"
#include <QDebug>
#include <QtCore>


TakePictureScreen::TakePictureScreen(QWidget *parent, std::string email) :
    QWidget(parent),
    ui(new Ui::TakePictureScreen)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    this->ui->jeszczeRaz->setVisible(false);
    this->email = email;

    qRegisterMetaType<QImage>("QImage&");
    on_btnStart_clicked();
}

TakePictureScreen::~TakePictureScreen()
{
    delete ui;
}

void TakePictureScreen::on_btnStart_clicked()
{
    /*workerThread = new QThread;
    worker = new CameraWorker;

    worker->moveToThread(workerThread);

    connect(workerThread, SIGNAL(started()), worker, SLOT(doWork()));
    connect(this, SIGNAL(takePhoto(std::string)), worker, SLOT(takePhotoWorker(std::string)));
    connect(worker, SIGNAL(handleImage(QImage &)), this, SLOT(handleImage(QImage &)));
    workerThread->start();*/

}

void TakePictureScreen::handleImage(QImage &image)
{
    ui->imgLabel->setPixmap(QPixmap::fromImage(image));
    QApplication::processEvents();
    this->repaint();
}


void TakePictureScreen::on_OK_2_clicked()
{
    /*workerThread->terminate();
    delete worker;*/
    this->close();
}

void TakePictureScreen::on_OK_clicked()
{
    this->ui->OK->setVisible(false);
    this->ui->jeszczeRaz->setVisible(true);
    emit takePhoto(email);
    QApplication::processEvents();
    this->repaint();
}
