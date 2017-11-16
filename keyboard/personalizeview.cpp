#include "personalizeview.h"
#include "ui_personalizeview.h"

PersonalizeView::PersonalizeView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PersonalizeView)
{
    ui->setupUi(this);
}

PersonalizeView::~PersonalizeView()
{
    delete ui;
}

void PersonalizeView::on_pushButton_clicked()
{


    for (int i = 0; i < ui->items->count(); ++i)
    {
      QWidget *widget = ui->items->itemAt(i)->widget();
      if (widget != NULL)
      {

       if(QPushButton *pb = qobject_cast<QPushButton*>(widget)){
        widget->setStyleSheet("background-color:black;");
          }
      }
      else
      {
        // You may want to recurse, or perform different actions on layouts.
        // See gridLayout->itemAt(i)->layout()
      }
    }


}
