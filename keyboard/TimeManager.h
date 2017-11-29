#ifndef MYTIMER_H
#define MYTIMER_H

#include <QtCore>
#include"buttonoperator.h"
#include "hovermanager.h"
#include<vector>

#include"dictionary.h"
#include "googlesearcher.h"
#include"personalizeview.h"
#include"layoutlook.h"
class QUdpSocket;
using namespace std;
class TimeManager : public QObject
{

    Q_OBJECT
public:
    TimeManager(std::vector<ButtonOperator*> sButtonList,QTextEdit *sTextEdit,QProgressBar *sProgressBar ,std::vector<ButtonOperator*> sHintButtonList);
    void startTimer();
    HoverManager *updateHoverState(int currentHover);
    bool stop;
    QTimer *timer;

private:

    HoverManager *executeTimerStep();
    HoverManager *executeSpecialButton();
    HoverManager *executeNormalButton();
    void updateButtonLook();
    void verifyTimerTickCount();
    int getHoveredButton();

    HoverManager *hoverState;
    std::vector<ButtonOperator*> buttonList;
    std::vector<ButtonOperator*> hintButtonList;
    QTextEdit *textEdit;
    QProgressBar *progressBar;
    Dictionary *dictionary;
    GoogleSearcher *googler;
    PersonalizeView *personalize;
    QUdpSocket *udpSocket;
    QByteArray datagram;
    map < int , QString > sendingPossibilities;
    int ticksSinceLastChange;
    int backspaceCount;
    bool menuIsOpen;
    int layoutMod;
    bool isSending;
    int tickCounter;
    int sendingState;

public slots:
    void TimerStep();
};

#endif // MYTIMER_H
