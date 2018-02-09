#ifndef ELEMENT_H
#define ELEMENT_H

#include "infoelement.h"

class List;

class Element
{
protected:
    Type            type;
    List *          parent;
    InfoElement     info;

public:
    Element(const InfoElement & _info,List * _parent);

    QString         getTitle()const;
    List *          getParent();
    int             getNumberInParentList()const; //position de l'element dans le vecteur de son parent
    bool            isList()const;

};

#endif // ELEMENT_H
