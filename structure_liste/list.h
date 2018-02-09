#ifndef LIST_H
#define LIST_H

#include "element.h"

#include <vector>

class List:public Element
{
private:
    std::vector<List *>     children;

public:
    List(InfoElement _info, List * _parent=NULL);
};

#endif // LIST_H
