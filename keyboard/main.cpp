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
     //  QWidget *some = w.getMainWidget();
    QPalette pal =w.palette();

    // set black background
    pal.setColor(QPalette::Background, Qt::white);

  //  w.setStyleSheet("QMainWindow{background:black;}");
    w.show();
    //  w.setPalette(pal);
    //enter full screen mode
  //w.setWindowState(w.windowState() ^ Qt::WindowFullScreen);



   // some->setStyleSheet("QWidget{background-color:black;}");
    TimeManager *mTimer= new TimeManager(w.getButtonList(),w.getTextEdit(),w.getProgressBar(),w.getHintButtonList());
    mTimer->startTimer();
  //  Dictionary dic;




    return a.exec();
}
