#ifndef TIPI_DI_UTENTI_H
#define TIPI_DI_UTENTI_H
#include<utente.h>

class UtenteBasic: public Utente {
public:
    UtenteBasic(Utente*);
    // overriding: ricerca per un utente Basic
    virtual QString userSearch(DB&) const;
    virtual QString Ricercausername(DB&,Username& ) const;
};

class UtenteBusiness: public Utente {
public:
    UtenteBusiness(Utente*);
    // overriding: ricerca per un utente Business
    virtual QString userSearch(DB& ) const;
    virtual QString Ricercausername(DB& ,Username& ) const;
    virtual QString Ricercaincampo(DB&,const int,QString&)const;
};



class UtenteExecutive: public Utente {
public:
    UtenteExecutive(Utente*);
    // overriding: ricerca per un utente Executive
    virtual QString userSearch(DB&) const;
    virtual QString Ricercausername(DB& d,Username& x) const;
    virtual QString Ricercaincampo(DB&,const int,QString&)const;
};

#endif // TIPI_DI_UTENTI_H
