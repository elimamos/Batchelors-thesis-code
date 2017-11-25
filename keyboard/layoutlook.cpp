#include "layoutlook.h"
LayoutLook::LayoutLook(QString sLayoutName,QString sButtonLook,QPalette sBackgroundLook, QString sProgressBarLook,QString sTextEditLook,QString sLabelLook, QString sStopButtonLook)
{
    layoutName=sLayoutName;
    layoutButtonLook=sButtonLook;
    backgroundColor=sBackgroundLook;
    progressBarLook=sProgressBarLook;
    textEditLook=sTextEditLook;
    labelLook=sLabelLook;
    stopButtonLook=sStopButtonLook;
}
LayoutLook::LayoutLook(){
    //qDebug()<<"EMPTY HERE!";
}
QString LayoutLook::getLayoutName(){
    return layoutName;
}
QString LayoutLook::getLayouButtonLook(){
    return layoutButtonLook;
}
QPalette LayoutLook::getLayoutBackgroundLook(){
    return backgroundColor;
}

QString LayoutLook::getprogressBarLook(){
    return progressBarLook;
}
QString LayoutLook::getTextEditLook(){
    return textEditLook;
}
QString LayoutLook::getLabelLook(){
    return labelLook;
}
QString LayoutLook::getStopButtonLook(){
    return stopButtonLook;
}
