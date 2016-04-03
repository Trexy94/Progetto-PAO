#include<DB.h>
#include<Info.h>
#include<Rete.h>
bool DB::findbool(QString x)
{
    if (db.find(x)!=db.end())
        return true;
    else
        return false;
}


std::map<QString,Utente*>::iterator DB::find(Username u)
{
      return (db.find(u.login));
}

DB::~DB()
{
 for (std::map<QString,Utente*>::iterator it=db.begin(); it!=db.end(); ++it)//dealloco tutti gli oggetti puntati
 {
     delete it->second->info;
     delete it->second->rete;
     delete it->second;
 }
 db.clear();//dealloco anche la pair
}

