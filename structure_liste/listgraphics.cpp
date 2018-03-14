#include "listgraphics.h"
#include<iostream>

ListGraphics::ListGraphics(List* l,QMdiArea * area, QWidget* parent):QWidget(parent),liste(l),expanded(false)
{

    buttonExpand=new QPushButton("v",this);
    buttonAdd=new QPushButton("+",this);
    buttonDelete=new QPushButton("x",this);
    txtDescription=new QLabel(liste->getDescription(),this);
    txtCreationDate=new QLabel("Créé le "+liste->getCreationDate(), this);
    txtModificationDate=new QLabel("Dernière modification le "+liste->getModifDate(),this);
    setWindowTitle(liste->getTitle());

    layout=new QGridLayout;
    layout->addWidget(txtCreationDate,0,0);
    layout->addWidget(txtModificationDate,0,2);
    layout->addWidget(txtDescription,1,0,2,2);
    layout->addWidget(buttonExpand,3,0);
    layout->addWidget(buttonAdd,3,1);
    layout->addWidget(buttonDelete,3,2);

    setLayout(layout);

    area->addSubWindow(this);
    //TODO ameliorer l'ajout des fenetres.
    //Pour le moment, y'a des risques que des fenêtres soient perdus sur la droite de la fenêtre
    //Et du coup, sa serait un peu con de perdre nos fenêtres dans les abysses insondables de l'interface graphique

    txtCreationDate->setVisible(false);
    txtModificationDate->setVisible(false);
    txtDescription->setVisible(false);


    //TODO Les slots fonctionnent que pour le dernier élément affiché (ce qui est logique vu l'implémentation). Du coup faudrait faire
    //un glorieux vecteur ou un autre truc pour que toutes les fenêtres aient des boutons qui en plus d'êtres magnifiques, soient fonctionels.


    //TODO c'est buggé (détail dans expand et retract)... Tragique, n'est il pas ? En plus, sa serait peut être mieux de tout afficher direct
    if(!expanded[liste->getNumberInParentList()])
    {
         QObject::connect(buttonExpand,SIGNAL(clicked()),this,SLOT(expand()));
    }
    else if(expanded[liste->getNumberInParentList()])
    {
        QObject::connect(buttonExpand,SIGNAL(clicked()),this,SLOT(retract()));
    }

    //TODO cf add et del
    QObject::connect(buttonAdd,SIGNAL(clicked()),this,SLOT(add()));
    QObject::connect(buttonDelete,SIGNAL(clicked()),this,SLOT(del()));

    show();
}

void ListGraphics::expand()
{
    //TODO faire en sorte que sa marche (peut etre effet de bord qui marche pas et/ou expanded qu'a pas le bon indice...)
    buttonExpand->setText("^");
    expanded[liste->getNumberInParentList()]=true;
    txtCreationDate->setVisible(true);
    txtModificationDate->setVisible(true);
    txtDescription->setVisible(true);
}

void ListGraphics::retract()
{
    //TODO faire en sorte que sa marche (peut etre effet de bord qui marche pas et/ou expanded qu'a pas le bon indice...)
    buttonExpand->setText("v");
    expanded[liste->getNumberInParentList()]=false;
    txtCreationDate->setVisible(false);
    txtModificationDate->setVisible(false);
    txtDescription->setVisible(false);
}

void ListGraphics::add()
{
    QDialog* w=new QDialog(this);
    QCheckBox* checkBoxIsList=new QCheckBox("list",w);
    QCheckBox* checkBoxIsElement=new QCheckBox("element",w);
    QLineEdit* lineEditTitle=new QLineEdit("title",w);
    QPlainTextEdit* textEditDescription= new QPlainTextEdit("description",w);
    QPushButton* buttonConfirm= new QPushButton("confirm",w);
    QPushButton* buttonAnnul= new QPushButton("cancel",w);
    QGridLayout* layout=new QGridLayout;
    //TODO une variable avec la date d'aujourd'hui, pour la rajouter dans l'élément créer.

    w->setLayout(layout);
    layout->addWidget(checkBoxIsElement,0,0);
    layout->addWidget(checkBoxIsList,0,2);
    layout->addWidget(lineEditTitle,1,0);
    layout->addWidget(textEditDescription,2,0,3,3);
    layout->addWidget(buttonConfirm,6,0);
    layout->addWidget(buttonAnnul,6,2);

    w->show();

    //TODO les scripts des boutons confirm et annul

}

void ListGraphics::del()
{
    QDialog* w=new QDialog(this);
    QLabel* txtValidation=new QLabel("Do you really wish to delete this menber and all of his children ?",w);
    QPushButton* buttonConfirm= new QPushButton("confirm",w);
    QPushButton* buttonAnnul= new QPushButton("cancel",w);
    QGridLayout* layout=new QGridLayout;

    w->setLayout(layout);
    layout->addWidget(txtValidation,0,0);
    layout->addWidget(buttonConfirm,1,0);
    layout->addWidget(buttonAnnul,1,1);

    w->show();

     //TODO les scripts des boutons confirm et annul
}

