#include "list.h"

List::List(InfoElement _info, List * _parent):Element(_info,_parent),children()
{
    type=LIST;
}

List::~List(){
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
