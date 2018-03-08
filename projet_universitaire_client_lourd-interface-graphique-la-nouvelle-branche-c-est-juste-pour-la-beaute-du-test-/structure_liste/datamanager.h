#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include "list.h"

#include <QString>

class DataManager
{
private:
    QString     userName;
    QString     password;
    bool        isConnected;
    bool        isIdentified;

public:
    DataManager();
    //retourne un numero d'erreur (0 si tout va bien, 1 si mauvais username, 2 si pas de connection...)
    int connection(const QString & _userName, const QString & _password, bool _isConnected, bool _isIdentified);


    //int est un numero d'erreur ici aussi
    int load(List *)const;
    int save(List *)const;
};

#endif // DATAMANAGER_H
