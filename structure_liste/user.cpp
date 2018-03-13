#include "user.h"

User::User(QString _nickName,QString _password,bool _validated,bool _connected):
role("USER"),nickName(_nickName),password(_password),validated(_validated),connected(_connected)
{

}
User::User(QString _nickName):nickName(_nickName)
{

}



/* setters & getters */

int User::getIdUser() const
{
    return idUser;
}

QString User::getPassword() const
{
    return password;
}

QString User::getNickName() const
{
    return nickName;
}

void User::setConnected(bool value)
{
    connected = value;
}

void User::setIdUser(int value)
{
    idUser = value;
}

void User::setNickName(const QString &value)
{
    nickName = value;
}

void User::setPassword(const QString &value)
{
    password = value;
}
