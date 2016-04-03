#include<Rete.h>
#include<DB.h>

QString Rete::get_rete()
{
    QString rete="amici:\n";
    if(!net.empty()) for(unsigned int i=0;i<(net.size());i++)
    {
        rete+=net[i]+"\n";
    }
    else
    rete+="nessuno";//nel caso di un forever alone
    return rete;

}

bool Rete::is_in(QString amico)
{
     if(std::find(net.begin(),net.end(),amico)==net.end())
         return false;
                 else
         return true;
}

QString Rete::add(QString u, DB*db)
{
    QString amico(u);
    if((db->find(u)!=db->end()) &&  !is_in(u))
    { net.push_back(amico); db->save(); return "<font color='blue'>Utente correttamente inserito nella tua rete</font>";}//invoco il save qui per ragioni di maggior coerenza tra il db effettivo e quello su file
    else
        if (is_in(u))
    return "<font color='red'>utente già presente</font>";
    else
            return "<font color='red'>utente inesistente</font>";
}

QString Rete::remove(QString u,DB*db)
{
std::vector<QString>::iterator it=std::find(net.begin(),net.end(),u);
if(it!=net.end())
{ net.erase(it); db->save(); return "<font color='blue'> Utente rimosso</font>";}//salvo qui per lo stesso motivo
else
return "<font color='red'>utente non presente nella lista amici</font>";
}
