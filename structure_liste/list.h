#ifndef LIST_H
#define LIST_H

#include "element.h"
#include <QString>

#include <vector>

class List:public Element
{
private:
    std::vector<Element *>      children;
    int                         accessRight;

public:
    List(InfoElement _info,  int id, List * _parent=NULL,int accessRight=0);
    ~List();

    void                        appendChild(Element * newChild);
    Element *                   child(int index);
    int                         childCount()const;
    bool                        removeChild(int position);
    Element *                   findById(int id);
    bool                        inList(int id);
    QString                     getTitleOf(int index);
    QString                     getDescriptionOf(int index);
    QString                     getCreationDateOf(int index);
    QString                     getModifDateOf(int index);
};

#endif // LIST_H
