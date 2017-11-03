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
    void setIndex(int sIndex);
    int getIndex();
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
    int index;
    QStringList displayList;
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
