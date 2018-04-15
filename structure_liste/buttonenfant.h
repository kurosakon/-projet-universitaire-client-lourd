#ifndef BUTTONENFANT_H
#define BUTTONENFANT_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QMdiArea>
#include <QMdiSubWindow>
#include "element.h"
#include "list.h"
#include "listgraphics.h"

class ButtonEnfant:public QWidget
{

Q_OBJECT

private:
    Element* elt;
    QPushButton* b;
    QMdiArea* area;

public:
    ButtonEnfant(Element* e, QMdiArea *a);//On crée un bouton avec le titre de e. Le cliquer crée une listGraphic correspondant a e.

public slots:
    void expand();//affiche l'élément à l'écran
};

#endif // BUTTONENFANT_H
