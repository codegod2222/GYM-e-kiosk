#include "TakePictureScreen.h"
#include "ui_TakePictureScreen.h"


TakePictureScreen::TakePictureScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TakePictureScreen)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    qRegisterMetaType<QImage>("QImage&");
    //data = new unsigned char[camera.getImageTypeSize(RASPICAM_FORMAT_RGB)];
}

TakePictureScreen::~TakePictureScreen()
{
    delete ui;
}

void TakePictureScreen::loop()
{
    // Open the camera
        if (!camera.open()) {
            qDebug() << "Error opening camera";
            cameraRunning = false;
        } else {
            cameraRunning = true;
        }

        // Wait for the camera
        sleep(3);

        // While the camera is on (the user has clicked the button), capture
        while (cameraRunning) {
            // Capture
            camera.grab();
            camera.retrieve(data, RASPICAM_FORMAT_RGB);

            // Convert the data and send to the caller to handle
            QImage image = QImage(data, camera.getWidth(), camera.getHeight(), QImage::Format_RGB888);

            // Update the image shown
            ui->imgLabel->setPixmap(QPixmap::fromImage(image));

            // Force an update of the UI so that the image is shown immediately.
            QApplication::processEvents();
            this->repaint();

            usleep(200);
        }
}
