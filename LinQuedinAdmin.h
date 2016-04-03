#ifndef LINQUEDINADMIN_H
#define LINQUEDINADMIN_H
#include<utente.h>
#include<Rete.h>
#include<Info.h>
#include<DB.h>
QString ShowXmlOnScreen();


class LinQedInAdmin {
public:
    DB* db; // inizializzato da file,
    // gestito in memoria,
    // salvabile su file
    LinQedInAdmin() {db=new DB; db->load();}//carica da file
    void insert(QString, QString, QString, QString, QString, QString, QString,QString,QString,QString);//potevo metterlo in un array, ma così è più chiaro...
    QString find(Username u);
    QString remove(Username u);
    // cambia tra Basic, Business, Executive!
    void changeSubscriptionType(Username,QString);
    QString mostradb();
    void save()  { db->save(); }
    ~LinQedInAdmin(){delete db;}
};


#endif // LINQUEDINADMIN_H
