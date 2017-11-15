#include "TimeManager.h"
#include<QtCore>
#include <QtDebug>
#include "buttonoperator.h"
#include "const.h"
#include<QString>
#include"hovermanager.h"
#include<vector>
#include "dictionary.h"
TimeManager::TimeManager(std::vector<ButtonOperator*> sButtonList,QTextEdit *sTextEdit,QRoundProgressBar *sProgressBar,std::vector<ButtonOperator*> sHintButtonList)
{
    hintButtonList=sHintButtonList;
    hoverState= new HoverManager(-1, -1, 0,-1,0);
    buttonList=sButtonList;
    textEdit=sTextEdit;
    roundProgressBar=sProgressBar;

dictionary= new Dictionary(sTextEdit,sHintButtonList);
   /* dictionary->insertWord(trieTree,  QString:: fromUtf8("bęc"),1);
  dictionary->insertWord(trieTree, QString:: fromUtf8("eliska"),2);
      dictionary->insertWord(trieTree, QString:: fromUtf8("kopytko"),3);
      dictionary->insertWord(trieTree, QString:: fromUtf8("aęaaa"),4);
      dictionary->insertWord(trieTree,"a",5);
      dictionary->insertWord(trieTree,QString::fromUtf8("aaaę"),6);
      dictionary->insertWord(trieTree,QString::fromUtf8("będę"),7);
      dictionary->insertWord(trieTree,QString::fromUtf8("będąc"),8);*/
}

void TimeManager::TimerStep()
{

    int currentHoverID=getHoveredButton();
    hoverState=updateHoverState(currentHoverID);
    hoverState= executeTimerStep();
    roundProgressBar->setValue(hoverState->getHoveredCount());
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
        textEdit->setFocus();
        return executeSpecialButton();

    }

 //   qDebug()<<"NONE special pressed";
    textEdit->setFocus();
    executeNormalButton();
    if(hoverState->getLastSpecialID()==SHIFT_ID){
        return new HoverManager(hoverState->getLastHoveredID(),0,0,-1,0);
    }else return new HoverManager(hoverState->getLastHoveredID(),0,hoverState->getKeyboardState(),hoverState->getLastSpecialID(),hoverState->getLastSpecialCount());

}
void TimeManager::executeNormalButton(){

   //textEdit->insertPlainText(buttonList[hoverState->getLastHoveredID()]->getDisplayList().at(hoverState->getKeyboardState()));
  // QString currentText=textEdit->toPlainText();
     dictionary->update(buttonList[hoverState->getLastHoveredID()]->getDisplayList().at(hoverState->getKeyboardState()));
    //    textEdit->moveCursor (QTextCursor::End);
}

HoverManager *TimeManager::executeSpecialButton(){

    switch(hoverState->getLastHoveredID()){
    case CAPS_ID:
        qDebug()<<"CAPSLOCK";
        if(hoverState->getLastSpecialID()==CAPS_ID){


//      vector<QString> *endings=new vector<QString>();
  //        Dictionary:: node * trieNode =  dictionary->searchWord(trieTree, "bę");
    //       dictionary->getSimilarEndings(trieNode,printUtil,endings);
      //          textEdit->append(endings->at(2));

            return new HoverManager(hoverState->getLastHoveredID(),0,0,-1,0);
        }
       //   dictionary->update("o");
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
    case BACK_ID:
        //textEdit->textCursor().deletePreviousChar();
        dictionary->backSpace();
        return new HoverManager(hoverState->getLastHoveredID(),0,hoverState->getKeyboardState(),hoverState->getLastSpecialID(),hoverState->getLastSpecialCount());
    case SEND_ID:
        //HERE BROADCAST TO BE IMPLEMENTED
        return hoverState;
    case END_ID:
        textEdit->moveCursor(QTextCursor::End);
        return new HoverManager(hoverState->getLastHoveredID(),0,hoverState->getKeyboardState(),hoverState->getLastSpecialID(),hoverState->getLastSpecialCount());
    case CLEAR_ID:
        textEdit->clear();
        return hoverState;
    case HOME_ID:
        textEdit->moveCursor(QTextCursor::Start);
        return new HoverManager(hoverState->getLastHoveredID(),0,hoverState->getKeyboardState(),hoverState->getLastSpecialID(),hoverState->getLastSpecialCount());
    case LEFT_ID:
        textEdit->moveCursor(QTextCursor::Left);
        return new HoverManager(hoverState->getLastHoveredID(),0,hoverState->getKeyboardState(),hoverState->getLastSpecialID(),hoverState->getLastSpecialCount());
    case UP_ID:
        textEdit->moveCursor(QTextCursor::Up);
        return new HoverManager(hoverState->getLastHoveredID(),0,hoverState->getKeyboardState(),hoverState->getLastSpecialID(),hoverState->getLastSpecialCount());
    case RIGHT_ID:
        textEdit->moveCursor(QTextCursor::Right);
        return new HoverManager(hoverState->getLastHoveredID(),0,hoverState->getKeyboardState(),hoverState->getLastSpecialID(),hoverState->getLastSpecialCount());
    case DOWN_ID:
        textEdit->moveCursor(QTextCursor::Down);
        return new HoverManager(hoverState->getLastHoveredID(),0,hoverState->getKeyboardState(),hoverState->getLastSpecialID(),hoverState->getLastSpecialCount());
    case TXT2SPEACH_ID:
        //HERE Text to speech  BE IMPLEMENTED
        return hoverState;

    case LEAVE_ID:
        qApp->quit();
        return hoverState;


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

