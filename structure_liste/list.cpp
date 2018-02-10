#include "list.h"

List::List(InfoElement _info, List * _parent):Element(_info,_parent),children()
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
