#include "elementwidget.h"
#include "ui_elementwidget.h"

ElementWidget::ElementWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ElementWidget)
{
    ui->setupUi(this);
}

ElementWidget::~ElementWidget()
{
    delete ui;
}
