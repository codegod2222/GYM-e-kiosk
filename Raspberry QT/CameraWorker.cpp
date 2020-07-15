#include "CameraWorker.h"

#include <fstream>
#include <iostream>

#include <QDebug>
#include <QApplication>

#include "unistd.h"

CameraWorker::~CameraWorker()
{
    qDebug() << "Destruktor CameraWorker";
    delete data;
}

void CameraWorker::doWork()
{
    //Przeniesione z konstruktora
    qRegisterMetaType<QImage>("QImage&");
    data = new unsigned char[camera.getImageTypeSize(RASPICAM_FORMAT_RGB)];

    if (!camera.open())
    {
        qDebug() << "Problem z kamera";
        return;
    }

    sleep(2);

    while (this->cameraRunning)
    {
        camera.grab();
        camera.retrieve(data, RASPICAM_FORMAT_RGB);
        camera.setWidth(1280);
        camera.setHeight(960);

        QImage image = QImage(data, camera.getWidth(), camera.getHeight(), QImage::Format_RGB888);
        image = image.rgbSwapped();
        emit handleImage(image);

        qApp->processEvents();
        usleep(200);
    }
    qDebug() << "Wychodze z metody doWork";
}

void CameraWorker::takePhotoWorker()
{
    this->cameraRunning = false;
    //Do sprawdzenia backslash
    std::string path = "Pictures/" + email + ".ppm";
    std::ofstream outFile (path , std::ios::binary);
    outFile<<"P6\n"<< camera.getWidth() << " " << camera.getHeight() << " 255\n";
    outFile.write((char*)data, camera.getImageTypeSize(RASPICAM_FORMAT_RGB));
    qApp->processEvents();
}

void CameraWorker::clean()
{
    qDebug() << "Sprzatam w cameraWorker";
    delete data;
}

