#include "mytimer.h"
#include<QtCore>
#include <QtDebug>
#include "buttonoperator.h"
#include "const.h"
#include<QString>
myTimer::myTimer(ButtonOperator *sButtonList,QTextEdit *sTextEdit)
{
    buttonList=sButtonList;
    textEdit=sTextEdit;
}
int lastHoveredIndex=1;
void myTimer::TimerStep()
{

    if(lastHoveredIndex%2==0){
        buttonList[0].setText("0");
    }else buttonList[0].setText("1");
    lastHoveredIndex++;
    textEdit->append(QString::number(lastHoveredIndex));
    //qDebug()<<QString::number(thisTimer->getHoverIndex());
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

void myTimer::startTimer(){
    timer = new QTimer (this);

     connect (timer,SIGNAL(timeout()),this, SLOT(TimerStep()));
     timer->start(TIMER_TICK);
}

