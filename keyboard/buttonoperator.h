#ifndef BUTTONOPERATOR_H
#define BUTTONOPERATOR_H
using namespace std;
#include <QtWidgets>
#include <QStringList>




class ButtonOperator : public QPushButton
{
    Q_OBJECT

public:
    explicit ButtonOperator(QWidget *parent=0);
    void setDisplayList(QStringList sDisplayList);
    QStringList getDisplayList();
    void setSpecial(bool sIsSpecial);
    bool getSpecial();
    bool getHover();


protected:
    void hoverEnter(QHoverEvent *event);
    void hoverLeave(QHoverEvent *event);
    void hoverMove(QHoverEvent *event);
    bool event(QEvent *event);

private:
    bool isSpecial;
    bool isHovered;

    QStringList displayList;

};


#endif // BUTTONOPERATOR_H
