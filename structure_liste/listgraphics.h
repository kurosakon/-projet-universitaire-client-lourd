#ifndef LISTGRAPHIC_H
#define LISTGRAPHIC_H

#include <QObject>
#include<QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QWindow>
#include <QGridLayout>
#include <QCheckBox>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QDialog>
#include <QMdiArea>
#include<vector>
#include "element.h"
#include "list.h"

class ListGraphics:public QWidget
{
    Q_OBJECT
private:
    List* liste;
    std::vector<bool> expanded;//Pour savooir si les différents menbres de la liste sont deployés
    QPushButton* buttonExpand;
    QPushButton* buttonShowInfo;
    QPushButton* buttonAdd;
    QPushButton* buttonDelete;
    QLabel* txtTitre;
    QLabel* txtDescription;
    QLabel* txtCreationDate;
    QLabel* txtModificationDate;
    QWidget* windowList;
    QGridLayout* layout;

public:
    ListGraphics(List* l,QMdiArea * area, QWidget* parent=0);//Affiche tout les elements, chacun dans une fenetre

public slots:
    void add();//Ajoute un enfant
    void del();//Supprime l'element ET tout ses enfant
    void expand();//"Déploie" l'élément (=Affiche les dates de creation, modif, et la description)
    void retract();//"rétracte" l'élément (=Désaffiche les dates de creation, modif, et la description)


};

#endif // LISTGRAPHIC_H
