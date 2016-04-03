#include<Info.h>

int translate(QString campo)
{
    if (campo=="Nome") return nome;
    else if (campo=="Cognome") return cognome ;
    else if (campo=="Data di nascita") return data;
    else if(campo=="Città") return citta;
    else if(campo=="Lavoro") return lavoro;
    else if(campo=="Lingue parlate") return lingua;
    else if(campo=="Telefono") return ntel;
    else if(campo=="E-mail") return mail;
    return -1;
}

QString Info::visualizza()
{
   return ("Nome: "+Nome+"\n"+"Cognome: "+Cognome+"\n"+"Data di nascita: "+data_nascita+"\n"+"città di residenza: "+Citta+"\n"+"lavori: "+lavori+"\n"+"lingue parlate: "+lingue+"\n"+"telefono: "+telefono+"\n"+"email: "+email+"\n");
}

bool Info::trovato(const int campo, QString & da_trovare)
{
    switch (campo)
    {
    case (nome):
        return Nome.contains(da_trovare,Qt::CaseInsensitive);
        break;
    case(cognome):
        return Cognome.contains(da_trovare,Qt::CaseInsensitive);
        break;
    case(data):
        return data_nascita.contains(da_trovare,Qt::CaseInsensitive);
        break;
    case(citta):
        return Citta.contains(da_trovare,Qt::CaseInsensitive);
        break;
    case(lavoro):
        return lavori.contains(da_trovare,Qt::CaseInsensitive);
        break;
    case (lingua):
        return lingue.contains(da_trovare,Qt::CaseInsensitive);
        break;
    case (ntel):
        return telefono.contains(da_trovare,Qt::CaseInsensitive);
        break;
    case (mail):
        return email.contains(da_trovare,Qt::CaseInsensitive);
    }
    return false;
}

void Info::modifica(const int x,QString value)
{
    switch (x)
    {
    case (nome):
        Nome=value;
        break;
    case(cognome):
        Cognome=value;
        break;
    case(data):
        data_nascita=value;
        break;
    case(citta):
        Citta=value;
        break;
    case(lavoro):
        lavori=value;
        break;
    case (lingua):
        lingue=(value);
        break;
    case (ntel):
        telefono=(value);
        break;
    case (mail):
        email=value;
    }
}

