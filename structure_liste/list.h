#ifndef LIST_H
#define LIST_H

#include "element.h"

#include <vector>

class List:public Element
{
private:
    std::vector<Element *>      children;

public:
    List(InfoElement _info, List * _parent=NULL);
    ~List();

    void                        appendChild(Element * newChild); //ajoute un enfant (a la fin du vecteur)
    Element *                   child(int index);
    int                         childCount()const; //nombre d'enfants
};

#endif // LIST_H
