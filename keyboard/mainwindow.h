#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"buttonoperator.h"
#include<QString>
#include"const.h"
#include<vector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    std::vector<ButtonOperator*> getButtonList();
    QTextEdit *getTextEdit ();
private slots:
    void on_leave_clicked();


private:
    Ui::MainWindow *ui;
    std::vector<ButtonOperator*> buttonList;
    QTextEdit *textEdit;
    void setButtons();
    void setButtonInfo(ButtonOperator *myButton,int index, QString s1,QString s2,QString s3,QString s4,QString s5, bool isSpecial);
    void setNoneChangingButton(ButtonOperator *myButton,int index, QString s1, bool isSpecial);

};

#endif // MAINWINDOW_H
