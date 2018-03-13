#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"

class Admin:public User
{

public:

    Admin(QString _nickName,QString _password);
    ~Admin();

    bool addUser(QString _nickName,QString _password); //obliger le user a modifier son password a la première connexion
    bool loadUser(QString _nickName);
    bool updateUser(QString _nickName,QString _password);
    bool deleteUser(QString _nickName);

    bool nickNameIsAvailable();
    User lookForUser(QString _nickName);

/***/
};

#endif // ADMIN_H
