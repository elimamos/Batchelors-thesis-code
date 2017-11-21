#include "layoutlook.h"

LayoutLook::LayoutLook(QString sLayoutName,QString sButtonLook,QPalette sBackgroundLook)
{
    layoutName=sLayoutName;
    layoutButtonLook=sButtonLook;
    backgroundColor=sBackgroundLook;
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
