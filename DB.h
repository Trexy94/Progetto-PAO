#ifndef DB_H
#define DB_H
#include<utente.h>
void loadxml(std::map<QString, Utente*>& d);
void savexml(std::map<QString, Utente*>& d);


// il database di utenti LinQedIn
class DB {
    friend class LinQedInAdmin;
private:
    std::map<QString,Utente*> db;
public:
    void load() {loadxml(db);}
    // carica da file
    const std::map<QString,Utente*>::iterator begin(){return db.begin();}
    const std::map<QString,Utente*>::iterator end(){return db.end();}
    void save() {savexml(db);} // salva su file
    // cerca l'utente (con il suo tipo)
    // avente Username u nel DB
    bool findbool(QString);//questo dice solo se c'è
    std::map<QString,Utente*>::iterator find(Username);//questo lo restituisce
    ~DB();
};
#endif // DB_H
