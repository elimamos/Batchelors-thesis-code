#ifndef MYTIMER_H
#define MYTIMER_H

#include <QtCore>
#include"buttonoperator.h"
#include "hovermanager.h"
#include<vector>

class TimeManager : public QObject
{

    Q_OBJECT
public:
   TimeManager(std::vector<ButtonOperator*> sButtonList,QTextEdit *sTextEdit);
    QTimer *timer;


    void startTimer();
private:
    HoverManager *previousHover;
    std::vector<ButtonOperator*> buttonList;
    QTextEdit *textEdit;
    int getHoveredButton();

public slots:
    void TimerStep();
};

#endif // MYTIMER_H
