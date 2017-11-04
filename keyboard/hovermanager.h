#ifndef HOVERMANAGER_H
#define HOVERMANAGER_H


class HoverManager
{

public:
    HoverManager(int sLastHoveredID,int sHoveredCount, int sKeyboardState,int sLastSpecialID,int sLastSpecialCount);
    int getLastHoveredID();
    int getHoveredCount();
    int getKeyboardState();
    int getLastSpecialID();
    int getLastSpecialCount();
private:
    int lastHoveredID;
    int hoverCount;
    int keyboardState;
    int lastSpecialID;
    int lastSpecialCount;


};

#endif // HOVERMANAGER_H
