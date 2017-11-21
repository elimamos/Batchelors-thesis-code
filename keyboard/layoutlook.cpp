#include "layoutlook.h"

LayoutLook::LayoutLook(QString sLayoutName,QString sButtonLook,QString sBackgroundLook)
{
    layoutName=sLayoutName;
    layoutButtonLook=sButtonLook;
    layoutBackgroundLook=sBackgroundLook;
}
QString LayoutLook::getLayoutName(){
    return layoutName;
}
QString LayoutLook::getLayouButtonLook(){
    return layoutButtonLook;
}
QString LayoutLook::getLayoutBackgroundLook(){
    return layoutBackgroundLook;
}
