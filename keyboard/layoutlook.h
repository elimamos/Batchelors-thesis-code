#ifndef LAYOUTLOOK_H
#define LAYOUTLOOK_H
#include<QString>
#include<QPalette>

class LayoutLook
{
public:
    LayoutLook(QString sLayoutName,QString sButtonLook,QPalette sBackgroundLook, QString sProgressBarLook, QString sTextEditLook,QString sLabelLook, QString sStopButtonLook);
    LayoutLook();
    QString getLayoutName();
    QString getLayouButtonLook();
    QPalette getLayoutBackgroundLook();
    QString getprogressBarLook();
    QString getTextEditLook();
    QString getBackGroundColor();
    QString getLabelLook();
    QString getStopButtonLook();
private:
    QString layoutName;
    QString layoutButtonLook;
    QPalette backgroundColor;
    QString progressBarLook;
    QString textEditLook;
    QString labelLook;
    QString stopButtonLook;


};

#endif // LAYOUTLOOK_H
