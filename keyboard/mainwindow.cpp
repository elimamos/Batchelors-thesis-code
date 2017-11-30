#include "mainwindow.h"
#include "ui_mainwindow.h"
#include  <QPushButton>
#include "buttonoperator.h"
#include <QStringList>
#include<vector>

#include "personalizeview.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    ui->setupUi(this);

    setButtons();


}
QProgressBar *MainWindow::getProgressBar(){
    return progressBar;
}
void MainWindow::setButtons(){
    textEdit=ui->textBox;
    progressBar=ui->progressBar;
    progressBar->setMaximum(STARTING_COUNT);
    setNoneChangingButton(ui->b1,"1",false);
    setNoneChangingButton(ui->b2,"2",false);
    setNoneChangingButton(ui->b3,"3",false);
    setNoneChangingButton(ui->b4,"4",false);
    setNoneChangingButton(ui->b5,"5",false);
    setNoneChangingButton(ui->b6,"6",false);
    setNoneChangingButton(ui->b7,"7",false);
    setNoneChangingButton(ui->b8,"8",false);
    setNoneChangingButton(ui->b9,"9",false);
    setNoneChangingButton(ui->b0,"0",false);
    setButtonInfo(ui->b10,"q","Q","=","","",false);
    setButtonInfo(ui->b11,"w","W","+",":)","Ą",false);
    setButtonInfo(ui->b12,"e","E","%",";)","ą",false);
    setButtonInfo(ui->b13,"r","R","*",":(","Ć",false);
    setButtonInfo(ui->b14,"t","T","[",":o","ć",false);
    setButtonInfo(ui->b15,"y","Y","]",":D","Ę",false);
    setButtonInfo(ui->b16,"u","U","{",":P","ę",false);
    setButtonInfo(ui->b17,"i","I","}",":S","Ł",false);
    setButtonInfo(ui->b18,"o","O","<",":x","ł",false);
    setButtonInfo(ui->b19,"p","P",">","B)","Ń",false);
    setNoneChangingButton(ui->caps,"",true);
    setButtonInfo(ui->b21,"a","A",":","<3","ń",false);
    setButtonInfo(ui->b22,"s","S",";","</3","Ó",false);
    setButtonInfo(ui->b23,"d","D","_",":/","ó",false);
    setButtonInfo(ui->b24,"f","F","-","T__T","Ś",false);
    setButtonInfo(ui->b25,"g","G","#",";<","ś",false);
    setButtonInfo(ui->b26,"h","H","=",":>","Ź",false);
    setButtonInfo(ui->b27,"j","J","(",">:(","ź",false);
    setButtonInfo(ui->b28,"k","K",")",":*","Ż",false);
    setButtonInfo(ui->b29,"l","L","/","XD","ż",false);
    setNoneChangingButton(ui->shift,"aA",true);
    setButtonInfo(ui->b31,"z","Z","\\","xd","",false);
    setButtonInfo(ui->b32,"x","X",".",":c","",false);
    setButtonInfo(ui->b33,"c","C",",","D:","",false);
    setButtonInfo(ui->b34,"v","V","?","*_*","",false);
    setButtonInfo(ui->b35,"b","B","!","^^","",false);
    setButtonInfo(ui->b36,"n","N","'","O:)","",false);
    setButtonInfo(ui->b37,"m","M","\"",";D","",false);
    setButtonInfo(ui->b38,",",",","...",":))","",false);
    setButtonInfo(ui->b39,".",".","$",";(","",false);
    setNoneChangingButton(ui->special,"?!$",true);
    setNoneChangingButton(ui->space," ",false);
    setNoneChangingButton(ui->pl,"ążś",true);
    setNoneChangingButton(ui->enter,"\n",false);
    setNoneChangingButton(ui->back,"",true);
    setNoneChangingButton(ui->send,"WYŚLIJ",true);
    setNoneChangingButton(ui->end,"END",true);
    setNoneChangingButton(ui->clear,"CZYŚĆ",true);
    setNoneChangingButton(ui->home,"HOME",true);
    setNoneChangingButton(ui->aLeft,"",true);

    setNoneChangingButton(ui->aRight,"",true);

    setNoneChangingButton(ui->txt2speech,"",true);
    setNoneChangingButton(ui->menu,"",true);
    setNoneChangingButton(ui->hintB1,"",true);
    setNoneChangingButton(ui->hintB2,"",true);
    setNoneChangingButton(ui->hintB3,"",true);
    setNoneChangingButton(ui->hintB4,"",true);
    setNoneChangingButton(ui->leave,"x",true);
    setNoneChangingButton(ui->stop,"START",true);
    setNoneChangingButton(ui->sendingLeft,"",true);
    setNoneChangingButton(ui->sendingType,"Google",true);
    setNoneChangingButton(ui->sendingRight,"",true);
    setNoneChangingButton(ui->previous,"",true);
    setNoneChangingButton(ui->next,"",true);
    setNoneChangingButton(ui->ctrl,"Ctrl",true);
    setNoneChangingButton(ui->alt,"Alt",true);
    hintButtonList.push_back(ui->hintB1);
    hintButtonList.push_back(ui->hintB2);
    hintButtonList.push_back(ui->hintB3);
    hintButtonList.push_back(ui->hintB4);

}

QWidget *MainWindow::getMainWidget(){
    return ui->centralWidget;
}

std::vector<ButtonOperator*> MainWindow::getHintButtonList(){
    return hintButtonList;
}
std::vector<ButtonOperator*> MainWindow::getButtonList(){
    return buttonList;
}

void MainWindow::setButtonInfo(ButtonOperator *myButton, QString s1,QString s2,QString s3,QString s4,QString s5,bool isSpecial){
    QStringList myList;
    myList.append(s1);
    myList.append(s2);
    myList.append(s3);
    myList.append(s4);
    myList.append(s5);
    if(isSpecial){
        myList.append(s5);
    }else{
        myList.append("");}
    myButton->setDisplayList(myList);
    myButton->setSpecial(isSpecial);
    buttonList.push_back(myButton);



}
void MainWindow::setNoneChangingButton(ButtonOperator *myButton, QString s1,bool isSpecial){
    setButtonInfo(myButton,s1,s1,s1,s1,s1,isSpecial);
}
QTextEdit *MainWindow::getTextEdit()
{
    return textEdit;
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_leave_clicked()
{
    this->close();
}

void MainWindow::on_menu_clicked()
{


}

void MainWindow::on_textBox_textChanged()
{

}
