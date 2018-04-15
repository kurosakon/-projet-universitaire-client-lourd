#include "infoelement.h"

InfoElement::InfoElement(QString _title, QString _description, QString _creationDate, QString _modificationDate, Status _status, const std::vector<QString> & _tags):
    title(_title),description(_description),creationDate(_creationDate),modificationDate(_modificationDate),tags(_tags),status(_status)
{

}



