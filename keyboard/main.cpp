#include "mainwindow.h"
#include <QApplication>
#include<QElapsedTimer>
#include<QDebug>
#include"mytimer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //enter full screen mode
  // w.setWindowState(w.windowState() ^ Qt::WindowFullScreen);
qDebug() << "show";

        myTimer mTimer;
    w.show();

    return a.exec();
}

