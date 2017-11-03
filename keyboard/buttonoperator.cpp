#include "buttonoperator.h"
#include "TimeManager.h"
#include <QDebug>


ButtonOperator::ButtonOperator(QWidget *parent):QPushButton(parent)
    {
        setMouseTracking(true);
        setAttribute(Qt::WA_Hover);

    }

    void ButtonOperator::hoverEnter(QHoverEvent *)
    {

      //  qDebug()<<index;

        isHovered=true;
     //   qDebug()<<isHovered;

    }


    void ButtonOperator::hoverLeave(QHoverEvent *)
    {
       // qDebug()<<index;
        isHovered=false;
       // qDebug()<<isHovered;
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
    void ButtonOperator::setIndex(int sIndex){
        index=sIndex;
    }
    int ButtonOperator::getIndex(){
        return index;
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

