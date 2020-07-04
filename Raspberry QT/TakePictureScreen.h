#ifndef TAKEPICTURESCREEN_H
#define TAKEPICTURESCREEN_H

#include <QWidget>
//#include <raspicam/raspicam.h>
#include <CameraWorker.h>

//using namespace raspicam;

namespace Ui {
class TakePictureScreen;
}

class TakePictureScreen : public QWidget
{
    Q_OBJECT

public:
    explicit TakePictureScreen(QWidget *parent = nullptr);
    ~TakePictureScreen();

private slots:

        void handleImage(QImage &image);
        void on_btnStart_clicked();

        void on_OK_2_clicked();

        void on_OK_clicked();

signals:

        void takePhoto();

private:
        Ui::TakePictureScreen *ui;
        QThread *workerThread;
        //CameraWorker *worker;
};

#endif // TAKEPICTURESCREEN_H
