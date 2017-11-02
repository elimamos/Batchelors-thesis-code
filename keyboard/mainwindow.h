#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"buttonoperator.h"
#include<QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_leave_clicked();


private:
    Ui::MainWindow *ui;
    ButtonOperator *buttonList[10];
    void setButtons();
    void setButtonInfo(ButtonOperator *myButton,int index, QString s1,QString s2,QString s3,QString s4,QString s5);
    void setNoneChangingButton(ButtonOperator *myButton,int index, QString s1);
};

#endif // MAINWINDOW_H
