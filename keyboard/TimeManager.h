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
    QTimer *timer;
    HoverManager *updateHoverState(int currentHover);
    bool stop;


    void startTimer();
private:
    HoverManager *hoverState;
    std::vector<ButtonOperator*> buttonList;
    std::vector<ButtonOperator*> hintButtonList;
    QTextEdit *textEdit;
    QProgressBar *progressBar;
    int getHoveredButton();
    HoverManager *executeTimerStep();
    HoverManager *executeSpecialButton();
   HoverManager *executeNormalButton();
    void updateButtonLook();
    Dictionary *dictionary;
    bool isSending;
    GoogleSearcher *googler;
    PersonalizeView *personalize;
    int sendingState;
    QUdpSocket *udpSocket;
    QByteArray datagram;
    int tickCounter;
    map < int , QString > sendingPossibilities;
    void verifyTimerTickCount();
    int ticksSinceLastChange;
    int backspaceCount;
    bool menuIsOpen;
    int layoutMod;




public slots:
    void TimerStep();
};

#endif // MYTIMER_H
