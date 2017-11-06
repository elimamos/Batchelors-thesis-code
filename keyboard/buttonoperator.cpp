#include "buttonoperator.h"
#include "TimeManager.h"
#include <QDebug>


ButtonOperator::ButtonOperator(QWidget *parent):QPushButton(parent)
{
    setMouseTracking(true);
    setAttribute(Qt::WA_Hover);
    isHovered=false;

}

void ButtonOperator::hoverEnter(QHoverEvent *)
{
    this->update();
    isHovered=true;
}


void ButtonOperator::hoverLeave(QHoverEvent *)
{
    this->update();
    isHovered=false;
}

void ButtonOperator::hoverMove(QHoverEvent *)
{

}

bool ButtonOperator::event(QEvent *event)
{
    switch(event->type())
    {
    case QEvent::HoverEnter:
        hoverEnter(static_cast<QHoverEvent*>(event));
        return true;
        break;
    case QEvent::HoverLeave:
        hoverLeave(static_cast<QHoverEvent*>(event));
        return true;
        break;
    case QEvent::HoverMove:
        hoverMove(static_cast<QHoverEvent*>(event));
        return true;
        break;
    default:
        break;
    }
    return QWidget::event(event);
}

QStringList ButtonOperator::getDisplayList(){
    return displayList;
}
void ButtonOperator::setDisplayList(QStringList sDisplayList){
    displayList=sDisplayList;
}
void ButtonOperator::setSpecial(bool sIsSpecial){
    isSpecial=sIsSpecial;
}
bool ButtonOperator::getSpecial(){
    return isSpecial;
}
bool ButtonOperator::getHover(){
    return isHovered;
}

