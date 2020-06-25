#include "LoopThread.h"
#include "QDebug"
#include "mainwindow.h"

void LoopThread::run()
{
    int i = 0;
    while(1)
    {
        QString licznik = QString::number(i);
        qDebug() << "Pozdrowienia z loopThread " + licznik;
        _sleep(500);
        i++;

        if(i%10 == 0)
        {
            emit przylozonoKarte("Emit z loopThread");
        }
    }
}
