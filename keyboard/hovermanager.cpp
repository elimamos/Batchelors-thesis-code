#include "hovermanager.h"

HoverManager::HoverManager(int sLastHoveredID,int sHoveredCount){
    hoverCount=sHoveredCount;
    lastHoveredID=sLastHoveredID;


}
int HoverManager::getHoveredCount(){
    return hoverCount;
}
int HoverManager::getLastHoveredID(){
    return lastHoveredID;
}
