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
          bool                  validated;// si l'utilisateur s'est connecté la premiere fois pour changer le mot de pass

protected:

    int                         idUser;
    QString                     nickName;
    QString                     password;
    bool                        connected;

    std::vector<listInfo>       listsLegends; // toutes les listes auxquelles l'user a acces (publiques et privés)
    std::vector<List *>         loadedListes; //cash en RAM


public:

    User(QString _nickName,QString _password,bool _validated,bool connected);
    User(QString _nickName);
    ~User();

    //metthodes user
    bool save();
    bool load();
    bool update();
    bool drop();

    bool createList();


    bool isConnected();

    bool loadListsLegends();
    List loadList(QString _idList);

    bool permissionToWrite();        /*tester si la liste est partagée en ecriture
                                           *=====>oui alors tester si user connecté
                                           *                =====>oui alors renvoyer true
                                           *                =====>non alors renvoyer false
                                           *=====>non alors tester si user est propriétaire de la liste
                                           *                =====>oui alors renvoyer true
                                           *                =====>non alors revoyer false
                                           */
                                           /*
                                            * donc ponser a une methode isSharedOnWrite
                                            * dans liste
                                            * qui  retourn false si aucun user appart owner ne
                                            * la modifier en ecriture
                                            */

    //setters getters
    void setIdUser(int value);
    void setNickName(const QString &value);
    void setPassword(const QString &value);
    void setConnected(bool value);

    QString getNickName() const;
    int     getIdUser() const;
    QString getPassword() const;
/**/
};

#endif // USER_H
