#include "CameraWorker.h"

#include <fstream>
#include <iostream>

#include <QDebug>
#include <QApplication>

#include "unistd.h"

CameraWorker::CameraWorker() : cameraRunning(true)
{
    qRegisterMetaType<QImage>("QImage&");
    data = new unsigned char[camera.getImageTypeSize(RASPICAM_FORMAT_GRAY)];
}

CameraWorker::~CameraWorker()
{
}

void CameraWorker::doWork()
{
    // Open the camera
    if (!camera.open()) {
        qDebug() << "Error opening camera";
        cameraRunning = false;
    } else {
        cameraRunning = true;
    }

    // Wait for the camera
    //sleep(3);

    // While the camera is on (the user has clicked the button), capture
    while (cameraRunning) {
        // Capture
        camera.grab();
        camera.retrieve(data, RASPICAM_FORMAT_RGB);
        camera.setWidth(1280);
        camera.setHeight(960);

        // Convert the data and send to the caller to handle
        QImage image = QImage(data, camera.getWidth(), camera.getHeight(), QImage::Format_RGB888);
        image = image.rgbSwapped();
        emit handleImage(image);

        // Make the app process stopWork() if necessary
        qApp->processEvents();
        usleep(200);
    }
}

void CameraWorker::takePhotoWorker()
{
    std::string path = "email";
    path.append(".ppm");
    std::ofstream outFile (path , std::ios::binary);
    outFile<<"P6\n"<< camera.getWidth() << " " << camera.getHeight() << " 255\n";
    outFile.write((char*)data, camera.getImageTypeSize(RASPICAM_FORMAT_BGR));
    cameraRunning = false;
    qApp->processEvents();
}

