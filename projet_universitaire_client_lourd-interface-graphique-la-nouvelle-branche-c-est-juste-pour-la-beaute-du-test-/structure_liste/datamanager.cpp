#include "datamanager.h"

DataManager::DataManager():userName(""),password(""),isConnected(false),isIdentified(false)
{
}


int DataManager::connection(const QString & _userName, const QString & _password, bool _isConnected, bool _isIdentified){
    if(_isIdentified==false && _isConnected==false){
        isIdentified=false;
        isConnected=false;
        return 0;
    }
    else if(_isIdentified==true && _isConnected==false){
        //regarder si l'utilisateur existe dans la bdd local
    }else if(_isIdentified==false && _isConnected==true){
        //se connecter au serveur (si il existe...)
    }else{
        //se connecter au serveur avec les identifiants
    }
    return 0;
}
