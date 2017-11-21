#ifndef PERSONALIZEVIEW_H
#define PERSONALIZEVIEW_H
#include"buttonoperator.h"
#include <QWidget>
#include"layoutlook.h"
#include "hovermanager.h"

using namespace std;
namespace Ui {
class PersonalizeView;
}

class PersonalizeView : public QWidget
{
    Q_OBJECT

public:
    explicit PersonalizeView(QWidget *parent = 0);
    ~PersonalizeView();
     QTimer *timer;
     vector<ButtonOperator*> menuButtons;
      void setButtonList(vector<ButtonOperator*> buttonList);
      void setSendingState(int *sSendingState);
private slots:
    void on_pushButton_clicked();

public slots:
    void TimerStep();
private:
    Ui::PersonalizeView *ui;
    vector<ButtonOperator*> keyboardButtons;
    int getHoveredButton();
    vector<LayoutLook> layoutList;
    void setButtonInfo(ButtonOperator *myButton, QString s1,QString s2,QString s3,QString s4,QString s5,bool isSpecial);
    void setNoneChangingButton(ButtonOperator *myButton, QString s1,bool isSpecial);
    int *sendingState;
    HoverManager *hoverState;
    HoverManager *updateHoverState(int currentHover);
    void updateButtonLook();
    HoverManager *executeTimerStep();
    HoverManager *executeButton();
    int currentMod;
    void setLayout(int id);

};

#endif // PERSONALIZEVIEW_H
