#include "TakePictureScreen.h"
#include "ui_TakePictureScreen.h"
#include <QDebug>
#include <QtCore>


TakePictureScreen::TakePictureScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TakePictureScreen)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->ui->jeszczeRaz->setVisible(false);

    qRegisterMetaType<QImage>("QImage&");
    on_btnStart_clicked();
}

TakePictureScreen::~TakePictureScreen()
{
    delete ui;
}

void TakePictureScreen::on_btnStart_clicked()
{
    // Initialize the thread and worker
    /*workerThread = new QThread;
    worker = new CameraWorker;

    // Setup the thread
    worker->moveToThread(workerThread);

    // Connect signals to slots
    connect(workerThread, SIGNAL(started()), worker, SLOT(doWork()));
    connect(this, SIGNAL(takePhoto()), worker, SLOT(takePhotoWorker()));
    connect(worker, SIGNAL(handleImage(QImage &)), this, SLOT(handleImage(QImage &)));
    workerThread->start();*/

}

void TakePictureScreen::handleImage(QImage &image)
{
    // Update the image shown
    ui->imgLabel->setPixmap(QPixmap::fromImage(image));

    // Force an update of the UI so that the image is shown immediately.
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
    emit takePhoto();
    QApplication::processEvents();
    this->repaint();
}
