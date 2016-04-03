#include<tipi_di_utenti.h>
#include<Info.h>
#include<Rete.h>
#include<DB.h>

QString UtenteBasic::userSearch(DB &d) const
{
    int contautenti=1;
    QString risposta="";
    for (std::map<QString,Utente*>::iterator it=d.begin(); it!=d.end(); ++it)
    {
        if (it->first==un.login)
            continue;
        if (rete->is_in(it->second->un.login))
        {
            risposta+="\n\nutente amico, puoi vedere il profilo intero anche se sei basic: "+it->second->un.login+ "\n"; contautenti++;
            risposta+=it->second->info->visualizza();
            risposta+=it->second->rete->get_rete();
        }
        else
        {
            risposta+="\n\nutente: "+QString::number(contautenti)+ "\n"; contautenti++;
            risposta+=("Nome: " +(it->second->info->Nome)+"\n");
            risposta+=("Cognome: "+(it->second->info->Cognome)+"\n");
        }
    }
    if (risposta=="") return "Spiacente, nessun risultato :(";
    return risposta;
}

QString UtenteBasic::Ricercausername(DB &d, Username& x) const
{
    if (!d.findbool(x.login)) return "<font color='red'>Errore! Utente non presente</font>";
    QString risposta="";
    Utente* s=d.find(x)->second;
    if (rete->is_in(s->un.login))
    {
        risposta+="l'utente è tuo amico :) \n ecco il suo profilo: \n\n"+s->info->visualizza()+s->rete->get_rete();
    }
    else
    {
        risposta+=("Ecco l'utente:\n Nome: "+ (s->info->Nome)+"\n");
        risposta+=("Cognome: "+(s->info->Cognome)+"\n");
    }
    return risposta;
}

QString UtenteBusiness::userSearch(DB& d) const {
    QString risposta="";
    int contautenti=1;
    for (std::map<QString,Utente*>::iterator it=d.begin(); it!=d.end(); ++it)
    {   if (it->first==this->un.login)
            continue;
        if (rete->is_in(it->second->un.login))
        {
            risposta+=("\n\nl'utente è tuo amico :) \n ecco il suo profilo: \n\nutente: "+it->second->un.login+ "\n"+it->second->info->visualizza()+it->second->rete->get_rete());
        }
        else
        {
            risposta+="\n\nutente: "+QString::number(contautenti)+ "\n";contautenti++;
            risposta+=it->second->info->visualizza();
        }

    }
    if (risposta=="") return "Spiacente, nessun risultato :(";
    return risposta;
}


QString UtenteBusiness::Ricercausername(DB& d,Username& x) const
{
    if (!d.findbool(x.login)) return "<font color='red'>Errore! Utente non presente</font>";
    QString risposta="Ecco l'utente:\n";
    Utente* s=d.find(x)->second;
    if (rete->is_in(s->un.login))
        risposta+="l'utente è tuo amico :) \n ecco il suo profilo: \n\nutente: "+s->un.login+ "\n"+s->info->visualizza()+s->rete->get_rete();
    else
        risposta+=s->info->visualizza();
    return risposta;
}

QString UtenteBusiness::Ricercaincampo(DB & d, const int campo, QString & da_cercare) const
{
    int contautenti=1;
    QString risposta="";
    for (std::map<QString,Utente*>::iterator it=d.begin(); it!=d.end(); ++it)
    {
        if (!it->second->info->trovato(campo,da_cercare)|| it->first==this->un.login)
            continue;
        risposta+="\n\nutente: "+QString::number(contautenti)+ "\n";contautenti++;
        risposta+=it->second->info->visualizza();
    }
    if (risposta=="") return "Spiacente, nessun risultato :(";
    else
        return risposta;
}

QString UtenteExecutive::userSearch(DB& d) const {
    QString risposta="\nsiccome sei un utente Executive, hai diritto a vedere l'intero database \n";
    for (std::map<QString,Utente*>::iterator it=d.begin(); it!=d.end(); ++it)
    {
        if (it->first==this->un.login)
            continue;
        if (rete->is_in(it->second->un.login))
        {
            risposta+="\n\nl'utente è tuo amico :) \n ecco il suo profilo: \n\nutente: "+it->second->un.login+ "\n"+it->second->info->visualizza()+it->second->rete->get_rete();
        }
        else
        {
            risposta+="\n\nutente: "+it->second->un.login+ "\n";
            risposta+=it->second->info->visualizza()+it->second->rete->get_rete();
        }
    }
    if (risposta=="\nsiccome sei un utente Executive, hai diritto a vedere l'intero database \n") return "Spiacente, nessun risultato :(";
    return risposta;
}
QString UtenteExecutive::Ricercausername(DB& d,Username& x) const
{
    if (!d.findbool(x.login)) return "<font color='red'>Errore! Utente non presente</font>";
    Utente* s=d.find(x)->second;
    if (rete->is_in(s->un.login))
    {
        return"l'utente è tuo amico :) \n ecco il suo profilo: \n\nutente: "+s->un.login+ "\n"+s->info->visualizza()+s->rete->get_rete();
    }
    return "Ecco l'utente:\n"+s->info->visualizza()+ s->rete->get_rete();
}

QString UtenteExecutive::Ricercaincampo(DB & d , const int campo, QString & da_cercare) const
{
    int contautenti=1;
    QString risposta="";
    for (std::map<QString,Utente*>::iterator it=d.begin(); it!=d.end(); ++it)
    {
        if (!it->second->info->trovato(campo,da_cercare) || it->first==this->un.login)
            continue;
        risposta+="\n\nutente: "+it->second->un.login+ "\n";contautenti++;
        risposta+=it->second->info->visualizza()+it->second->rete->get_rete();

    }
    if (risposta=="") return "Spiacente, nessun risultato :(";
    else
        return risposta;
}

UtenteBasic::UtenteBasic(Utente* ut)
{
    this->info=ut->info;
    this->rete=ut->rete;
    this->un=ut->un;
}



UtenteBusiness::UtenteBusiness(Utente* ut)
{
    this->info=ut->info;
    this->rete=ut->rete;
    this->un=ut->un;
}



UtenteExecutive::UtenteExecutive(Utente* ut)
{
    this->info=ut->info;
    this->rete=ut->rete;
    this->un=ut->un;
}


QString Utente::userSearch(DB &d) const //queste 2 si presume non vengano invocate mai, le metto per avere un caso di default
{
    delete &d;
    return "errore!!!!";
}
QString Utente::Ricercausername(DB &d, Username& x) const
{
    delete &d; std::cout<<x.login.toStdString();
    return "errore!!!!";
}
QString Utente::Ricercaincampo(DB&d,const int campo,QString& da_cercare)const//questa serve anche in caso per caso comparisse in un Utente_basic il pulsante in qualche modo imprevisto
{
    delete &d;
    return campo+da_cercare+"Errore, funzionalità riservata a utenti di categoria superiore";
}
