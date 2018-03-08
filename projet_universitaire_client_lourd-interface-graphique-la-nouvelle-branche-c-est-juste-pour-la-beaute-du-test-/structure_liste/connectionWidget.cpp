#include "connectionWidget.h"
#include "ui_connectionwidget.h"
#include <iostream>
ConnectionWidget::ConnectionWidget(DataManager & dm, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectionWidget),
    dm(dm)
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
    int code=dm.connection(ui->userName->text(),ui->password->text(),!ui->outline->isChecked(),true);
    if(code==0)
        close();
    else{
        //TODO
        //afficher les problemes
    }
}

void ConnectionWidget::connectionWithoutId(bool){
    int code=dm.connection("","",!ui->outline->isChecked(),false);
    if(code==0)
        close();
    else{
        //TODO
        //afficher les problemes
    }
}
