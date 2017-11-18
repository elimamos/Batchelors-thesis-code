#ifndef PERSONALIZEVIEW_H
#define PERSONALIZEVIEW_H

#include <QWidget>
using namespace std;
namespace Ui {
class PersonalizeView;
}

class PersonalizeView : public QWidget
{
    Q_OBJECT

public:
    explicit PersonalizeView(QWidget *parent = 0);
    ~PersonalizeView();

private slots:
    void on_pushButton_clicked();

private:
    Ui::PersonalizeView *ui;

};

#endif // PERSONALIZEVIEW_H
