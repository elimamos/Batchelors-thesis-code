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

    QPalette pal1 =this->palette();

    pal1.setColor(QPalette::Background, "#343434");
    QString label1="color:#ffffff";
    QString stop="QPushButton {font: 28px arial, sans-serif;  border-radius: 28px; font-weight: bold; color: #ffffff;font-weight:bold; background: #4a6373;padding: 10px 20px 10px 20px; text-decoration: none;}";
    stop+="QPushButton:hover{ background: #4a6373;text-decoration: none;}";
    stop+="QPushButton#clear { font-size: 18px;} QPushButton#home {  font-size: 18px; }  QPushButton#end { font-size: 18px; }  QPushButton:checked{  background: #4a6373;text-decoration: none;}QPushButton#menu{ background: #FBBDA6; text-decoration: none;}   QPushButton:focus { outline: none;}";
    QString buttonLook1 ="QPushButton {font: 28px arial, sans-serif;  border-radius: 28px; font-weight: bold; color: #ffffff;font-weight:bold; background: #9fb5c4;padding: 10px 20px 10px 20px; text-decoration: none;}";
    buttonLook1+="QPushButton:hover{ background: #4a6373;text-decoration: none;}";
    buttonLook1+="QPushButton#clear { font-size: 18px;} QPushButton#home {  font-size: 18px; }  QPushButton#end { font-size: 18px; }  QPushButton:checked{  background: #4a6373;text-decoration: none;}QPushButton#menu{ background: #FBBDA6; text-decoration: none;}   QPushButton:focus { outline: none;}";
    QString progressBarLook1="QProgressBar{ border: 2px solid #343434;  border-radius: 5px;  text-align: center; color: #343434;  } QProgressBar::chunk { background-color: #FBBDA6; }";
    QString textEditLook1="QTextEdit{ min-height: 10px;  min-width: 100px; border-radius: 28px; font-family: Arial; font-size: 20px; background:  #ffffff; padding: 10px 20px 10px 20px;text-decoration: none;}";
    layoutList.push_back(LayoutLook(QString("Basic"),buttonLook1,pal1,progressBarLook1,textEditLook1,label1,stop));

    QPalette pal2 =this->palette();
    pal2.setColor(QPalette::Background, "#4C4243");
    QString label2="color:#fae596";
    QString buttonLook2 ="QPushButton { font: 28px arial, sans-serif; border-radius: 28px; font-weight: bold; color: #fae596;font-weight:bold;  background: #312c32; padding: 10px 20px 10px 20px;text-decoration: none;}";
    buttonLook2+="   QPushButton:hover{ background:#8F7F89;  text-decoration: none; }  QPushButton#clear {  font-size: 18px; }   QPushButton#home { font-size: 18px;}";
    buttonLook2+="QPushButton#end {   font-size: 18px;} QPushButton:checked{background: #8F7F89;text-decoration: none; } QPushButton#menu{ background: #fae596;text-decoration: none;} QPushButton:focus { outline: none;}";
    QString stop2 ="QPushButton { font: 28px arial, sans-serif; border-radius: 28px; font-weight: bold; color: #fae596;font-weight:bold;  background: #8F7F89; padding: 10px 20px 10px 20px;text-decoration: none;}";
    stop2+="   QPushButton:hover{ background:#8F7F89;  text-decoration: none; }  QPushButton#clear {  font-size: 18px; }   QPushButton#home { font-size: 18px;}";
    stop2+="QPushButton#end {   font-size: 18px;} QPushButton:checked{background: #8F7F89;text-decoration: none; } QPushButton#menu{ background: #fae596;text-decoration: none;} QPushButton:focus { outline: none;}";

    QString progressBarLook2="QProgressBar{ border: 2px solid #343434;border-radius: 5px; text-align: center;  color: #343434; } QProgressBar::chunk { background-color: #fae596;}";
    QString textEditLook2="QTextEdit{min-height: 10px; min-width: 100px;  border-radius: 28px; font-family: Arial;font-size: 20px;background:  #ffffff; padding: 10px 20px 10px 20px; text-decoration: none;}";
    layoutList.push_back(LayoutLook(QString("Dark"),buttonLook2,pal2, progressBarLook2,textEditLook2,label2,stop2));

    QPalette pal3 =this->palette();
    QString label3="color:#334431";
    pal3.setColor(QPalette::Background, "#ffffff");
    QString buttonLook3 ="QPushButton {font: 28px arial, sans-serif;  border-radius: 28px; font-weight: bold; color: #ffffff;font-weight:bold;background: #B3BDB4;padding: 10px 20px 10px 20px; text-decoration: none;  } QPushButton:hover{ background:#7C9979; text-decoration: none; }  QPushButton#clear { font-size: 18px; }";
    buttonLook3 +=" QPushButton#home {font-size: 18px; } QPushButton#end { font-size: 18px;      } QPushButton:checked{background: #7C9979; text-decoration: none;} QPushButton#menu{  background: #334431; text-decoration: none;} QPushButton:focus { outline: none; }";
    QString stop3 ="QPushButton {font: 28px arial, sans-serif;  border-radius: 28px; font-weight: bold; color: #ffffff;font-weight:bold;background: #7C9979;padding: 10px 20px 10px 20px; text-decoration: none;  } QPushButton:hover{ background:#7C9979; text-decoration: none; }  QPushButton#clear { font-size: 18px; }";
    stop3 +=" QPushButton#home {font-size: 18px; } QPushButton#end { font-size: 18px;      } QPushButton:checked{background: #7C9979; text-decoration: none;} QPushButton#menu{  background: #334431; text-decoration: none;} QPushButton:focus { outline: none; }";

    QString progressBarLook3="QProgressBar{ border: 2px solid #343434;  border-radius: 5px; text-align: center; color: #963019; }  QProgressBar::chunk {       background-color: #334431; }";
    QString textEditLook3="QTextEdit{ min-height: 10px; min-width: 100px; border-radius: 28px; font-family: Arial; font-size: 20px;  background:  #ffffff;  padding: 10px 20px 10px 20px; text-decoration: none;border: 2px solid #343434;   }";
    layoutList.push_back(LayoutLook(QString("Light"),buttonLook3,pal3 ,progressBarLook3,textEditLook3,label3,stop3));

    QPalette pal4 =pal3;
    QString label4="color:#173e43";
    QString buttonLook4 ="QPushButton { font: 28px arial, sans-serif;    border-radius: 28px; font-weight: bold; color: #ffffff;  font-weight:bold;   background: #173e43; padding: 10px 20px 10px 20px; text-decoration: none;} QPushButton:hover{background:#3fb0ac;text-decoration: none; }QPushButton#clear {font-size: 18px;} QPushButton#home { font-size: 18px; }QPushButton#end { font-size: 18px; }";
    buttonLook4+="QPushButton:checked{background: #3fb0ac;text-decoration: none;}QPushButton#menu{background: #fae596;text-decoration: none;}QPushButton:focus {outline: none;}";
    QString stop4 ="QPushButton { font: 28px arial, sans-serif;    border-radius: 28px; font-weight: bold; color: #ffffff;  font-weight:bold;   background: #3fb0ac; padding: 10px 20px 10px 20px; text-decoration: none;} QPushButton:hover{background:#3fb0ac;text-decoration: none; }QPushButton#clear {font-size: 18px;} QPushButton#home { font-size: 18px; }QPushButton#end { font-size: 18px; }";
    stop4+="QPushButton:checked{background: #3fb0ac;text-decoration: none;}QPushButton#menu{background: #fae596;text-decoration: none;}QPushButton:focus {outline: none;}";
    QString progressBarLook4="QProgressBar{border: 2px solid #343434;border-radius: 5px;text-align: center;color: #000000;}QProgressBar::chunk {background-color: #fae596;}";
    QString textEditLook4="QTextEdit{min-height: 10px;min-width: 100px;border-radius: 28px;font-family: Arial;font-size: 20px;background:  #ffffff;padding: 10px 20px 10px 20px;text-decoration: none;border: 2px solid #343434;}";
    layoutList.push_back(LayoutLook(QString("Modern"),buttonLook4,pal4 ,progressBarLook4,textEditLook4,label4,stop4));

    QPalette pal5=this->palette();
    QString label5="color:#5F0015";
    pal5.setColor(QPalette::Background, "#FFF5E5");
    QString buttonLook5 ="QPushButton {font: 28px arial, sans-serif;border-radius: 28px;font-weight: bold; color: #ffffff;font-weight:bold;background: #5F0015;padding: 10px 20px 10px 20px;text-decoration: none;}QPushButton:hover{background:#6F2839;text-decoration: none;}QPushButton#clear {font-size: 18px;}QPushButton#home {font-size: 18px;}QPushButton#end {font-size: 18px;}QPushButton:checked{background: #6F2839;text-decoration: none;}QPushButton#menu{background: #2F4B5E;text-decoration: none;}";
    buttonLook5+="QPushButton:focus {outline: none;}";
    QString stop5 ="QPushButton {font: 28px arial, sans-serif;border-radius: 28px;font-weight: bold; color: #ffffff;font-weight:bold;background: #6F2839;padding: 10px 20px 10px 20px;text-decoration: none;}QPushButton:hover{background:#6F2839;text-decoration: none;}QPushButton#clear {font-size: 18px;}QPushButton#home {font-size: 18px;}QPushButton#end {font-size: 18px;}QPushButton:checked{background: #6F2839;text-decoration: none;}QPushButton#menu{background: #2F4B5E;text-decoration: none;}";
    stop5+="QPushButton:focus {outline: none;}";
    QString progressBarLook5="QProgressBar{border: 2px solid #343434;border-radius: 5px;text-align: center;color: #000000;}QProgressBar::chunk {background-color: #2F4B5E;}";
    QString textEditLook5="QTextEdit{    min-height: 10px;min-width: 100px;border-radius: 28px;font-family: Arial;font-size: 20px;background:  #ffffff;padding: 10px 20px 10px 20px;text-decoration: none;border: 2px solid #343434;}";
    layoutList.push_back(LayoutLook(QString("Wine"),buttonLook5,pal5 ,progressBarLook5,textEditLook5,label5,stop5));


    ui->listWidget->addItem(layoutList.at(0).getLayoutName());
    ui->listWidget->addItem(layoutList.at(1).getLayoutName());
    ui->listWidget->addItem(layoutList.at(2).getLayoutName());
    ui->listWidget->addItem(layoutList.at(3).getLayoutName());
    ui->listWidget->addItem(layoutList.at(4).getLayoutName());
    ui->listWidget->item(0)->setSelected(true);

    //currentLook=layoutList.at(0);

    ui->progressBar->setStyleSheet(layoutList.at(0).getprogressBarLook());

    setLayout(0);

    this->setPalette(layoutList.at(0).getLayoutBackgroundLook());
    ui->label->setStyleSheet(layoutList.at(0).getLabelLook());
    ui->label_2->setStyleSheet(layoutList.at(0).getLabelLook());

    ui->label_3->setStyleSheet(layoutList.at(0).getLabelLook());


    ui->progressBar->setMaximum(STARTING_COUNT);
    timer = new QTimer (this);
    textFontSize=20;
    ui->lineEdit->setText(QString::number(textFontSize)+"px");
    ui->lineEdit->setStyleSheet("font-size: "+QString::number(textFontSize)+"px;");
    ui->lineEdit->setAlignment(Qt::AlignCenter);

    connect (timer,SIGNAL(timeout()),this, SLOT(TimerStep()));
    timer->start(TIMER_TICK);
    hoverState= new HoverManager(-1, -1, 0,-1,0);
    ui->timeValue->setAlignment(Qt::AlignCenter);
    ui->timeValue->setStyleSheet("font-size: "+QString::number(textFontSize)+"px;");
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
void PersonalizeView::setIsOpen(bool *sIsOpen){
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
        *isOpen=false;
        this->close();
        return new HoverManager(hoverState->getLastHoveredID(),0,hoverState->getKeyboardState(),hoverState->getLastSpecialID(),hoverState->getLastSpecialCount());
    case MODE_UP:

        if(*currentMod>0){
            *currentMod-=1;

        }
        else{
            *currentMod=layoutList.size()-1;

        }
        ui->listWidget->item(*currentMod)->setSelected(true);
        setLayout(*currentMod);
        textEdit->setStyleSheet(layoutList.at(*currentMod).getTextEditLook());
        this->setPalette(layoutList.at(*currentMod).getLayoutBackgroundLook());
        mainWindow->setStyleSheet(layoutList.at(*currentMod).getprogressBarLook());
        mainWindow->setPalette(layoutList.at(*currentMod).getLayoutBackgroundLook());
        ui->label->setStyleSheet(layoutList.at(*currentMod).getLabelLook());
        ui->label_2->setStyleSheet(layoutList.at(*currentMod).getLabelLook());

        ui->label_3->setStyleSheet(layoutList.at(*currentMod).getLabelLook());


        return new HoverManager(hoverState->getLastHoveredID(),0,hoverState->getKeyboardState(),hoverState->getLastSpecialID(),hoverState->getLastSpecialCount());
    case MODE_DOWN:
        if(*currentMod<layoutList.size()-1){
            *currentMod+=1;
        }
        else{
            *currentMod=0;

        }
        textEdit->setStyleSheet(layoutList.at(*currentMod).getTextEditLook());
        ui->listWidget->item(*currentMod)->setSelected(true);
        setLayout(*currentMod);
        mainWindow->setStyleSheet(layoutList.at(*currentMod).getprogressBarLook());
        ui->progressBar->setStyleSheet(layoutList.at(*currentMod).getprogressBarLook());
        this->setPalette(layoutList.at(*currentMod).getLayoutBackgroundLook());
        mainWindow->setPalette(layoutList.at(*currentMod).getLayoutBackgroundLook());
        ui->label->setStyleSheet(layoutList.at(*currentMod).getLabelLook());
        ui->label_2->setStyleSheet(layoutList.at(*currentMod).getLabelLook());

        ui->label_3->setStyleSheet(layoutList.at(*currentMod).getLabelLook());


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
void PersonalizeView::setWindow(QWidget *sWindow){
    mainWindow=sWindow;
}
void PersonalizeView::setCurrentMod(int *mod){
    currentMod=mod;
}
