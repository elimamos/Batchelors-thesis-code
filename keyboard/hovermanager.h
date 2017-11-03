#ifndef HOVERMANAGER_H
#define HOVERMANAGER_H


class HoverManager
{

public:
    HoverManager(int sLastHoveredID,int sHoveredCount);
    int getLastHoveredID();
    int getHoveredCount();
private:
    int lastHoveredID;
    int hoverCount;



};

#endif // HOVERMANAGER_H
