#ifndef LISTGRAPHIC_H
#define LISTGRAPHIC_H

#include <QObject>
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QWindow>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QDialog>
#include <QMdiArea>
#include <QRadioButton>
#include <QDate>
#include <QTime>
#include <QMdiSubWindow>
#include <QMessageBox>
#include <QList>
#include <iostream>
#include <vector>
#include <buttonenfant.h>
#include "element.h"
#include "list.h"

class ListGraphics:public QWidget
{
    Q_OBJECT
private:
    List* liste;
    QPushButton* buttonAdd;
    QPushButton* buttonDelete;
    QPushButton* buttonModif;
    QLabel* txtTitre;
    QLabel* txtDescription;
    QLabel* txtCreationDate;
    QLabel* txtModificationDate;
    QLabel* txtEnfant;
    QLabel* txtTags;
    QRadioButton* checkBoxRealise;
    QRadioButton* checkBoxEnAttente;
    QRadioButton* checkBoxAnnule;
    QGridLayout* layout;
    QHBoxLayout* layoutButton;
    QVBoxLayout* layoutEnfant;
    QHBoxLayout* layoutCheckBox;
    QMdiArea* a;

    void newElt(InfoElement e);
    void newList(InfoElement e);
    void delElt();
    void closeChildren(QList<QMdiSubWindow *> l, List *list);
    void deleteElement(Element* l);

public:
    ListGraphics(List *l, QMdiArea * area, QWidget* parent=0);

public slots:
    void add();
    void del();
    void modif();
    void statusAnnuler();
    void statusEnAttente();
    void statusRealiser();
};

#endif // LISTGRAPHIC_H
