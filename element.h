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
    void            setDescription(QString s);
    void            setTitle(QString s);
    void            setModifDate(QString s);
    List *          getParent()const;
    int             getId()const;
    int             getNumberInParentList()const;
    bool            isList()const;

};

#endif // ELEMENT_H
