#ifndef CAMERAWORKER_H
#define CAMERAWORKER_H

#include <QImage>

#include <raspicam/raspicam.h>

// This makes it so we don't have to prefix everything with raspicam::
// So raspicam::RaspiCam becomes just RaspiCam
using namespace raspicam;

/*!
 * \brief Class to run the camera and get data from it.
 *
 * This class is responsible for grabbing data from the Raspberry Pi camera
 * using the [raspicam library](https://github.com/cedricve/raspicam)
 * and converting it to a QImage so it can be displayed by MainWindow.
 */
class CameraWorker : public QObject
{
    Q_OBJECT
public:
    explicit CameraWorker();
    ~CameraWorker();

private:
    RaspiCam camera;
    bool cameraRunning;
    unsigned char *data;

signals:
    void handleImage(QImage &image);

private slots:
    void takePhotoWorker();

public slots:
    void doWork();
};

#endif // CAMERAWORKER_H
