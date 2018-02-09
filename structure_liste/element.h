#ifndef ELEMENT_H
#define ELEMENT_H

#include "infoelement.h"

class List;

class Element
{
private:
    Type            type;
    List *          parent;
    InfoElement     info;

public:
    Element(InfoElement _info,List * _parent);
};

#endif // ELEMENT_H
