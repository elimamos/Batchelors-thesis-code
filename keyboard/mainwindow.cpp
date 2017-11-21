#include "mainwindow.h"
#include "ui_mainwindow.h"
#include  <QPushButton>
#include "buttonoperator.h"
#include <QStringList>
#include<vector>
#include "qroundprogressbar.h"
#include "personalizeview.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    ui->setupUi(this);

    setButtons();


    /*m_button[0] = ui->zero;
   m_button[0]->setIndex(3);
    QStringList qlist;
    qlist.append("ELEMENT1");
    qlist.append("ELEMENT2");
    m_button[0]->setDisplayList(qlist);

    qDebug()<<m_button[0]->getIndex();
    qDebug()<<m_button[0]->getDisplayList().at(1);
    m_button[0]->setText(m_button[0]->getDisplayList().at(1));*/

    //  connect(ui->zero,SIGNAL(onHover()),ui->textEdit,SLOT(setText()));


}
QRoundProgressBar *MainWindow::getProgressBar(){
    return roundProgressBar;
}
void MainWindow::setButtons(){
    textEdit=ui->textBox;
    roundProgressBar=ui->roundprogressbar;
    roundProgressBar->setMaximum(TICK_COUNTER);
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
    setButtonInfo(ui->b12,"e","E","%",":)","ą",false);
    setButtonInfo(ui->b13,"r","R","*",":)","Ć",false);
    setButtonInfo(ui->b14,"t","T","[",":)","ć",false);
    setButtonInfo(ui->b15,"y","Y","]",":)","Ę",false);
    setButtonInfo(ui->b16,"u","U","{",":)","ę",false);
    setButtonInfo(ui->b17,"i","I","}",":)","Ł",false);
    setButtonInfo(ui->b18,"o","O","<",":)","ł",false);
    setButtonInfo(ui->b19,"p","P",">",":)","Ń",false);
    setNoneChangingButton(ui->caps,"",true);
    setButtonInfo(ui->b21,"a","A",":",":)","ń",false);
    setButtonInfo(ui->b22,"s","S",";",":)","Ó",false);
    setButtonInfo(ui->b23,"d","D","_",":)","ó",false);
    setButtonInfo(ui->b24,"f","F","-",":)","Ś",false);
    setButtonInfo(ui->b25,"g","G","#",":)","ś",false);
    setButtonInfo(ui->b26,"h","H","=",":)","Ź",false);
    setButtonInfo(ui->b27,"j","J","(",":)","ź",false);
    setButtonInfo(ui->b28,"k","K",")",":)","Ż",false);
    setButtonInfo(ui->b29,"l","L","/",":)","ż",false);
    setNoneChangingButton(ui->shift,"aA",true);
    setButtonInfo(ui->b31,"z","Z","\\",":)","",false);
    setButtonInfo(ui->b32,"x","X",".",":)","",false);
    setButtonInfo(ui->b33,"c","C",",",":)","",false);
    setButtonInfo(ui->b34,"v","V","?",":)","",false);
    setButtonInfo(ui->b35,"b","B","!",":)","",false);
    setButtonInfo(ui->b36,"n","N","'",":)","",false);
    setButtonInfo(ui->b37,"m","M","\"",":)","",false);
    setButtonInfo(ui->b38,",",",","...",":)","",false);
    setButtonInfo(ui->b39,".",".","$",":)","",false);
    setNoneChangingButton(ui->special,"?!$",true);
    setNoneChangingButton(ui->space," ",false);
    setNoneChangingButton(ui->pl,"ążś",true);

    // setNoneChangingButton(ui->ctrl,"Ctrl",true);
    // setNoneChangingButton(ui->alt,"Alt",true);
    setNoneChangingButton(ui->enter,"\n",false);
    setNoneChangingButton(ui->back,"",true);
    setNoneChangingButton(ui->send,"WYŚLIJ",true);
    setNoneChangingButton(ui->end,"END",true);
    setNoneChangingButton(ui->clear,"CZYŚĆ",true);
    setNoneChangingButton(ui->home,"HOME",true);
    setNoneChangingButton(ui->aLeft,"",true);
    setNoneChangingButton(ui->aUP,"",true);
    setNoneChangingButton(ui->aRight,"",true);
    setNoneChangingButton(ui->aDown,"",true);
    setNoneChangingButton(ui->txt2speech,"",true);
    setNoneChangingButton(ui->menu,"menu",true);
    setNoneChangingButton(ui->hintB1,"",true);
    setNoneChangingButton(ui->hintB2,"",true);
    setNoneChangingButton(ui->hintB3,"",true);
    setNoneChangingButton(ui->hintB4,"",true);
    setNoneChangingButton(ui->leave,"x",true);
    setNoneChangingButton(ui->stop,"START",true);
    hintButtonList.push_back(ui->hintB1);
    hintButtonList.push_back(ui->hintB2);
    hintButtonList.push_back(ui->hintB3);
    hintButtonList.push_back(ui->hintB4);

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
