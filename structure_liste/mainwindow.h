#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "tree.h"
#include "listgraphics.h"

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

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public slots:
   void             deleteElement();
   void             updateActions();
};

#endif // MAINWINDOW_H
