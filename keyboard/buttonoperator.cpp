#include "buttonoperator.h"
#include "mytimer.h"
#include <QDebug>


ButtonOperator::ButtonOperator(QWidget *parent):QPushButton(parent)
    {
        setMouseTracking(true);
        setAttribute(Qt::WA_Hover);

    }

    void ButtonOperator::hoverEnter(QHoverEvent *)
    {


    }


    void ButtonOperator::hoverLeave(QHoverEvent *)
    {
        QFont font = this->font();
        font.setBold(false);
        this->setFont(font);
        repaint();
    }

    void ButtonOperator::hoverMove(QHoverEvent *)
    {
        QFont font = this->font();
        font.setBold(true);
        this->setFont(font);
        repaint();
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


