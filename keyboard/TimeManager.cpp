#include "TimeManager.h"
#include<QtCore>
#include <QtDebug>
#include "buttonoperator.h"
#include "const.h"
#include<QString>
#include"hovermanager.h"
#include<vector>
TimeManager::TimeManager(std::vector<ButtonOperator*> sButtonList,QTextEdit *sTextEdit)
{
    previousHover= new HoverManager(-1, -1);
    buttonList=sButtonList;
    textEdit=sTextEdit;
}
  int i=0;
void TimeManager::TimerStep()
{



    //textEdit->append(QString::number(buttonList[1].getHover()));

   qDebug()<<buttonList[0]->getHover();

    qDebug()<<buttonList[1]->getHover();
//ButtonOperator *newButton= buttonList.at(1);
//newButton->setText("LOL");

    qDebug()<<buttonList[2]->getHover();
    //qDebug()<<"  ";

 /*   int currentIndex =this->getHoverIndex();
  //  qDebug()<<"CurrentIndex "+QString::number(currentIndex)+" LastHovered "+QString::number(lastHoveredIndex);
    if(currentIndex==lastHoveredIndex){
         qDebug()<<"SAME";
    }
    else{
             qDebug()<<"different";
             lastHoveredIndex=currentIndex;
    }
*/

}

int TimeManager::getHoveredButton(){
    for(int i=BUTTON_COUNT-1;i>=0;i--)
    {
       /* if(buttonList[i].getHover()){
            return i;
        }*/
    }
    return -1;
}

void TimeManager::startTimer(){
    timer = new QTimer (this);

     connect (timer,SIGNAL(timeout()),this, SLOT(TimerStep()));
     timer->start(TIMER_TICK);
}

