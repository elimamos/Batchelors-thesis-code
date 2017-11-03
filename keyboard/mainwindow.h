#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"buttonoperator.h"
#include<QString>
#include"const.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    ButtonOperator *getButtonList();
    QTextEdit *getTextEdit ();
private slots:
    void on_leave_clicked();


private:
    Ui::MainWindow *ui;
    ButtonOperator *buttonList[BUTTON_COUNT];
    QTextEdit *textEdit;
    void setButtons();
    void setButtonInfo(ButtonOperator *myButton,int index, QString s1,QString s2,QString s3,QString s4,QString s5, bool isSpecial);
    void setNoneChangingButton(ButtonOperator *myButton,int index, QString s1, bool isSpecial);

};

#endif // MAINWINDOW_H
