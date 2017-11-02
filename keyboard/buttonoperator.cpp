#include "buttonoperator.h"
#include "mytimer.h"

ButtonOperator::ButtonOperator(QWidget *parent):QPushButton(parent)
    {
        setMouseTracking(true);
        setAttribute(Qt::WA_Hover);
    }

    void ButtonOperator::hoverEnter(QHoverEvent *)
    {



        QFont font = this->font();
        font.setUnderline(true);
        font.setBold(false);
        this->setFont(font);
        repaint();
    }

    void ButtonOperator::hoverLeave(QHoverEvent *)
    {       myTimer myTime;
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

