#include "mainwindow.h"
#include "ui_mainwindow.h"
#include  <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
  //  connect(ui->zero,SIGNAL(onHover()),ui->textEdit,SLOT(setText()));
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_leave_clicked()
{
    this->close();
}

