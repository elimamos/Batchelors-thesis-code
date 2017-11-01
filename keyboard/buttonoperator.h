#ifndef BUTTONOPERATOR_H
#define BUTTONOPERATOR_H
#include <QtCore>
#include <QPushButton>

class ButtonOperator : public QObject
{
    Q_OBJECT


public:
    ButtonOperator();
   QPushButton *button ;

  //  QTimer *timer;

public slots:
    void MySlot();
};

#endif // BUTTONOPERATOR_H
