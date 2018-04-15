#ifndef USER_H
#define USER_H

#include<QString>
#include<vector>
#include"list.h"

struct listInfo {
    int     idListe;
    QString title;
    QString owner;
};

class Admin;

class User
{
private:
    const QString               role;
          bool                  validated;

protected:
    int                         idUser;
    QString                     nickName;
    QString                     password;
    bool                        connected;
    std::vector<listInfo>       listsLegends;
    std::vector<List *>         loadedListes;

public:
    User(QString _nickName,QString _password,bool _validated,bool connected);
    User(QString _nickName);
    ~User();

    bool save();
    bool load();
    bool update();
    bool drop();

    bool createList();

    bool isConnected();

    bool loadListsLegends();
    List loadList(QString _idList);

    bool permissionToWrite();

    void setIdUser(int value);
    void setNickName(const QString &value);
    void setPassword(const QString &value);
    void setConnected(bool value);
    QString getNickName() const;
    int     getIdUser() const;
    QString getPassword() const;
};

#endif // USER_H
