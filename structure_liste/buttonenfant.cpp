#include "buttonenfant.h"

ButtonEnfant::ButtonEnfant(Element* e, QMdiArea* a):elt(e),area(a)
{
    if(e->isList())
        b=new QPushButton("<LIST>"+e->getTitle(),this);
    else
        b=new QPushButton("<ELEMENT>"+e->getTitle(),this);

    QGridLayout* l=new QGridLayout;
    l->addWidget(b,0,0,0,4);
    setLayout(l);
    show();

    QObject::connect(b,SIGNAL(clicked()),this,SLOT(expand()));
}

void ButtonEnfant::expand()
{
    QList <QMdiSubWindow*> l=area->subWindowList();
    int i;
    for(i=0;i<l.size();i++)//On vérifie que l'élément est pas déja affiché
    {
        if(l.value(i)->windowTitle()=="<LIST>"+elt->getTitle()|| l.value(i)->windowTitle()=="<ELEMENT>"+elt->getTitle())
        {
            break;
        }
    }
    if(i==l.size())
    {
        ListGraphics* lg= new ListGraphics(static_cast<List *>(elt),area);
        lg->show();
    }
    else
    {
        area->setActiveSubWindow(l.value(i));
    }

}


