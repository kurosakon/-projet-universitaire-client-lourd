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
    std::vector<QString>    tags;

    InfoElement(QString _title, QString _description, QString _creationDate, QString _modificationDate,const std::vector<QString> & tags={});
};

#endif // INFOELEMENT_H
