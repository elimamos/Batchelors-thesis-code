#include "mainwindow.h"
#include <QApplication>
#include<QElapsedTimer>
#include<QDebug>
#include"TimeManager.h"
#include "buttonoperator.h"
#include "dictionary.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();
    //enter full screen mode
  //w.setWindowState(w.windowState() ^ Qt::WindowFullScreen);


    TimeManager *mTimer= new TimeManager(w.getButtonList(),w.getTextEdit(),w.getProgressBar(),w.getHintButtonList());
    mTimer->startTimer();
  //  Dictionary dic;


    return a.exec();
}
