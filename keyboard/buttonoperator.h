#ifndef BUTTONOPERATOR_H
#define BUTTONOPERATOR_H
#include <QtWidgets>

class ButtonOperator : public QPushButton
{
    Q_OBJECT


public:
   explicit ButtonOperator(QWidget *parent=0);


protected:
    void hoverEnter(QHoverEvent *event);
    void hoverLeave(QHoverEvent *event);
    void hoverMove(QHoverEvent *event);
    bool event(QEvent *event);

protected slots:
   /* void mousePressEvent(QMouseEvent *e){
        if (e->button() == Qt::RightButton) emit rightClicked();
        else if (e->button() == Qt::LeftButton) emit clicked();
    };*/
signals:
  //  void rightClicked();
public slots:
};


#endif // BUTTONOPERATOR_H
