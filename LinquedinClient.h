#ifndef LINQUEDINCLIENT_H
#define LINQUEDINCLIENT_H
#include<utente.h>
#include<Info.h>
#include<Rete.h>
#include<DB.h>
#include<tipi_di_utenti.h>
// lato client
class LinQedInClient {
public:
    Utente* u;
    QString tu;
    DB* db; // inizializzato da file,
    // usato in sola lettura
    LinQedInClient(Username);

    QString showProfilo();

    QString  insertRete(Username un);

    QString removeRete(Username un);
    // funzionalita` di ricerca autorizzate per u
    QString ricerca();
    QString ricerca_per_username(Username un);
    QString search(const int,QString);
    ~LinQedInClient();
};
#endif // LINQUEDINCLIENT_H
