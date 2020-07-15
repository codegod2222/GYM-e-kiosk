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

    this->ui->ponow->setVisible(false);
    this->email = email;

    qRegisterMetaType<QImage>("QImage&");
    startCapturing();
}

TakePictureScreen::~TakePictureScreen()
{
    qDebug() << "Destruktor TakePictureScreen";
    this->cameraRunning = false;
    //Moze generowac bledy:
    delete workerThread;
    delete worker;
    delete ui;
}

void TakePictureScreen::startCapturing()
{
    this->cameraRunning = true;

    workerThread = new QThread;
    worker = new CameraWorker(cameraRunning, email);

    worker->moveToThread(workerThread);

    connect(workerThread, SIGNAL(started()), worker, SLOT(doWork()));
    connect(this, SIGNAL(takePhoto()), worker, SLOT(takePhotoWorker()));
    connect(worker, SIGNAL(handleImage(QImage &)), this, SLOT(handleImage(QImage &)));
    workerThread->start();

}

void TakePictureScreen::handleImage(QImage &image)
{
    ui->imgLabel->setPixmap(QPixmap::fromImage(image));
    QApplication::processEvents();
    this->repaint();
}

void TakePictureScreen::on_robZdj_clicked()
{
    this->ui->robZdj->setVisible(false);
    this->ui->ponow->setVisible(true);
    emit takePhoto();
    QApplication::processEvents();
    this->repaint();
}

void TakePictureScreen::on_ponow_clicked()
{
    this->cameraRunning = true;
    //Trzeba przedebugowac bo nie wiem jak sie zachowa (nie mamy nigdzie jawnie thread.stop()
    workerThread->start();
    //lub ewentualnie to:
    //worker->doWork();
}

void TakePictureScreen::on_wyjdz_clicked()
{
    this->cameraRunning = false;
    worker->clean();
    this->close();
}
