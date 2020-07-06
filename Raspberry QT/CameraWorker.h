#ifndef CAMERAWORKER_H
#define CAMERAWORKER_H

#include <QImage>

#include <raspicam/raspicam.h>

using namespace raspicam;

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
