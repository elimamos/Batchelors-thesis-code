#include "personalizeview.h"
#include "ui_personalizeview.h"
#include "const.h"

PersonalizeView::PersonalizeView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PersonalizeView)
{

    ui->setupUi(this);
    setNoneChangingButton(ui->exit,"1",false);
    setNoneChangingButton(ui->m1,"1",false);
    setNoneChangingButton(ui->m2,"1",false);
    setNoneChangingButton(ui->f1,"1",false);
    setNoneChangingButton(ui->f2,"1",false);
    setNoneChangingButton(ui->mod1,"1",false);
    setNoneChangingButton(ui->mod2,"1",false);
    setNoneChangingButton(ui->mod3,"1",false);
    layoutList.push_back(LayoutLook("Basic","QPushButton {font: 28px arial, sans-serif; "
                                            "border-radius: 28px;font-weight: bold; color: #ffffff;"
                                            "font-weight:bold;background: #9fb5c4;padding: 10px 20px 10px 20px;text-decoration: none; "
                                            "QPushButton:hover{background: #4a6373;    text-decoration: none;}"
                                            "QPushButton#clear {    font-size: 18px;}QPushButton#home {    font-size: 18px;}QPushButton#end { font-size: 18px;}","background-color:black;"));

timer = new QTimer (this);

connect (timer,SIGNAL(timeout()),this, SLOT(TimerStep()));
timer->start(TIMER_TICK);


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


    for (int i = 0; i < ui->items->count(); ++i)
    {
        QWidget *widget = ui->items->itemAt(i)->widget();
        if (widget != NULL)
        {

            if(QPushButton *pb = qobject_cast<QPushButton*>(widget)){
                widget->setStyleSheet("background-color:black;");
            }
        }
        else
        {
            // You may want to recurse, or perform different actions on layouts.
            // See gridLayout->itemAt(i)->layout()
        }
    }


}
void PersonalizeView::setButtonList(vector<ButtonOperator*> buttonList){
    keyboardButtons=buttonList;
}
void PersonalizeView::TimerStep()
{
    int currentHoverID=getHoveredButton();
    if(currentHoverID==1){
        *sendingState=2;
        for (int i = 0; i < keyboardButtons.size(); ++i)
        {
            QWidget *widget = keyboardButtons.at(i);

            widget->setStyleSheet("background-color:black;");
        }
        for (int i = 0; i < menuButtons.size(); ++i)
        {
            QWidget *widget = menuButtons.at(i);

            widget->setStyleSheet("background-color:black;");
        }
    }
    else if(currentHoverID==2){
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
    }
    qDebug()<<currentHoverID;

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
