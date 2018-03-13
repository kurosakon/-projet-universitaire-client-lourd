#ifndef CONNECTIONBUTTON_H
#define CONNECTIONBUTTON_H

#include "user.h"

#include <QDialog>
namespace Ui {
class ConnectionWidget;
}

class ConnectionWidget : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectionWidget(User & _user,QWidget *parent = 0);
    ~ConnectionWidget();


private:
    Ui::ConnectionWidget *  ui;
    User                    user;

private slots:
    void connection(bool);
    void connectionWithoutId(bool);
};

#endif // CONNECTIONBUTTON_H
