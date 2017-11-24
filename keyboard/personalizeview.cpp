#include "personalizeview.h"
#include "ui_personalizeview.h"
#include "const.h"


PersonalizeView::PersonalizeView(QWidget *parent) :QWidget(parent), ui(new Ui::PersonalizeView)
{

    ui->setupUi(this);



    setNoneChangingButton(ui->exit,"WYJDŹ",false);
    setNoneChangingButton(ui->m1,"",false);
    setNoneChangingButton(ui->m2,"",false);
    setNoneChangingButton(ui->f1,"",false);
    setNoneChangingButton(ui->f2,"",false);
    setNoneChangingButton(ui->timeLess,"",true);
    setNoneChangingButton(ui->timeMore,"",true);

    QPalette pal =this->palette();
    pal.setColor(QPalette::Background, "#343434");
    QPalette pal2 = this->palette();
    pal2.setColor(QPalette::Background,Qt::white);
    QString look ="QPushButton {font: 28px arial, sans-serif; border-radius: 28px; font-weight: bold;color: #ffffff;font-weight:bold; background: #9fb5c4; padding: 10px 20px 10px 20px;text-decoration: none;} ";
    look +="QPushButton:hover{ background: #4a6373; text-decoration: none;}";
    QString look2 ="QPushButton {font: 28px arial, sans-serif; border-radius: 28px; font-weight: bold;color: #ffffff;font-weight:bold; background: #000000; padding: 10px 20px 10px 20px;text-decoration: none;} ";
    look2 +="QPushButton:hover{ background: #4a6373; text-decoration: none;}";
    QString look3="QWidget{         background-color:#5a5c51;           } QProgressBar{ border: 2px solid #343434;  border-radius: 5px;text-align: center; color: #343434; } QProgressBar::chunk { background-color: #fae596; } QTextEdit{ min-height: 10px; min-width: 100px;  border-radius: 28px; font-family: Arial; font-size: 20px; background:  #ffffff; padding: 10px 20px 10px 20px; text-decoration: none;} QPushButton { font: 28px arial, sans-serif; border-radius: 28px;font-weight: bold; color: #fae596; font-weight:bold; background: #312c32;  padding: 10px 20px 10px 20px; text-decoration: none; }";
       look3+="     QPushButton:hover{    background:#5a5c51;          text-decoration: none;      }   QPushButton#clear {   font-size: 18px;  }  QPushButton#home {    font-size: 18px;   }QPushButton#end {    font-size: 18px;      }   QPushButton:pressed{        background: #2b4454;       text-decoration: none;} QPushButton#menu{ background: #fae596;              text-decoration: none;} QPushButton:focus { outline: none; }     QScrollBar:vertical {   border: none;   background:#343434;        width:10px;    margin: 5px 5px 5px 5px;      }  ";
       layoutList.push_back(LayoutLook(QString("Basic"),look,pal));
       layoutList.push_back(LayoutLook(QString("Light"),look2,pal2));
       layoutList.push_back(LayoutLook(QString("Dark"),look,pal));

    ui->listWidget->addItem(layoutList.at(0).getLayoutName());
    ui->listWidget->addItem(layoutList.at(1).getLayoutName());
    ui->listWidget->addItem(layoutList.at(2).getLayoutName());
    ui->listWidget->item(0)->setSelected(true);


    /*   for(int row = 0; row < ui->listWidget->count(); row++)
    {
             QListWidgetItem *item = ui->listWidget->item(row);
              item->setTextAlignment(Qt::AlignCenter);
    }
*/
    // ui->listWidget->setTextElideMode();
    //  ui->listWidget->sortItems(Qt::DescendingOrder);
    ui->progressBar->setMaximum(STARTING_COUNT);
    timer = new QTimer (this);
    textFontSize=20;
    ui->lineEdit->setText(QString::number(textFontSize)+"px");
    ui->lineEdit->setStyleSheet("font-size: "+QString::number(textFontSize)+"px;");
    ui->lineEdit->setAlignment(Qt::AlignCenter);

    connect (timer,SIGNAL(timeout()),this, SLOT(TimerStep()));
    timer->start(TIMER_TICK);
    hoverState= new HoverManager(-1, -1, 0,-1,0);
    currentMod=0;

}
void PersonalizeView::setButtonInfo(ButtonOperator *myButton, QString s1,QString s2,QString s3,QString s4,QString s5,bool isSpecial){
    QStringList myList;
    myList.append(s1);
    myList.append(s2);
    myList.append(s3);
    myList.append(s4);
    myList.append(s5);
    myButton->setDisplayList(myList);
    myButton->setSpecial(isSpecial);
    menuButtons.push_back(myButton);


}
void PersonalizeView::setIsOpen(bool sIsOpen){
        isOpen=sIsOpen;
}
void PersonalizeView::setNoneChangingButton(ButtonOperator *myButton, QString s1,bool isSpecial){
    setButtonInfo(myButton,s1,s1,s1,s1,s1,isSpecial);
}
PersonalizeView::~PersonalizeView()
{
    delete ui;

}


void PersonalizeView::setButtonList(vector<ButtonOperator*> buttonList){
    keyboardButtons=buttonList;
}
void PersonalizeView::TimerStep()
{
    int currentHoverID=getHoveredButton();
    if(currentHoverID!=-1){
        hoverState=updateHoverState(currentHoverID);
        hoverState= executeTimerStep();
        ui->progressBar->setValue(hoverState->getHoveredCount());
        updateButtonLook();
    }

}
void PersonalizeView::setTickCount(int *sTickCount){

    tickCounter=sTickCount;
    double time = *tickCounter*TIMER_TICK/1000.0;
    ui->timeValue->setText(QString::number(time));
     ui->progressBar->setMaximum(*tickCounter);

}
int PersonalizeView::getHoveredButton(){
    for(unsigned int i=0;i<menuButtons.size();i++)
    {
        if(menuButtons[i]->getHover()){
            return i;
        }
    }
    return -1;

}

HoverManager *PersonalizeView::updateHoverState(int currentHover){
    if(currentHover==-1){
        return new HoverManager(-1,0,hoverState->getKeyboardState(),hoverState->getLastSpecialID(),hoverState->getLastSpecialCount());
    }

    if(hoverState->getLastHoveredID()==currentHover){
        int currentCount=hoverState->getHoveredCount();
        return new HoverManager(currentHover,currentCount+1,hoverState->getKeyboardState(),hoverState->getLastSpecialID(),hoverState->getLastSpecialCount());
    }

    return new HoverManager(currentHover,0,hoverState->getKeyboardState(),hoverState->getLastSpecialID(),hoverState->getLastSpecialCount());



}
void PersonalizeView::updateButtonLook(){
    for(ButtonOperator *btn:menuButtons){
        btn->setText(btn->getDisplayList().at(hoverState->getKeyboardState()));
    }

}
HoverManager *PersonalizeView::executeTimerStep(){
    if(hoverState->getHoveredCount()<*tickCounter){
        return hoverState;
    }

    executeButton();
    return new HoverManager(hoverState->getLastHoveredID(),0,hoverState->getKeyboardState(),hoverState->getLastSpecialID(),hoverState->getLastSpecialCount());


}
HoverManager *PersonalizeView::executeButton(){
      double time;
    switch(hoverState->getLastHoveredID()){
    case EXIT:
        isOpen=false;
        this->close();
        return new HoverManager(hoverState->getLastHoveredID(),0,hoverState->getKeyboardState(),hoverState->getLastSpecialID(),hoverState->getLastSpecialCount());
    case MODE_UP:
        if(currentMod<layoutList.size()-1){
            currentMod++;

        }
        else{
            currentMod=0;

        }
        //ui->modeText->setText(layoutList.at(currentMod).getLayoutName());
        //     ui->listWidget->addItem();
        ui->listWidget->item(currentMod)->setSelected(true);
       setLayout(currentMod);
       this->setPalette(layoutList.at(currentMod).getLayoutBackgroundLook());
      //   qApp->setStyleSheet(layoutList.at(currentMod).getLayouButtonLook());
        return new HoverManager(hoverState->getLastHoveredID(),0,hoverState->getKeyboardState(),hoverState->getLastSpecialID(),hoverState->getLastSpecialCount());
    case MODE_DOWN:

        if(currentMod>0){
            currentMod--;

        }
        else{
            currentMod=layoutList.size()-1;

        }

        ui->listWidget->item(currentMod)->setSelected(true);
        setLayout(currentMod);
        this->setPalette(layoutList.at(currentMod).getLayoutBackgroundLook());
        return new HoverManager(hoverState->getLastHoveredID(),0,hoverState->getKeyboardState(),hoverState->getLastSpecialID(),hoverState->getLastSpecialCount());

    case SIZE_UP:
        textFontSize++;
        ui->lineEdit->setText(QString::number(textFontSize)+"px");
        ui->lineEdit->setStyleSheet("font-size: "+QString::number(textFontSize)+"px;");
        textEdit->setStyleSheet("font-size: "+QString::number(textFontSize)+"px;");
        return new HoverManager(hoverState->getLastHoveredID(),0,hoverState->getKeyboardState(),hoverState->getLastSpecialID(),hoverState->getLastSpecialCount());
    case SIZE_DOWN:
        if(textFontSize!=1){
            textFontSize--;
            ui->lineEdit->setText(QString::number(textFontSize)+"px");
            ui->lineEdit->setStyleSheet("font-size: "+QString::number(textFontSize)+"px;");
            textEdit->setStyleSheet("font-size: "+QString::number(textFontSize)+"px;");}
        return new HoverManager(hoverState->getLastHoveredID(),0,hoverState->getKeyboardState(),hoverState->getLastSpecialID(),hoverState->getLastSpecialCount());
    case TIME_LESS:
        *tickCounter-=TICK_COUNT_STEP;
        if(*tickCounter<TICK_COUNT_MIN)
        {
            *tickCounter=TICK_COUNT_MIN;
        }
         time = *tickCounter*TIMER_TICK/1000.0;
        ui->timeValue->setText(QString::number(time));
           ui->progressBar->setMaximum(*tickCounter);
        return new HoverManager(hoverState->getLastHoveredID(),0,hoverState->getKeyboardState(),hoverState->getLastSpecialID(),hoverState->getLastSpecialCount());
    case TIME_MORE:
        *tickCounter+=TICK_COUNT_STEP;
        if(*tickCounter>TICK_COUNT_MAX)
        {
            *tickCounter=TICK_COUNT_MAX;
        }
         time = *tickCounter*TIMER_TICK/1000.0;
        ui->timeValue->setText(QString::number(time));
           ui->progressBar->setMaximum(*tickCounter);
        return new HoverManager(hoverState->getLastHoveredID(),0,hoverState->getKeyboardState(),hoverState->getLastSpecialID(),hoverState->getLastSpecialCount());

    }

}
void PersonalizeView::setLayout(int id){
    for (int i = 0; i < keyboardButtons.size(); ++i)
    {
        QPushButton *widget = keyboardButtons.at(i);

        widget->setStyleSheet(layoutList.at(id).getLayouButtonLook());

    }
    for (int i = 0; i < menuButtons.size(); ++i)
    {
        QPushButton *widget = menuButtons.at(i);

        widget->setStyleSheet(layoutList.at(id).getLayouButtonLook());
    }

}
void PersonalizeView::setTextEdit(QTextEdit *sTextEdit){
    textEdit=sTextEdit;
}

