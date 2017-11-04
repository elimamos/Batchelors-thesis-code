#include "TimeManager.h"
#include<QtCore>
#include <QtDebug>
#include "buttonoperator.h"
#include "const.h"
#include<QString>
#include"hovermanager.h"
#include<vector>
TimeManager::TimeManager(std::vector<ButtonOperator*> sButtonList,QTextEdit *sTextEdit,QProgressBar *sProgressBar)
{
    hoverState= new HoverManager(-1, -1, 0,-1,0);
    buttonList=sButtonList;
    textEdit=sTextEdit;
    progressBar=sProgressBar;
}

void TimeManager::TimerStep()
{

    int currentHoverID=getHoveredButton();
    hoverState=updateHoverState(currentHoverID);
    hoverState= executeTimerStep();
    progressBar->setValue(hoverState->getHoveredCount());
updateButtonLook();
 //   qDebug()<<hoverState->getLastHoveredID();
   // qDebug()<<hoverState->getHoveredCount();
   // qDebug()<<" ";

}
HoverManager *TimeManager::executeTimerStep(){
    if(hoverState->getHoveredCount()<TICK_COUNTER){
        return hoverState;
    }
  if(buttonList[hoverState->getLastHoveredID()]->getSpecial()==true){
      qDebug()<<"SPECIAL PRESSED";
     return executeSpecialButton();

  }

    qDebug()<<"NONE special pressed";
    executeNormalButton();
if(hoverState->getLastSpecialID()==SHIFT_ID){
 return new HoverManager(hoverState->getLastHoveredID(),0,0,-1,0);
}else return new HoverManager(hoverState->getLastHoveredID(),0,hoverState->getKeyboardState(),hoverState->getLastSpecialID(),hoverState->getLastSpecialCount());

}
void TimeManager::executeNormalButton(){

    textEdit->insertPlainText(buttonList[hoverState->getLastHoveredID()]->getDisplayList().at(hoverState->getKeyboardState()));
    textEdit->moveCursor (QTextCursor::End);
}

HoverManager *TimeManager::executeSpecialButton(){

    switch(hoverState->getLastHoveredID()){
        case CAPS_ID:
            qDebug()<<"CAPSLOCK";
            if(hoverState->getLastSpecialID()==CAPS_ID){
                 return new HoverManager(hoverState->getLastHoveredID(),0,0,-1,0);
            }
            return new HoverManager(hoverState->getLastHoveredID(),0,1,CAPS_ID,0);
        case SHIFT_ID:
            if(hoverState->getLastSpecialID()==SHIFT_ID){
                 return new HoverManager(hoverState->getLastHoveredID(),0,0,-1,0);
            }
             return new HoverManager(hoverState->getLastHoveredID(),0,1,SHIFT_ID,0);
        case SPECIAL_ID:
            qDebug()<<"Special";
            if(hoverState->getLastSpecialID()==SPECIAL_ID){
                if(hoverState->getLastSpecialCount()==1){
                    return new HoverManager(hoverState->getLastHoveredID(),0,3,SPECIAL_ID,2);
                }
                return new HoverManager(hoverState->getLastHoveredID(),0,0,-1,0);
            }
           return new HoverManager(hoverState->getLastHoveredID(),0,2,SPECIAL_ID,1);
        break;
        case PL_ID:
        if(hoverState->getLastSpecialID()==PL_ID){
             return new HoverManager(hoverState->getLastHoveredID(),0,0,-1,0);
        }
        return new HoverManager(hoverState->getLastHoveredID(),0,4,PL_ID,0);


    }

    return hoverState;

}
int TimeManager::getHoveredButton(){
    for(unsigned int i=0;i<buttonList.size();i++)
    {
        if(buttonList[i]->getHover()){
            return i;
        }
    }
    return -1;
}
HoverManager *TimeManager::updateHoverState(int currentHover){
    if(currentHover==-1){
        return new HoverManager(-1,0,hoverState->getKeyboardState(),hoverState->getLastSpecialID(),hoverState->getLastSpecialCount());
    }

    if(hoverState->getLastHoveredID()==currentHover){
        int currentCount=hoverState->getHoveredCount();
        return new HoverManager(currentHover,currentCount+1,hoverState->getKeyboardState(),hoverState->getLastSpecialID(),hoverState->getLastSpecialCount());
    }

    return new HoverManager(currentHover,0,hoverState->getKeyboardState(),hoverState->getLastSpecialID(),hoverState->getLastSpecialCount());



}

void TimeManager::startTimer(){
    timer = new QTimer (this);

     connect (timer,SIGNAL(timeout()),this, SLOT(TimerStep()));
     timer->start(TIMER_TICK);
}
void TimeManager::updateButtonLook(){
    for(ButtonOperator *btn:buttonList){
        btn->setText(btn->getDisplayList().at(hoverState->getKeyboardState()));
    }

}

