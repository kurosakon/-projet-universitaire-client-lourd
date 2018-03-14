#ifndef POSTIT_H
#define POSTIT_H

#include <QObject>
#include <QWidget>
#include "listgraphics.h"

class PostIt:public QWidget
{

private:
    ListGraphics liste;
    bool positionFixed;
public:
    PostIt();
    //setColor(int r, int v, int b);
    void setSize(int size);
    void fixPosition(int x, int y);
    void newPostIt(List l);
};

#endif // POSTIT_H
