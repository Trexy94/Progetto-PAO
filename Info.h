#ifndef INFO_H
#define INFO_H
#include<iostream>
#include<vector>
#include<QString>
#include<map>

using std::vector;
using std::string;
enum info {nome=0,cognome=1,data=2,citta=3,lavoro=4,lingua=5, ntel=6, mail=7};

class Info {
public:
    bool trovato(const int,QString&);
    QString visualizza ();
    void modifica (const int,QString);
    QString Nome;
    QString Cognome;
    QString data_nascita;
    QString Citta;
    QString lavori;
    QString lingue;
    QString telefono;
    QString email;
};
#endif // INFO_H
