#include "mainwindow.h"
#include <QApplication>
#include<QElapsedTimer>
#include<QDebug>
#include"TimeManager.h"
#include "buttonoperator.h"
#include "dictionary.h"
#include<QPalette>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

   QPalette pal =w.palette();

 pal.setColor(QPalette::Background, Qt::white);


    w.show();


    //enter full screen mode
  w.setWindowState(w.windowState() ^ Qt::WindowFullScreen);




    TimeManager *mTimer= new TimeManager(w.getButtonList(),w.getTextEdit(),w.getProgressBar(),w.getHintButtonList());
    mTimer->startTimer();





    return a.exec();
}
