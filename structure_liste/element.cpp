#include "element.h"
#include "list.h"
Element::Element(const InfoElement & _info,List * _parent):
    type(ELEMENT),parent(_parent),info(_info)
{
}


QString Element::getTitle()const{
    return info.title;
}

List * Element::getParent(){
    return parent;
}

int Element::getNumberInParentList()const{
    if(parent)
    {
        for(int i=0;i<parent->childCount();i++)
        {
            if(parent->child(i)==this){
                return i;
            }
        }
    }
    return 0;
}

bool Element::isList()const{
    if(type==LIST)
        return true;
    else
        return false;
}
