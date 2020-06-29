#ifndef TAKEPICTURESCREEN_H
#define TAKEPICTURESCREEN_H

#include <QWidget>
/*#include <raspicam/raspicam.h>

using namespace raspicam;*/

namespace Ui {
class TakePictureScreen;
}

class TakePictureScreen : public QWidget
{
    Q_OBJECT

public:
    explicit TakePictureScreen(QWidget *parent = nullptr);
    ~TakePictureScreen();

private:
    void loop();

private:
    Ui::TakePictureScreen *ui;
    //RaspiCam camera;
    unsigned char *data;
};

#endif // TAKEPICTURESCREEN_H
