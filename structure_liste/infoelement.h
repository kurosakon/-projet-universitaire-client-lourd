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

    InfoElement(QString _title, QString _description, QString _creationDate, QString _modificationDate);
};

#endif // INFOELEMENT_H
