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
    setNoneChangingButton(ui->mod1,"Wiadomość",false);
    setNoneChangingButton(ui->mod2,"Google",false);
    setNoneChangingButton(ui->mod3,"Filmweb",false);
    QPalette pal =this->palette();
    pal.setColor(QPalette::Background, "#343434");
    QPalette pal2 = this->palette();
    pal2.setColor(QPalette::Background,Qt::red);
    QString look ="QPushButton {font: 28px arial, sans-serif; border-radius: 28px; font-weight: bold;color: #ffffff;font-weight:bold; background: #9fb5c4; padding: 10px 20px 10px 20px;text-decoration: none;} ";
    look +="QPushButton:hover{ background: #4a6373; text-decoration: none;}";
  layoutList.push_back(LayoutLook(QString("Basic"),look,pal));
    layoutList.push_back(LayoutLook(QString("Light"),look,pal2));
  ui->listWidget->addItem(layoutList.at(0).getLayoutName());
  ui->listWidget->addItem(layoutList.at(1).getLayoutName());
  ui->listWidget->item(0)->setSelected(true);
//  ui->listWidget->sortItems(Qt::DescendingOrder);
    ui->progressBar->setMaximum(TICK_COUNTER);
    timer = new QTimer (this);

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
void PersonalizeView::setNoneChangingButton(ButtonOperator *myButton, QString s1,bool isSpecial){
    setButtonInfo(myButton,s1,s1,s1,s1,s1,isSpecial);
}
PersonalizeView::~PersonalizeView()
{
    delete ui;

}

void PersonalizeView::on_pushButton_clicked()
{



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

    /*  if(currentHoverID==1){

        //  *sendingState=2;
        for (int i = 0; i < keyboardButtons.size(); ++i)
        {
            QWidget *widget = keyboardButtons.at(i);

            widget->setStyleSheet("QPushButton {font: 28px arial, sans-serif; border-radius: 28px;font-weight: bold; color: #ffffff;font-weight:bold;background: #9fb5c4;padding: 10px 20px 10px 20px;text-decoration: none;QPushButton:hover{background: #4a6373;    text-decoration: none;}QPushButton#clear {font-size: 18px;}QPushButton#home {    font-size: 18px;}QPushButton#end { font-size: 18px;},background-color:black;");
        }/*
        for (int i = 0; i < menuButtons.size(); ++i)
        {
            QWidget *widget = menuButtons.at(i);

            widget->setStyleSheet("background-color:black;");
        }*/
    //}
    /* else if(currentHoverID==2){
        for (int i = 0; i < keyboardButtons.size(); ++i)
        {
            QWidget *widget = keyboardButtons.at(i);

            widget->setStyleSheet(layoutList.at(0).getLayouButtonLook());
        }
        for (int i = 0; i < menuButtons.size(); ++i)
        {
            QWidget *widget = menuButtons.at(i);

            widget->setStyleSheet(layoutList.at(0).getLayouButtonLook());
        }
    }*/
//    qDebug()<<currentHoverID;

}
void PersonalizeView::setSendingState(int *sSendingState){
    sendingState=sSendingState;

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
    if(hoverState->getHoveredCount()<TICK_COUNTER){
        return hoverState;
    }

    executeButton();
    return new HoverManager(hoverState->getLastHoveredID(),0,hoverState->getKeyboardState(),hoverState->getLastSpecialID(),hoverState->getLastSpecialCount());


}
HoverManager *PersonalizeView::executeButton(){
    switch(hoverState->getLastHoveredID()){
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
        return new HoverManager(hoverState->getLastHoveredID(),0,hoverState->getKeyboardState(),hoverState->getLastSpecialID(),hoverState->getLastSpecialCount());
    case MODE_DOWN:

        if(currentMod>1){
            currentMod--;

        }
        else{
            currentMod=0;

        }

        ui->listWidget->item(currentMod)->setSelected(true);
        setLayout(currentMod);
         this->setPalette(layoutList.at(currentMod).getLayoutBackgroundLook());
        return new HoverManager(hoverState->getLastHoveredID(),0,hoverState->getKeyboardState(),hoverState->getLastSpecialID(),hoverState->getLastSpecialCount());
    }

}
void PersonalizeView::setLayout(int id){
    for (int i = 0; i < keyboardButtons.size(); ++i)
    {
        QWidget *widget = keyboardButtons.at(i);

        widget->setStyleSheet(layoutList.at(id).getLayouButtonLook());

    }
    for (int i = 0; i < menuButtons.size(); ++i)
    {
        QWidget *widget = menuButtons.at(i);

        widget->setStyleSheet(layoutList.at(id).getLayouButtonLook());
    }

}
