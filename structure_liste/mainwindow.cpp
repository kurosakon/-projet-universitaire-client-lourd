#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>
#include <QSplitter>
#include <iostream>

#include "list.h"
#include "postit.h"
#include "listgraphics.h"

//juste une fonction pour tester linterface. ca renvoit une liste remplit
List * bdd(){
    List * l1=new List(InfoElement("courses","","",""),1);
        List * l21=new List(InfoElement("lundi","description","1/1/1","2/2/2"),2,l1);
            List * l211=new List(InfoElement("bouffe","","",""),3,l21);
                Element * l2111=new Element(InfoElement("cornichon","","",""),l211,4);
                Element * l2112=new Element(InfoElement("mayo","","",""),l211,5);
            Element * l212=new Element(InfoElement("magazine","","",""),l21,6);
        List * l22=new List(InfoElement("mardi","","",""),7,l1);
        List * l23=new List(InfoElement("mercredi","","",""),8,l1);
    l1->appendChild(l21);
    l1->appendChild(l22);
    l1->appendChild(l23);
    l21->appendChild(l211);
    l21->appendChild(l212);
    l211->appendChild(l2111);
    l211->appendChild(l2112);

    return l1;
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    root=bdd();
    model=new ListModel(root);
    tree=new Tree(model);
    lg=new ListGraphics(root);

    QSplitter *splitter = new QSplitter(this);
    splitter->addWidget(tree);
    splitter->addWidget(lg);
    setCentralWidget(splitter);

    updateActions();

    //appeler updateActions dès que l'utilisateur selectionne un élément
    connect(tree->selectionModel(), &QItemSelectionModel::selectionChanged,this, &MainWindow::updateActions);

    connect(ui->deleteElementAction, &QAction::triggered, this, &MainWindow::deleteElement);

}

MainWindow::~MainWindow()
{
    delete ui;
}

//slots

void MainWindow::deleteElement(){
    QWidget * tmp=QApplication::focusWidget();
    if(tree==tmp){
    }
    std::cout<<"Ceci est une fonction pas encore construite"<<std::endl;

    updateActions();
}

void MainWindow::updateActions()
{
    QWidget * widget=QApplication::focusWidget();
    if(widget==tree)
    {
        //a modifier pour que la suppression soit impossible pour certaines listes (a la racine par exemple)
        ui->deleteElementAction->setEnabled(true);

        //je sais pas si ca sera util, ni meme a quoi sa sert
        //bool hasCurrent = tree->selectionModel()->currentIndex().isValid();
        //ui->deleteListAction->setEnabled(hasSelection);
    }else{
        ui->deleteElementAction->setEnabled(false);
    }
}
