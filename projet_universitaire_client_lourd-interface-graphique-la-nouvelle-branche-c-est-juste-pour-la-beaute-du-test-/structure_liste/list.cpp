#include "list.h"

List::List(InfoElement _info,  int id, List * _parent):Element(_info,_parent, id),children()
{
    type=LIST;
}

List::~List(){
    for(unsigned int i=0;i<children.size();i++)
        delete children[i];
    children.clear();
    //TODO détruire tout les fils en même temps ou pas ?
}

void List::appendChild(Element * newChild){
    if(newChild)
        children.push_back(newChild);
}

Element * List::child(int index){
    if(index>childCount())
        return NULL;
    return children[index];
}

int List::childCount()const{
    return (int)children.size();
}

bool List::removeChild(int position)
{
    if (position < 0 || position> (int)children.size())
        return false;

    delete children[position];

    return true;
}


Element* List::findById(int id)
{
    //TODO : chercher aussi dans les enfants (recursivement par exemple) si c'est le but de la fonction ?
    for(unsigned int i=0;i<children.size();i++)
    {
        if(children[i]->getId()==id)
        {
            return children[i];
        }
    }
    return NULL;
}

bool List::inList(int id)
{
//TODO : chercher aussi dans les enfants (recursivement par exemple) si c'est le but de la fonction ?
    for(unsigned int i=0;i<children.size();i++)
    {
        if(children[i]->getId()==id)
        {
            return true;
        }
    }
    return false;
}

QString List::getTitleOf(int index)
{
    if (index<(int)children.size())
        return children[index]->getTitle();
    else
        return "error \"getTitleOf\" out of range";
}

QString List::getDescriptionOf(int index)
{
    if (index<(int)children.size())
        return children[index]->getDescription();
    else
        return "error \"getDescriptionOf\" out of rang";


}
QString List::getCreationDateOf(int index)
{
    if (index<(int)children.size())
        return children[index]->getCreationDate();
    else
        return "error \"getCreationDateOf\" out of rang";
}
QString List::getModifDateOf(int index)
{
    if (index<(int)children.size())
        return children[index]->getModifDate();
    else
        return "error \"getModifDateOf\" out of rang";
}
