#include "list.h"

Element::Element(const InfoElement & _info,List * _parent):
    type(ELEMENT),parent(_parent),info(_info)
{
}

Element::~Element(){
    if(type==LIST)
    {
        List * tmp=static_cast<List *>(this);
        for(int i=0;i<tmp->childCount();i++)
            delete tmp->child(i);
    }
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
