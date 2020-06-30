#ifndef LOOPTHREAD_H
#define LOOPTHREAD_H
#include <QtCore>


class LoopThread : public QThread
{
    Q_OBJECT
public:
    void run();
    LoopThread(bool& _runn) : runn(_runn) {}

private:
    bool& runn;
    int RFIDserial;

signals:
    void przylozonoKarte(QString);
};

#endif // LOOPTHREAD_H
