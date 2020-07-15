#ifndef CAMERAWORKER_H
#define CAMERAWORKER_H

#include <QImage>

#include <raspicam/raspicam.h>

using namespace raspicam;

class CameraWorker : public QObject
{
    Q_OBJECT
public:
    explicit CameraWorker(bool& _runn, std::string _email) : cameraRunning(_runn), email(_email) {};
    ~CameraWorker();

private:
    RaspiCam camera;
    bool& cameraRunning;
    unsigned char *data;
    std::string email;

signals:
    void handleImage(QImage &image);

private slots:
    void takePhotoWorker();   

public slots:
    void doWork();

    void clean();
};

#endif // CAMERAWORKER_H
