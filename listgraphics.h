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
    QGridLayout* layout;
    QHBoxLayout* layoutButton;
    QVBoxLayout* layoutEnfant;
    QMdiArea* a;

    void newElt(InfoElement e);
    void newList(InfoElement e);
    void delElt();


public:
    ListGraphics(List *l, QMdiArea * area, QWidget* parent=0);

public slots:
    void add();
    void del();
    void modif();
};

#endif // LISTGRAPHIC_H
