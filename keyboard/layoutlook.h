#ifndef LAYOUTLOOK_H
#define LAYOUTLOOK_H
#include<QString>

class LayoutLook
{
public:
    LayoutLook(QString sLayoutName,QString sButtonLook,QString sBackgroundLook);
    QString getLayoutName();
    QString getLayouButtonLook();
    QString getLayoutBackgroundLook();
private:
    QString layoutName;
    QString layoutButtonLook;
    QString layoutBackgroundLook;

};

#endif // LAYOUTLOOK_H
