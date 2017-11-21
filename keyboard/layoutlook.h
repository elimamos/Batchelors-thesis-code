#ifndef LAYOUTLOOK_H
#define LAYOUTLOOK_H
#include<QString>
#include<QPalette>

class LayoutLook
{
public:
    LayoutLook(QString sLayoutName,QString sButtonLook,QPalette sBackgroundLook);
    QString getLayoutName();
    QString getLayouButtonLook();
    QPalette getLayoutBackgroundLook();
private:
    QString layoutName;
    QString layoutButtonLook;
    QPalette backgroundColor;

};

#endif // LAYOUTLOOK_H
