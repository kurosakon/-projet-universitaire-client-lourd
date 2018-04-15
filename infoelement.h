#ifndef INFOELEMENT_H
#define INFOELEMENT_H

#include<QString>

enum Type{
    ELEMENT,
    LIST
};

enum Status{
    RIEN
};

class InfoElement
{
public:
    QString         title;
    QString         description;
    QString         creationDate;
    QString         modificationDate;
    std::vector<QString>    tags;
    Status          status;

    InfoElement(QString _title, QString _description, QString _creationDate, QString _modificationDate,Status _status=RIEN,const std::vector<QString> & tags={});
};

#endif // INFOELEMENT_H
