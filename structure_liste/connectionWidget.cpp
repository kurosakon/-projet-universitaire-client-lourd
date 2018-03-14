#include "connectionWidget.h"
#include "ui_connectionwidget.h"

#include <iostream>
ConnectionWidget::ConnectionWidget(User & _user, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectionWidget),
    user(_user)
{
    ui->setupUi(this);

    setFixedSize(width(),height());

    connect(ui->connection,SIGNAL(clicked(bool)),this,SLOT(connection(bool)));
    connect(ui->connectionWithoutId,SIGNAL(clicked(bool)),this,SLOT(connectionWithoutId(bool)));

    exec();
}

ConnectionWidget::~ConnectionWidget()
{
    delete ui;
}


void ConnectionWidget::connection(bool){
    //se connecter sur user
    int code=0;//code d'erreur
    if(code==0)
        close();
    else{
        //TODO
        //afficher les problemes
    }
}

void ConnectionWidget::connectionWithoutId(bool){
    //se connecter sur user en anonyme ?
    int code=0;//code d'erreur
    if(code==0)
        close();
    else{
        //TODO
        //afficher les problemes
    }
}
