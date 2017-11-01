#include "buttonoperator.h"

ButtonOperator::ButtonOperator()
{
        button=   new QPushButton();
        connect(button,SIGNAL(QHoverEvent),this, SLOT(MySlot()));
   }
   void ButtonOperator::MySlot()
   {
       /*QPushButton* buttonSender = qobject_cast<QPushButton*>(sender()); // retrieve the button you have clicked
          QString buttonText = buttonSender->text(); // retrive the text from the button clicked*/

   }

