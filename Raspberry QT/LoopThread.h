#ifndef LOOPTHREAD_H
#define LOOPTHREAD_H
#include <QtCore>


class LoopThread : public QThread
{
    Q_OBJECT
public:
    void run();

signals:
    void przylozonoKarte(QString);
};

#endif // LOOPTHREAD_H
