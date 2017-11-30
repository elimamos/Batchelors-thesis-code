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
      void setTickCount(int *sTickCount);
      void setTextEdit(QTextEdit *sTextEdit);
      void setIsOpen(bool *isOpen);
      void setWindow(QWidget *sWindow);
      void setCurrentMod(int *mod);


public slots:
    void TimerStep();
private:
    Ui::PersonalizeView *ui;
    vector<ButtonOperator*> keyboardButtons;
    int getHoveredButton();
    vector<LayoutLook> layoutList;
    void setButtonInfo(ButtonOperator *myButton, QString s1,QString s2,QString s3,QString s4,QString s5,bool isSpecial);
    void setNoneChangingButton(ButtonOperator *myButton, QString s1,bool isSpecial);
    int *tickCounter;
    HoverManager *hoverState;
    HoverManager *updateHoverState(int currentHover);
    void updateButtonLook();
    HoverManager *executeTimerStep();
    HoverManager *executeButton();
    int *currentMod;
    void setLayout(int id);
    int textFontSize;
    QTextEdit *textEdit;
    bool *isOpen;
    QWidget *mainWindow;
    //LayoutLook currentLook;



};

#endif // PERSONALIZEVIEW_H
