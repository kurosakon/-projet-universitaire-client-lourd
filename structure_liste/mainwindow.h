#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "tree.h"
#include "listgraphics.h"
#include "connectionWidget.h"
#include "user.h"

#include <QMainWindow>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Tree *          tree;
    ListModel *     model;
    List *          root;
    QMdiArea *      area;
    std::vector<ListGraphics *>  lgs;
    User            user;



    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public:
    void            update();

public slots:
   void             deleteElement();
   void             addElement();
   void             setElement();
   void             connection();
   void             updateActions();
   void             treeMenu( const QPoint & pos );
   void             newListGraphic(const QModelIndex & index);
};

#endif // MAINWINDOW_H
