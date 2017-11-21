#include "TimeManager.h"
#include<QtCore>
#include <QtDebug>
#include "buttonoperator.h"
#include "const.h"
#include<QString>
#include"hovermanager.h"
#include<vector>
#include "dictionary.h"
#include "googlesearcher.h"
#include "personalizeview.h"
TimeManager::TimeManager(std::vector<ButtonOperator*> sButtonList,QTextEdit *sTextEdit,QRoundProgressBar *sProgressBar,std::vector<ButtonOperator*> sHintButtonList)
{
    hintButtonList=sHintButtonList;
    hoverState= new HoverManager(-1, -1, 0,-1,0);
    buttonList=sButtonList;
    textEdit=sTextEdit;
    roundProgressBar=sProgressBar;
    googler = new GoogleSearcher;
    googler->setHintButtonList(hintButtonList);
    googler->setTextEdit(textEdit);
    isSending=false;
    stop=true;
    sendingState=1;
    for(int i=0;i<buttonList.size();i++){
        if(buttonList.at(i)->getSpecial()==false){
            buttonList.at(i)->setStyleSheet("background-color:#818b91");
        }
    }
    dictionary= new Dictionary(sTextEdit,sHintButtonList);

}

void TimeManager::TimerStep()
{

    int currentHoverID=getHoveredButton();
    if(currentHoverID!=-1){
        if(stop==true){
            if(buttonList.at(currentHoverID)->getSpecial()){
                hoverState=updateHoverState(currentHoverID);
                hoverState= executeTimerStep();
                roundProgressBar->setValue(hoverState->getHoveredCount());
                updateButtonLook();
            }
        }else{
            hoverState=updateHoverState(currentHoverID);
            hoverState= executeTimerStep();
            roundProgressBar->setValue(hoverState->getHoveredCount());
            updateButtonLook();
        }
    }
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
    if(!stop){

        //   qDebug()<<"NONE special pressed";
        textEdit->setFocus();
        executeNormalButton();
        if(hoverState->getLastSpecialID()==SHIFT_ID){
            return new HoverManager(hoverState->getLastHoveredID(),0,0,-1,0);
        }else return new HoverManager(hoverState->getLastHoveredID(),0,hoverState->getKeyboardState(),hoverState->getLastSpecialID(),hoverState->getLastSpecialCount());
    }
    return hoverState;//new HoverManager(hoverState->getLastHoveredID(),0,hoverState->getKeyboardState(),hoverState->getLastSpecialID(),hoverState->getLastSpecialCount());
}
void TimeManager::executeNormalButton(){

    //textEdit->insertPlainText(buttonList[hoverState->getLastHoveredID()]->getDisplayList().at(hoverState->getKeyboardState()));
    // QString currentText=textEdit->toPlainText();
    dictionary->update(buttonList[hoverState->getLastHoveredID()]->getDisplayList().at(hoverState->getKeyboardState()));
    //    textEdit->moveCursor (QTextCursor::End);
}

HoverManager *TimeManager::executeSpecialButton(){
    QString searchText;
    switch(hoverState->getLastHoveredID()){
    case CAPS_ID:
        qDebug()<<"CAPSLOCK";
        if(hoverState->getLastSpecialID()==CAPS_ID){


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
        isSending=true;
        searchText= textEdit->toPlainText();
        googler->search(searchText);
        return new HoverManager(hoverState->getLastHoveredID(),0,hoverState->getKeyboardState(),hoverState->getLastSpecialID(),hoverState->getLastSpecialCount());

    case END_ID:
        dictionary->moveCursorEnd("end");
        // textEdit->moveCursor(QTextCursor::End);
        return new HoverManager(hoverState->getLastHoveredID(),0,hoverState->getKeyboardState(),hoverState->getLastSpecialID(),hoverState->getLastSpecialCount());
    case CLEAR_ID:
        dictionary->clearTextbox();
        //  textEdit->clear();
        return hoverState;
    case HOME_ID:
        dictionary->moveCursorEnd("home");
        // textEdit->moveCursor(QTextCursor::Start);
        return new HoverManager(hoverState->getLastHoveredID(),0,hoverState->getKeyboardState(),hoverState->getLastSpecialID(),hoverState->getLastSpecialCount());
    case LEFT_ID:
        //textEdit->moveCursor(QTextCursor::Left);
        dictionary->moveCursor("left");
        return new HoverManager(hoverState->getLastHoveredID(),0,hoverState->getKeyboardState(),hoverState->getLastSpecialID(),hoverState->getLastSpecialCount());
    case UP_ID:
        textEdit->moveCursor(QTextCursor::Up);
        return new HoverManager(hoverState->getLastHoveredID(),0,hoverState->getKeyboardState(),hoverState->getLastSpecialID(),hoverState->getLastSpecialCount());
    case RIGHT_ID:
        dictionary->moveCursor("right");
        //  textEdit->moveCursor(QTextCursor::Right);
        return new HoverManager(hoverState->getLastHoveredID(),0,hoverState->getKeyboardState(),hoverState->getLastSpecialID(),hoverState->getLastSpecialCount());
    case DOWN_ID:
        textEdit->moveCursor(QTextCursor::Down);
        return new HoverManager(hoverState->getLastHoveredID(),0,hoverState->getKeyboardState(),hoverState->getLastSpecialID(),hoverState->getLastSpecialCount());
    case TXT2SPEACH_ID:
        //HERE Text to speech  BE IMPLEMENTED
        return hoverState;
    case MENU_ID:
        personalize= new PersonalizeView(); // Be sure to destroy your window somewhere
        personalize->setAttribute( Qt::WA_DeleteOnClose );
        personalize->setButtonList(buttonList);
        personalize->setSendingState(&sendingState);

        personalize->show();
        return new HoverManager(hoverState->getLastHoveredID(),0,hoverState->getKeyboardState(),hoverState->getLastSpecialID(),hoverState->getLastSpecialCount());
    case HINT1_ID:
        if(isSending){

            googler->openLink(0);
            isSending=false;
            textEdit->clear();
        }else dictionary->useHint(0);
        return new HoverManager(hoverState->getLastHoveredID(),0,hoverState->getKeyboardState(),hoverState->getLastSpecialID(),hoverState->getLastSpecialCount());
    case HINT2_ID:
        if(isSending){
            googler->openLink(1);
            isSending=false;
            textEdit->clear();
        }else dictionary->useHint(1);
        return new HoverManager(hoverState->getLastHoveredID(),0,hoverState->getKeyboardState(),hoverState->getLastSpecialID(),hoverState->getLastSpecialCount());

    case HINT3_ID:
        if(isSending){
            googler->openLink(2);
            isSending=false;
            textEdit->clear();
        }else dictionary->useHint(2);
        return new HoverManager(hoverState->getLastHoveredID(),0,hoverState->getKeyboardState(),hoverState->getLastSpecialID(),hoverState->getLastSpecialCount());

    case HINT4_ID:
        if(isSending){
            googler->openLink(3);
            isSending=false;
            textEdit->clear();
        }else dictionary->useHint(3);
        return new HoverManager(hoverState->getLastHoveredID(),0,hoverState->getKeyboardState(),hoverState->getLastSpecialID(),hoverState->getLastSpecialCount());

    case LEAVE_ID:
        qApp->quit();
        return hoverState;
    case STOP_ID:
        if(stop){
            stop=false;
            QStringList myList;
            myList.append("STOP");
            myList.append("STOP");
            myList.append("STOP");
            myList.append("STOP");
            myList.append("STOP");
            buttonList.at(STOP_ID)->setDisplayList(myList);
            for(int i=0;i<buttonList.size();i++){
                if(buttonList.at(i)->getSpecial()==false){
                    buttonList.at(i)->setStyleSheet("QPushButton { background: #9fb5c4;} QPushButton:hover{background: #4a6373;}");
                }
            }
            roundProgressBar->setMaximum(TICK_COUNTER);

        }
        else {
            stop=true;
            QStringList myList;
            myList.append("START");
            myList.append("START");
            myList.append("START");
            myList.append("START");
            myList.append("START");
            buttonList.at(STOP_ID)->setDisplayList(myList);
            for(int i=0;i<buttonList.size();i++){
                if(buttonList.at(i)->getSpecial()==false){
                    buttonList.at(i)->setStyleSheet("background-color:#818b91");
                }
            }
            //  roundProgressBar->setMaximum(0.0);

        }

        return new HoverManager(hoverState->getLastHoveredID(),0,hoverState->getKeyboardState(),hoverState->getLastSpecialID(),hoverState->getLastSpecialCount());


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

