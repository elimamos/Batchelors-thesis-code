#include "mainwindow.h"
#include "ui_mainwindow.h"
#include  <QPushButton>
#include "buttonoperator.h"
#include <QStringList>
#include<vector>


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
QProgressBar *MainWindow::getProgressBar(){
    return progressBar;
}
void MainWindow::setButtons(){
    textEdit=ui->textBox;
    progressBar=ui->progressBar;
    progressBar->setMaximum(TICK_COUNTER);
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
    setButtonInfo(ui->b10,"q","Q","=",":)","Ą",false);
    setButtonInfo(ui->b11,"w","Q","=",":)","Ą",false);
    setButtonInfo(ui->b12,"e","Q","=",":)","Ą",false);
    setButtonInfo(ui->b13,"r","Q","=",":)","Ą",false);
    setButtonInfo(ui->b14,"t","Q","=",":)","Ą",false);
    setButtonInfo(ui->b15,"y","Q","=",":)","Ą",false);
    setButtonInfo(ui->b16,"u","Q","=",":)","Ą",false);
    setButtonInfo(ui->b17,"i","Q","=",":)","Ą",false);
    setButtonInfo(ui->b18,"o","Q","=",":)","Ą",false);
    setButtonInfo(ui->b19,"p","Q","=",":)","Ą",false);
    setNoneChangingButton(ui->caps,"CapsLock",true);
    setButtonInfo(ui->b21,"a","Q","=",":)","Ą",false);
    setButtonInfo(ui->b22,"s","Q","=",":)","Ą",false);
    setButtonInfo(ui->b23,"d","Q","=",":)","Ą",false);
    setButtonInfo(ui->b24,"f","Q","=",":)","Ą",false);
    setButtonInfo(ui->b25,"g","Q","=",":)","Ą",false);
    setButtonInfo(ui->b26,"h","Q","=",":)","Ą",false);
    setButtonInfo(ui->b27,"j","Q","=",":)","Ą",false);
    setButtonInfo(ui->b28,"k","Q","=",":)","Ą",false);
    setButtonInfo(ui->b29,"l","Q","=",":)","Ą",false);
    setNoneChangingButton(ui->shift,"aA",true);
    setButtonInfo(ui->b31,"z","Q","=",":)","Ą",false);
    setButtonInfo(ui->b32,"x","Q","=",":)","Ą",false);
    setButtonInfo(ui->b33,"c","Q","=",":)","Ą",false);
    setButtonInfo(ui->b34,"v","Q","=",":)","Ą",false);
    setButtonInfo(ui->b35,"b","Q","=",":)","Ą",false);
    setButtonInfo(ui->b36,"n","Q","=",":)","Ą",false);
    setButtonInfo(ui->b37,"m","Q","=",":)","Ą",false);
    setButtonInfo(ui->b38,",","Q","=",":)","Ą",false);
    setButtonInfo(ui->b39,".","Q","=",":)","Ą",false);
    setNoneChangingButton(ui->pl,"ążś",true);
    setNoneChangingButton(ui->special,"?!$",true);
   // setNoneChangingButton(ui->ctrl,"Ctrl",true);
    setNoneChangingButton(ui->space," ",false);
   // setNoneChangingButton(ui->alt,"Alt",true);
    setNoneChangingButton(ui->enter,"\n",false);
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
