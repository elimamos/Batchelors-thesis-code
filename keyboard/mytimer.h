#ifndef MYTIMER_H
#define MYTIMER_H

#include <QtCore>
#include"buttonoperator.h"

class myTimer : public QObject
{

    Q_OBJECT
public:
    myTimer(ButtonOperator *sButtonList,QTextEdit *sTextEdit);
    QTimer *timer;

    void startTimer();
private:
    ButtonOperator *buttonList;
    QTextEdit *textEdit;
public slots:
    void TimerStep();
};

#endif // MYTIMER_H
