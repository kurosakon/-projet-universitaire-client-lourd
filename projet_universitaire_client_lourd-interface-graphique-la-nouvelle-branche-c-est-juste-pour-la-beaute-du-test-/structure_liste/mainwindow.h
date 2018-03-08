#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "tree.h"
#include "listgraphics.h"
#include "connectionWidget.h"
#include "datamanager.h"

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
    ListGraphics *  lg;
    DataManager     dm;



    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public slots:
   void             deleteElement();
   void             connection();
   void             updateActions();
   void             newListGraphic(const QModelIndex & index);
};

#endif // MAINWINDOW_H
