#ifndef HEAD_H
#define HEAD_H
#include<iostream>
#include<vector>
#include<Info.h>
#include<utente.h>
class Rete {
    friend void savexml (std::map<QString,Utente*>&);
private:
    vector<QString> net;
public:
    void insert(QString s){net.push_back(s);}
    QString add(QString, DB*);
    QString remove(QString, DB*);
    QString get_rete();
    bool is_in(QString);
};

#endif // HEAD_H
