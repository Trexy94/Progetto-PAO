#include<LinquedinClient.h>
LinQedInClient::LinQedInClient(Username s)
{
    db=new DB;
    // carica il DB
    db->load();
    Utente*utemp=(db->find(s)->second);
    tu=utemp->get_tipologia_utente();
    // cerca l'utente client con Username s
    if(tu=="business")
    u = new UtenteBusiness(utemp);
    else if (tu=="executive")
        u=new UtenteExecutive(utemp);
                else
                u=new UtenteBasic(utemp);

}

QString LinQedInClient::showProfilo() {
return ("Ecco il tuo profilo:\nsei un utente "+tu+"\n"+u->info->visualizza()+u->rete->get_rete());
}

QString  LinQedInClient::insertRete(Username un) {
    if (un.login!=this->u->un.login)
return u->rete->add(un.login,db);
    else
        return "<font color='purple'>non puoi essere amico di te stesso! -.-'' </font>";
}

QString LinQedInClient::removeRete(Username un) {
    if (un.login!=this->u->un.login)
        return u->rete->remove(un.login,db);
    else
        return "<font color='purple'>Perchè vuoi autoeliminarti? O.o</font>";
}

QString LinQedInClient::ricerca() { return "Ecco il database: \n"+u->userSearch(*db); }
QString LinQedInClient::ricerca_per_username(Username un)
{
    if (un.login!=this->u->un.login)
            return u->Ricercausername(*db, un);
    else
        return "<font color='purple'>Per vedere il tuo profilo c'è il tasto apposito ;)</font>";

}

QString LinQedInClient::search(const int campo , QString da_cercare)
{
    return u->Ricercaincampo(*db,campo,da_cercare);
}

LinQedInClient::~LinQedInClient(){delete db; delete u;}
