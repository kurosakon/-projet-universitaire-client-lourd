#include "listgraphics.h"


ListGraphics::ListGraphics(List* l, QMdiArea * area, QWidget* parent):QWidget(parent),liste(l),a(area)
{
    buttonAdd=new QPushButton("Ajouter",this);
    buttonDelete=new QPushButton("Supprimer",this);
    buttonModif=new QPushButton("Modifier",this);
    txtDescription=new QLabel("Description: \n"+liste->getDescription(),this);
    txtModificationDate=new QLabel("Dernière modification le "+QDate::currentDate().toString("dd.MM.yyyy")+" "+QTime::currentTime().toString("hh:mm"));
    txtEnfant=new QLabel("Enfant(s): (cliquez pour afficher)",this);
    txtTags=new QLabel("Tags: "+liste->getTag1()+"  ;  "+liste->getTag2());
    checkBoxAnnule=new QRadioButton("annuler",this);
    checkBoxEnAttente=new QRadioButton("enAttente",this);
    checkBoxRealise=new QRadioButton("Realise",this);

    if(liste->getStatus()==1)
        checkBoxRealise->setChecked(true);
    else if(liste->getStatus()==2)
        checkBoxEnAttente->setChecked(true);
    else
        checkBoxAnnule->setChecked(true);

    if(!liste->isList())
    {
        setWindowTitle("<ELEMENT>"+liste->getTitle());
        buttonAdd->setVisible(false);
        txtEnfant->setVisible(false);
    }
    else
    {
        setWindowTitle("<LIST>"+liste->getTitle());
    }

    layout=new QGridLayout;
    layout->addWidget(txtModificationDate,0,0);
    layout->addWidget(txtDescription,1,0,2,2);

    layoutButton=new QHBoxLayout;
    layoutButton->addWidget(buttonAdd);
    layoutButton->addWidget(buttonDelete);
    layoutButton->addWidget(buttonModif);

    layoutCheckBox=new QHBoxLayout;
    layoutCheckBox->addWidget(checkBoxRealise);
    layoutCheckBox->addWidget(checkBoxEnAttente);
    layoutCheckBox->addWidget(checkBoxAnnule);

    layout->addLayout(layoutCheckBox,3,0);
    layout->addLayout(layoutButton,4,0);
    layout->addWidget(txtEnfant,5,0);

    layoutEnfant= new QVBoxLayout;
    layout->addLayout(layoutEnfant,6,0);

    layout->addWidget(txtTags,7,0);

    int i=0;

    if(liste->isList() && liste->childCount()>0)
    {
        while(liste->child(i)!=NULL && i<liste->childCount())
        {
            Element* elt=liste->child(i);
            ButtonEnfant* b=new ButtonEnfant(elt,a);
            layoutEnfant->addWidget(b);
            i++;
        }
    }



    setLayout(layout);

    area->addSubWindow(this);



    QObject::connect(buttonAdd,SIGNAL(clicked()),this,SLOT(add()));
    QObject::connect(buttonDelete,SIGNAL(clicked()),this,SLOT(del()));
    QObject::connect(buttonModif,SIGNAL(clicked()),this,SLOT(modif()));
    QObject::connect(checkBoxAnnule,SIGNAL(clicked(bool)),SLOT(statusAnnuler()));
    QObject::connect(checkBoxEnAttente,SIGNAL(clicked(bool)),SLOT(statusEnAttente()));
    QObject::connect(checkBoxRealise,SIGNAL(clicked(bool)),SLOT(statusRealiser()));

    show();
}

void ListGraphics::add()
{
    //TODO cf newElt/newList.
    QDialog* w=new QDialog(this);
    QHBoxLayout* boxLayout=new QHBoxLayout;
    QRadioButton* checkBoxIsList=new QRadioButton("list",w);
    QRadioButton* checkBoxIsElement=new QRadioButton("element",w);
    QLineEdit* lineEditTitle=new QLineEdit(w);
    QLineEdit* lineEditTag1=new QLineEdit(w);
    QLineEdit* lineEditTag2=new QLineEdit(w);
    QPlainTextEdit* textEditDescription= new QPlainTextEdit(w);
    QPushButton* buttonConfirm= new QPushButton("confirmer",w);
    QPushButton* buttonAnnul= new QPushButton("annuler",w);
    QGridLayout* layout=new QGridLayout;
    QLabel* txtTitre=new QLabel("Titre:",w);
    QLabel* txtDescri=new QLabel("Description:",w);
    QLabel* txtTag1=new QLabel("Tag 1:");
    QLabel* txtTag2=new QLabel("Tag 2:");
    QString date=QDate::currentDate().toString("dd.MM.yyyy");

    boxLayout->addWidget(checkBoxIsElement);
    boxLayout->addWidget(checkBoxIsList);
    w->setLayout(layout);
    layout->addLayout(boxLayout,0,0);
    layout->addWidget(txtTitre,1,0);
    layout->addWidget(lineEditTitle,2,0,1,2);
    layout->addWidget(txtDescri,3,0);
    layout->addWidget(textEditDescription,4,0,1,2);
    layout->addWidget(txtTag1,6,0);
    layout->addWidget(lineEditTag1,6,1);
    layout->addWidget(txtTag2,7,0);
    layout->addWidget(lineEditTag2,7,1);
    layout->addWidget(buttonConfirm,8,0);
    layout->addWidget(buttonAnnul,8,1);

    checkBoxIsElement->setChecked(true);
    w->show();

    QObject::connect(buttonConfirm,SIGNAL(clicked()),w,SLOT(accept()));
    QObject::connect(buttonAnnul,SIGNAL(clicked()),w,SLOT(close()));


    if (w->exec()==QDialog::Accepted)
    {
        InfoElement e(lineEditTitle->text(),textEditDescription->toPlainText(),date,date,lineEditTag1->text(),lineEditTag2->text());

        if(lineEditTitle->text().size()==0)
            e.title="Titre";

        if(checkBoxIsElement->isChecked())
        {
            newElt(e);
            txtModificationDate->setText("Dernière modification le "+QDate::currentDate().toString("dd.MM.yyyy")+" "+QTime::currentTime().toString("hh:mm"));
            liste->setModifDate(QDate::currentDate().toString("dd.MM.yyyy")+" "+QTime::currentTime().toString("hh:mm"));
        }
        else if(checkBoxIsList->isChecked())
        {
            newList(e);
            txtModificationDate->setText("Dernière modification le "+QDate::currentDate().toString("dd.MM.yyyy")+" "+QTime::currentTime().toString("hh:mm"));
            liste->setModifDate(QDate::currentDate().toString("dd.MM.yyyy")+" "+QTime::currentTime().toString("hh:mm"));
        }
        parentWidget()->close();
        ListGraphics* lg=new ListGraphics(liste,a);
        lg->show();
    }

}

void ListGraphics::del()
{
    //TODO cf delElt
    QDialog* w=new QDialog(this);
    QLabel* txtValidation=new QLabel("Voulez-vous vraiment cet élément et tout ses enfants ?",w);
    QPushButton* buttonConfirm= new QPushButton("confirmer",w);
    QPushButton* buttonAnnul= new QPushButton("annuler",w);
    QGridLayout* layout=new QGridLayout;

    w->setLayout(layout);
    layout->addWidget(txtValidation,0,0);
    layout->addWidget(buttonConfirm,1,0);
    layout->addWidget(buttonAnnul,1,1);

    w->show();

    QObject::connect(buttonAnnul,SIGNAL(clicked()),w,SLOT(close()));
    QObject::connect(buttonConfirm,SIGNAL(clicked()),w,SLOT(accept()));

    if (w->exec()==QDialog::Accepted)
    {
        delElt();
    }
}

void ListGraphics::modif()
{
    //TODO la communication avec le serveur et la BDD locale.
    QDialog* w=new QDialog(this);
    QLineEdit* lineEditTitle=new QLineEdit(w);
    QString tmp=txtDescription->text();
    QLineEdit* lineEditTag1=new QLineEdit(liste->getTag1(),w);
    QLineEdit* lineEditTag2=new QLineEdit(liste->getTag2(),w);
    QPlainTextEdit* textEditDescription= new QPlainTextEdit(tmp.remove("Description: \n"),w);
    QPushButton* buttonConfirm= new QPushButton("confirmer",w);
    QPushButton* buttonAnnul= new QPushButton("annuler",w);
    QGridLayout* layout=new QGridLayout;
    QLabel* txtTitre=new QLabel("Titre:",w);
    QLabel* txtDescri=new QLabel("Description:",w);
    QLabel* txtTag1=new QLabel("Tag1:",w);
    QLabel* txtTag2=new QLabel("Tag2:",w);

    tmp=windowTitle();
    if(liste->isList())
        lineEditTitle->setText(tmp.remove("<LIST>"));
    else
        lineEditTitle->setText(tmp.remove("<ELEMENT>"));

    w->setLayout(layout);
    layout->addWidget(txtTitre,1,0);
    layout->addWidget(lineEditTitle,2,0,1,2);
    layout->addWidget(txtDescri,3,0);
    layout->addWidget(textEditDescription,4,0,1,2);
    layout->addWidget(txtTag1,6,0);
    layout->addWidget(lineEditTag1,6,1);
    layout->addWidget(txtTag2,7,0);
    layout->addWidget(lineEditTag2,7,1);
    layout->addWidget(buttonConfirm,8,0);
    layout->addWidget(buttonAnnul,8,1);

    w->show();

   QObject::connect(buttonConfirm,SIGNAL(clicked()),w,SLOT(accept()));
   QObject::connect(buttonAnnul,SIGNAL(clicked()),w,SLOT(close()));

   if (w->exec()==QDialog::Accepted)
   {
       if(liste->isList())
           setWindowTitle("<LIST>"+lineEditTitle->text());
       else
           setWindowTitle("<ELEMENT>"+lineEditTitle->text());

       txtDescription->setText("Description: \n"+textEditDescription->toPlainText());
       txtModificationDate->setText("Dernière modification le "+QDate::currentDate().toString("dd.MM.yyyy")+" "+QTime::currentTime().toString("hh:mm"));
       txtTags->setText("Tags: "+lineEditTag1->text()+"  ;  "+lineEditTag2->text());
       liste->setTags(lineEditTag1->text(),lineEditTag2->text());
       liste->setDescription(textEditDescription->toPlainText());
       liste->setTitle(lineEditTitle->text());
       liste->setModifDate(QDate::currentDate().toString("dd.MM.yyyy")+" "+QTime::currentTime().toString("hh:mm"));
   }
}

void ListGraphics::statusAnnuler()
{
    liste->setStatus(3);
}
void ListGraphics::statusEnAttente()
{
    liste->setStatus(2);
}
void ListGraphics::statusRealiser()
{
    liste->setStatus(1);
}

void ListGraphics::newElt(InfoElement e)
{
    //TODO communication avec bdd locale et serveur
    Element* elt=new Element(e,0,liste);
    ButtonEnfant* b=new ButtonEnfant(elt,a);
    liste->appendChild(elt);
    layoutEnfant->addWidget(b);
}

void ListGraphics::newList(InfoElement e)
{
    //TODO communication avec bdd locale et serveur
    List* elt=new List(e,0,liste);
    ButtonEnfant* b=new ButtonEnfant(elt,a);
    liste->appendChild(elt);
    layoutEnfant->addWidget(b);
}

void ListGraphics::delElt()
{
    //TODO corriger les bugs d'affichages dans l'arbre.
    //TODO communication avec serveur et BDD locale.
    QList<QMdiSubWindow*> l=a->subWindowList();
    if(liste->isList())
    {
        closeChildren(l,liste);
        parentWidget()->close();
        delete liste;
    }
    else
    {
        parentWidget()->close();
        delete liste;
    }

    if(liste->getParent()!=NULL)
    {
        List* p=liste->getParent();
        int i=0;

        for(i=0;i<l.size();i++)//On vérifie si le parent est affiché
        {
            if(l.value(i)->windowTitle()=="<LIST>"+p->getTitle()|| l.value(i)->windowTitle()=="<ELEMENT>"+p->getTitle())
            {
                break;
            }
        }

        if(i!=l.size())//Le parent est affiché et se trouve à l'indice i
        {
            a->setActiveSubWindow(l.value(i));//On ferme le parent
            a->closeActiveSubWindow();
            ListGraphics* lg=new ListGraphics(p,a);//On réaffiche le parent. Comme sa, sa l'actualise
            lg->show();
        }

    }

}

void ListGraphics::closeChildren(QList<QMdiSubWindow*> l, List* list)
{
    l=a->subWindowList();
    if(list->isList())
    {
        for(int i=0;i<l.size();i++)
        {
            for(int j=0;j<list->childCount();j++)
            {
                if(l.value(i)->windowTitle()=="<LIST>"+list->child(j)->getTitle()|| l.value(i)->windowTitle()=="<ELEMENT>"+list->child(j)->getTitle())
                {
                    a->setActiveSubWindow(l.value(i));
                    a->closeActiveSubWindow();
                }
                closeChildren(l,static_cast<List *>(list->child(j)));
            }
        }
    }
}


