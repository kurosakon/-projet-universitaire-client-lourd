#ifndef ELEMENT_H
#define ELEMENT_H

#include "infoelement.h"

class List;

class Element
{
protected:
    int             identifiant;
    Type            type;
    List *          parent;
    InfoElement     info;

public:
    Element(const InfoElement & _info, int id,List * _parent);
    ~Element();

    QString         getTitle()const;
    QString         getModifDate() const;
    QString         getCreationDate()const;
    QString         getDescription()const;
    List *          getParent()const;
    int             getId()const;
    int             getNumberInParentList()const; //position de l'element dans le vecteur de son parent
    bool            isList()const;

};

#endif // ELEMENT_H
