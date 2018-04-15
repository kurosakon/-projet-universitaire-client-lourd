#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>
#include <QSplitter>
#include <iostream>

#include "list.h"
#include "listgraphics.h"

//juste une fonction pour tester linterface. ca renvoit une liste remplit
List * bdd(){
    List * l1=new List(InfoElement("courses","","",""),1);
        List * l21=new List(InfoElement("lundi","description","1/1/1","2/2/2"),2,l1);
            List * l211=new List(InfoElement("bouffe","","",""),3,l21);
                Element * l2111=new Element(InfoElement("cornichon","","",""),4,l211);
                Element * l2112=new Element(InfoElement("mayo","","",""),5,l211);
            Element * l212=new Element(InfoElement("magazine","","",""),6,l21);
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
    lgs(),
    user(""),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    root=bdd();
    model=new ListModel(root);
    tree=new Tree(model);

    area=new QMdiArea();

    QSplitter *splitter = new QSplitter(this);
    splitter->addWidget(tree);
    lgs.push_back(new ListGraphics(static_cast<List *>(root->child(0)),area));
    splitter->addWidget(area);
    setCentralWidget(splitter);

    updateActions();

    //appeler updateActions dès que l'utilisateur selectionne un élément
    connect(tree->selectionModel(), &QItemSelectionModel::selectionChanged,this, &MainWindow::updateActions);

    connect(ui->deleteElementAction, &QAction::triggered, this, &MainWindow::deleteElement);
    connect(ui->addElementAction, &QAction::triggered, this, &MainWindow::addElement);
    connect(ui->setElementAction, &QAction::triggered, this, &MainWindow::setElement);
    connect(ui->connectionAction, &QAction::triggered, this, &MainWindow::connection);


    connect(tree,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(newListGraphic(QModelIndex)));
    connect(tree,&QTreeView::customContextMenuRequested,this,&MainWindow::treeMenu);

    connection();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//slots

void MainWindow::deleteElement()
{
    QWidget * tmp=QApplication::focusWidget();
    if(tree==tmp)
    {
        Element * element=model->getElement(tree->currentIndex());
        QList<QMdiSubWindow*> l=area->subWindowList();

        if(element->isList())//si c'est une liste, on ferme les fenêtres ouvertes des enfants
        {
            List* liste=static_cast<List *>(element);
            for(int i=0;i<l.size();i++)
            {
                for(int j=0;j<liste->childCount();j++)
                {
                    if(l.value(i)->windowTitle()=="<LIST>"+liste->child(j)->getTitle()|| l.value(i)->windowTitle()=="<ELEMENT>"+liste->child(j)->getTitle())
                    {
                        area->setActiveSubWindow(l.value(i));
                        area->closeActiveSubWindow();
                    }
                }

            }
        }

        for(int i=0;i<l.size();i++)//Si l'élément selectionné a une fenêtre ouverte, on la supprime
        {
            if(l.value(i)->windowTitle()=="<LIST>"+element->getTitle()|| l.value(i)->windowTitle()=="<ELEMENT>"+element->getTitle())
            {
                area->setActiveSubWindow(l.value(i));
                area->closeActiveSubWindow();
                break;
            }
        }

        delete element;


        if(element->getParent()!=NULL)//on actualise la fenêtre du parent si il existe et est affiché
        {
            List* p=element->getParent();
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
                area->setActiveSubWindow(l.value(i));//On ferme le parent
                area->closeActiveSubWindow();
                ListGraphics* lg=new ListGraphics(p,area);//On réaffiche le parent. Comme sa, sa l'actualise
                lg->show();
            }

        }

    }
    update();
    updateActions();
}

void MainWindow::addElement()
{
    QWidget * tmp=QApplication::focusWidget();
    Element * element=model->getElement(tree->currentIndex());
    if(tree==tmp && element->isList())
    {
        List* liste=static_cast<List *>(element);
        QDialog* w=new QDialog(this);
        QHBoxLayout* boxLayout=new QHBoxLayout;
        QRadioButton* checkBoxIsList=new QRadioButton("list",w);
        QRadioButton* checkBoxIsElement=new QRadioButton("element",w);
        QLineEdit* lineEditTitle=new QLineEdit(w);
        QPlainTextEdit* textEditDescription= new QPlainTextEdit(w);
        QPushButton* buttonConfirm= new QPushButton("confirmer",w);
        QPushButton* buttonAnnul= new QPushButton("annuler",w);
        QGridLayout* layout=new QGridLayout;
        QLabel* txtTitre=new QLabel("Titre:",w);
        QLabel* txtDescri=new QLabel("Description:",w);
        QString date=QDate::currentDate().toString("dd.MM.yyyy");

        boxLayout->addWidget(checkBoxIsElement);
        boxLayout->addWidget(checkBoxIsList);
        w->setLayout(layout);
        layout->addLayout(boxLayout,0,0);
        layout->addWidget(txtTitre,1,0);
        layout->addWidget(lineEditTitle,2,0,1,2);
        layout->addWidget(txtDescri,3,0);
        layout->addWidget(textEditDescription,4,0,1,2);
        layout->addWidget(buttonConfirm,6,0);
        layout->addWidget(buttonAnnul,6,1);

        checkBoxIsElement->setChecked(true);
        w->show();

        QObject::connect(buttonConfirm,SIGNAL(clicked()),w,SLOT(accept()));
        QObject::connect(buttonAnnul,SIGNAL(clicked()),w,SLOT(close()));


        if (w->exec()==QDialog::Accepted)
        {
            InfoElement e(lineEditTitle->text(),textEditDescription->toPlainText(),date,date);

            if(lineEditTitle->text().size()==0)
                e.title="Titre";

            if(checkBoxIsElement->isChecked())
            {
                Element* elt=new Element(e,0,liste);
                liste->appendChild(elt);
            }
            else if(checkBoxIsList->isChecked())
            {
                List* elt=new List(e,0,liste);
                liste->appendChild(elt);
            }

            ListGraphics* lg;
            QList<QMdiSubWindow*> l=area->subWindowList();
            for(int i=0;i<(int)lgs.size();i++)//Ce for est juste la pour que la fenêtre du parent (si ouverte) actualise sa taille
            {
                if("<LIST>"+liste->getTitle()==lgs[i]->windowTitle())//Cette liste est actuelment affiché, donc on ferme
                {
                    lgs[i]->close();
                    lgs.erase(lgs.begin()+i);
                    area->setActiveSubWindow(l.value(i));
                    area->closeActiveSubWindow();
                    lg=new ListGraphics(liste,area);//On refait la Listgraphic, comme sa sa actualise sa taille
                    lgs.push_back(lg);//on ajoute la liste actualiser
                    break;
                }
            }

        }
    }
    update();
    updateActions();
}

void MainWindow::setElement()
{
    QWidget * tmp=QApplication::focusWidget();
    Element * element=model->getElement(tree->currentIndex());
    if(tree==tmp)
    {
        QDialog* w=new QDialog(this);
        QLineEdit* lineEditTitle=new QLineEdit(w);
        QString tmp=element->getDescription();
        QPlainTextEdit* textEditDescription= new QPlainTextEdit(tmp.remove("Description: \n"),w);
        QPushButton* buttonConfirm= new QPushButton("confirmer",w);
        QPushButton* buttonAnnul= new QPushButton("annuler",w);
        QGridLayout* layout=new QGridLayout;
        QLabel* txtTitre=new QLabel("Titre:",w);
        QLabel* txtDescri=new QLabel("Description:",w);

        tmp=windowTitle();
        if(element->isList())
            lineEditTitle->setText(tmp.remove("<LIST>"));
        else
            lineEditTitle->setText(tmp.remove("<ELEMENT>"));

        w->setLayout(layout);
        layout->addWidget(txtTitre,1,0);
        layout->addWidget(lineEditTitle,2,0,1,2);
        layout->addWidget(txtDescri,3,0);
        layout->addWidget(textEditDescription,4,0,1,2);
        layout->addWidget(buttonConfirm,6,0);
        layout->addWidget(buttonAnnul,6,1);

        w->show();

       QObject::connect(buttonConfirm,SIGNAL(clicked()),w,SLOT(accept()));
       QObject::connect(buttonAnnul,SIGNAL(clicked()),w,SLOT(close()));

       if (w->exec()==QDialog::Accepted)
       {
           QString oldTitle=element->getTitle();
           element->setDescription(textEditDescription->toPlainText());
           element->setTitle(lineEditTitle->text());
           element->setModifDate(QDate::currentDate().toString("dd.MM.yyyy")+" "+QTime::currentTime().toString("hh:mm"));

           ListGraphics* lg;
           QList<QMdiSubWindow*> l=area->subWindowList();

           for(int i=0;i<(int)lgs.size();i++)//On modifie la listeGraphic de l'element si ouvert
           {
               if("<LIST>"+oldTitle==lgs[i]->windowTitle() || "<ELEMENT>"+oldTitle==lgs[i]->windowTitle())//Cette liste est actuelment affiché
               {
                   lgs[i]->close();
                   lgs.erase(lgs.begin()+i);
                   area->setActiveSubWindow(l.value(i));
                   area->closeActiveSubWindow();
                   lg=new ListGraphics(static_cast<List *>(element),area);//On refait la Listgraphic, comme sa sa actualise sa taille
                   lgs.push_back(lg);//on ajoute la liste actualiser
                   break;
               }
           }

       }
        update();
        updateActions();
    }
}

void MainWindow::updateActions()
{
    //std::cout<<"updateAction"<<std::endl;
    QWidget * widget=QApplication::focusWidget();
    if(widget==tree)
    {
        //a modifier pour que la suppression soit impossible pour certaines listes (a la racine par exemple)
        ui->deleteElementAction->setEnabled(true);
        ui->addElementAction->setEnabled(true);
        ui->setElementAction->setEnabled(true);
        //si l'utilisateur n'a pas les droits de modification, alors on disable
        //TODO
    }else{
        ui->deleteElementAction->setEnabled(false);
        ui->addElementAction->setEnabled(false);
        ui->setElementAction->setEnabled(false);
    }
}

void MainWindow::treeMenu( const QPoint & pos ){

    QMenu menu(this);
    menu.addAction(ui->deleteElementAction);
    QPoint pt(pos);
    menu.exec( tree->mapToGlobal(pos) );
}

void MainWindow::newListGraphic(const QModelIndex & index){
    //std::cout<<"fonction a completer plus tard (newListGraphic)"<<std::endl;
    Element * element=model->getElement(index);
    if(element->isList()){
        lgs.push_back(new ListGraphics(static_cast<List*>(element),area));
        std::cout<<area->subWindowList().count()<<std::endl;
        area->show();
    }


}

void MainWindow::connection(){
    ConnectionWidget * w=new ConnectionWidget(user,this);
}

void MainWindow::update(){
    delete model;
    model=new ListModel(root);
    tree->setModel(model);
//    emit model->dataChanged(QModelIndex(),QModelIndex());
//    tree->setModel(model);
}
