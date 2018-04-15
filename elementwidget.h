#ifndef ELEMENTWIDGET_H
#define ELEMENTWIDGET_H

#include <QWidget>

namespace Ui {
class ElementWidget;
}

class ElementWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ElementWidget(QWidget *parent = 0);
    ~ElementWidget();

private:
    Ui::ElementWidget *ui;
};

#endif // ELEMENTWIDGET_H
