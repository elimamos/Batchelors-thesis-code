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
   TimeManager(std::vector<ButtonOperator*> sButtonList,QTextEdit *sTextEdit,QProgressBar *sProgressBar);
    QTimer *timer;
    HoverManager *updateHoverState(int currentHover);



    void startTimer();
private:
    HoverManager *hoverState;
    std::vector<ButtonOperator*> buttonList;
    QTextEdit *textEdit;
    QProgressBar *progressBar;
    int getHoveredButton();
    HoverManager *executeTimerStep();
    HoverManager *executeSpecialButton();
    void executeNormalButton();
    void updateButtonLook();



public slots:
    void TimerStep();
};

#endif // MYTIMER_H
