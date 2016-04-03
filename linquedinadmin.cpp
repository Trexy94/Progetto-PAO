#include<LinQuedinAdmin.h>

QString LinQedInAdmin::remove(Username u)
{
    if (db->findbool(u.login))
    {
        Utente* da_eliminare=db->find(u)->second;
        delete da_eliminare->info;
        delete da_eliminare->rete;
        db->db.erase(u.login); return "<font color='green'>Operazione completata con successo</font>";}
    else
        return "<font color='red'>Errore, utente non presente nel database</font>";

}

void LinQedInAdmin::changeSubscriptionType(Username u, QString tu)
{
    std::map<QString,Utente*>::iterator target=db->find(u.login);
    target->second->tipologia_utente=tu;

}

void LinQedInAdmin::insert(QString username, QString tipoutente, QString name, QString cognome, QString citta, QString lavori, QString datanascita,QString lingue, QString telefono,QString email)
{
    Utente* valore=new Utente(Username(username));
    valore->info=new Info;
    valore->rete=new Rete;
    valore->info->Citta=citta;
    valore->info->Cognome=cognome;
    valore->info->data_nascita=datanascita;
    valore->info->lavori=lavori;
    valore->info->Nome=name;
    valore->info->lingue=lingue;
    valore->info->telefono=telefono;
    valore->info->email=email;
    valore->tipologia_utente=tipoutente;
    db->db.insert(std::pair<QString,Utente*>(username,valore));
}

QString LinQedInAdmin::find(Username u)
{
    if (!db->findbool(u.login)) return "<font color='red'>Errore! Utente non presente</font>";
        QString risposta="Ecco l'utente:\n";
        Utente* s=db->find(u)->second;
        risposta+=s->info->visualizza();
        risposta+=s->rete->get_rete();
        return risposta;
}

QString LinQedInAdmin::mostradb()
{
    return ShowXmlOnScreen();
}
