#include "LoopThread.h"
#include "QDebug"
#include "mainwindow.h"
#include "rfid.h"

void LoopThread::run()
{
    int i = 0;
    RFIDserial = RFIDopen(); //otwórz połączenie
    if (RFIDerrno == RFID_ERR_OPEN) { //jeżeli wystąpił błąd przy otwieraniu połączenia
    }
    char* readMsg; //bufor na odczytane dane
    while(runn)
    {
        qDebug() << "Watek " + QString::number(i);
        i++;
        int toRead = RFIDcheck(RFIDserial); //sprawdź ile znaków czeka na odczyt
        if (toRead >= 14) { //jeżeli na odczyt czeka conajmniej 14 znaków (cała wiadomość czytnika)
            readMsg = RFIDread(RFIDserial); //odczytaj wiadomość
            RFIDclear(RFIDserial); //wyczyść bufor wejściowy (na wypadek wielokrotnego odczytania tej samej karty) //potencjalnie zbędne
            if (readMsg == NULL) { //jeżeli wystąpił błąd
                //i++;
                continue;
            }
            else {
                char* ret = new char[11];
                for (unsigned char i = 0; i < 10; i++) {
                    ret[i] = readMsg[i+1];
                }
                ret[10] = '\0';
                emit przylozonoKarte(QString(ret));
                delete[] ret;
                break;
            }
        }
        sleep(1);
    }
    RFIDclose(RFIDserial);
}
