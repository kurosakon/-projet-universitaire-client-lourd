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
    int             status;//1=element accomplie, 2=element en attente, autres valeurs=element annuler

public:
    Element(const InfoElement & _info, int id,List * _parent);
    ~Element();

    QString         getTitle()const;
    QString         getModifDate() const;
    QString         getCreationDate()const;
    QString         getDescription()const;
    QString         getTag1() const;
    QString         getTag2() const;
    int             getStatus() const;
    void            setDescription(QString s);
    void            setTitle(QString s);
    void            setModifDate(QString s);
    void            setTags(QString t1, QString t2);
    void            setStatus(int i);
    List *          getParent()const;
    int             getId()const;
    int             getNumberInParentList()const;
    bool            isList()const;

};

#endif // ELEMENT_H
