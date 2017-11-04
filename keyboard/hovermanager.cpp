#include "hovermanager.h"

HoverManager::HoverManager(int sLastHoveredID,int sHoveredCount,int sKeyboardState,int sLastSpecialID,int sLastSpecialCount){
    hoverCount=sHoveredCount;
    lastHoveredID=sLastHoveredID;
    keyboardState=sKeyboardState;
    lastSpecialID=sLastSpecialID;
    lastSpecialCount=sLastSpecialCount;
}
int HoverManager::getHoveredCount(){
    return hoverCount;
}
int HoverManager::getLastHoveredID(){
    return lastHoveredID;
}
int HoverManager::getKeyboardState(){
    return keyboardState;
}

int HoverManager::getLastSpecialID(){
    return lastSpecialID;
}
int HoverManager::getLastSpecialCount(){
    return lastSpecialCount;
}
