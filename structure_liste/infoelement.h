#ifndef INFOELEMENT_H
#define INFOELEMENT_H

#include<QString>

enum Type{
    ELEMENT,
    LIST
};


class InfoElement
{
public:
    QString         title;
    QString         description;
    QString         creationDate;
    QString         modificationDate;
    QString         tag1;
    QString         tag2;

    InfoElement(QString _title, QString _description, QString _creationDate, QString _modificationDate,
                QString t1=0, QString t2=0);
};

#endif // INFOELEMENT_H
