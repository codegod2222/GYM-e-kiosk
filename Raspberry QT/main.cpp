#include "mainwindow.h"
//#1.1
#include <QWSServer>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //#1.1
    QWSServer::setCursorVisible(false);
    //#1.2
    QCursor cursor(Qt::BlankCursor);
    QApplication::setOverrideCursor(cursor);
    QApplication::changeOverrideCursor(cursor);
    //

    MainWindow w;
    w.move(0,0);
    w.show();
    return a.exec();
}
