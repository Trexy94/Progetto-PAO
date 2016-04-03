#ifndef UTENTE_H
#define UTENTE_H
#include<QString>
#include<map>

class DB;
class Rete;
class Info;

class Username {
public:
    QString login;
    Username(QString s): login(s) {}
};

class Utente {
    friend void loadxml(std::map<std::string,Utente*>&);
    friend class LinQedInAdmin;
    friend void ReadUtente(Utente* utente);
private:
    QString tipologia_utente;//basic,business,excecutive
public:
    QString get_tipologia_utente(){return tipologia_utente;}
    Info* info;
    Rete* rete;
    Username un;
    Utente(Username u=Username("")): un(u) {}
    virtual ~Utente() {}
    // la ricerca permessa dalla propria tipologia di subscription
    virtual QString userSearch(DB& ) const;//default
    virtual QString Ricercausername(DB& ,Username&) const;
    virtual QString Ricercaincampo(DB&,const int,QString&)const ;
};
#endif // UTENTE_H
