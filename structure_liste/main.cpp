#include <QApplication>
#include <QHBoxLayout>
#include<iostream>
#include <QPushButton>
#include <QAction>


#include "mainwindow.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow * w=new MainWindow();
    w->show();

    return a.exec();
}
