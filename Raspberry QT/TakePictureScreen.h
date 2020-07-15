#ifndef TAKEPICTURESCREEN_H
#define TAKEPICTURESCREEN_H

#include <QWidget>
#include <raspicam/raspicam.h>
#include <CameraWorker.h>

using namespace raspicam;

namespace Ui {
class TakePictureScreen;
}

class TakePictureScreen : public QWidget
{
    Q_OBJECT

public:
    explicit TakePictureScreen(QWidget *parent = nullptr, std::string email = "");
    ~TakePictureScreen();

private slots:

        void handleImage(QImage &image);

        void startCapturing();

        void on_robZdj_clicked();

        void on_ponow_clicked();

        void on_wyjdz_clicked();

signals:

        void takePhoto();

private:
        Ui::TakePictureScreen *ui;
        QThread *workerThread;
        CameraWorker *worker;
        std::string email;
        bool cameraRunning;
};

#endif // TAKEPICTURESCREEN_H
