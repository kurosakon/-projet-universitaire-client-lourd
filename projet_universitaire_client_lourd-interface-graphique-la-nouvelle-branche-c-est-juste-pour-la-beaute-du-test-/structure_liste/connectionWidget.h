#ifndef CONNECTIONBUTTON_H
#define CONNECTIONBUTTON_H

#include "datamanager.h"

#include <QDialog>
namespace Ui {
class ConnectionWidget;
}

class ConnectionWidget : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectionWidget(DataManager & dm,QWidget *parent = 0);
    ~ConnectionWidget();


private:
    Ui::ConnectionWidget *  ui;
    DataManager             dm;

private slots:
    void connection(bool);
    void connectionWithoutId(bool);
};

#endif // CONNECTIONBUTTON_H
