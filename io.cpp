#include <QFile>
#include <QXmlStreamWriter>
#include<QXmlStreamReader>
#include<DB.h>
#include<Info.h>
#include<Rete.h>
#include<QTextStream>
QXmlStreamReader Rxml;


void savexml (std::map<QString,Utente*>& db)//non uso accenti per evitare problemi di compatibilità per editor che non usano l'UTF8
{
    QFile file("database.xml");
    file.open(QIODevice::WriteOnly);

    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();

    xmlWriter.writeStartElement("Database");
      for (std::map<QString,Utente*>::iterator it=db.begin(); it!=db.end(); ++it)
    {
    xmlWriter.writeStartElement((it->first));
    xmlWriter.writeTextElement("nome", (it->second->info->Nome));
    xmlWriter.writeTextElement("cognome",(it->second->info->Cognome));
    xmlWriter.writeTextElement("data_nascita", (it->second->info->data_nascita));
    xmlWriter.writeTextElement("citta", (it->second->info->Citta));
    xmlWriter.writeTextElement("lavori", it->second->info->lavori);
    xmlWriter.writeTextElement("lingue", it->second->info->lingue);
    xmlWriter.writeTextElement("telefono", it->second->info->telefono);
    xmlWriter.writeTextElement("email", it->second->info->email);
    xmlWriter.writeTextElement("tipologia_utente",(it->second->get_tipologia_utente())); 
    if(!(it->second->rete->net.empty())) for(unsigned int i=0;i<(it->second->rete->net.size());i++)
    {
        xmlWriter.writeTextElement("amico",(it->second->rete->net[i]));
    }
    xmlWriter.writeEndElement();
    }
    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();
    file.close();
}
void READNEXT()//per facilitare la comprensione
{
    Rxml.readNext();
}

QString get_Element()
{
    while(!Rxml.atEnd())
        {
            if(Rxml.isEndElement())
            {
                READNEXT();
                break;
            }
            else if(Rxml.isStartElement())
            {
               return (Rxml.readElementText());
               READNEXT();
               break;

            }
            else if(Rxml.isCharacters())
            {
                READNEXT();
            }
            else
            {
                READNEXT();
            }
        }
    return "";
}

void ReadUtente(Utente* utente)
{
    while(!Rxml.atEnd())
    {
        if(Rxml.isEndElement())
        {
            READNEXT();
            break;
        }
        else if(Rxml.isCharacters())
        {
            READNEXT();
        }
        else if(Rxml.isStartElement())
        {
            if(Rxml.name() == "amico")//alla fine gli amici dovrebbero essere più degli altri., quindi vanno prima, per guadagnare in efficenza
            {
                utente->rete->insert(get_Element());
            }
            else if(Rxml.name() == "nome")
            {
               utente->info->Nome=get_Element();
            }
            else if(Rxml.name() == "cognome")
            {
                utente->info->Cognome=get_Element();
            }
            else if(Rxml.name() == "data_nascita")
            {
                utente->info->data_nascita=get_Element();
            }
            else if(Rxml.name() == "citta")
            {
                utente->info->Citta=get_Element();
            }
            else if(Rxml.name() == "lavori")
            {
               utente->info->lavori= get_Element();
            }
            else if(Rxml.name() == "lingue")
            {
                utente->info->lingue=get_Element();
            }
            else if (Rxml.name() == "telefono")
            {
                utente->info->telefono=get_Element();
            }
            else if (Rxml.name() == "email")
            {
                utente->info->email=get_Element();
            }
            else if(Rxml.name() == "tipologia_utente")
            {
                utente->tipologia_utente=get_Element();
            }
            READNEXT();
        }
        else
        {
            READNEXT();
        }
    }
}

void loadxml(std::map<QString,Utente*>& d)
{
    QFile file("database.xml");
        if (!file.exists())
    {
            file.open(QIODevice::WriteOnly);

            QXmlStreamWriter xmlWriter(&file);
            xmlWriter.setAutoFormatting(true);
            xmlWriter.writeStartDocument();

            xmlWriter.writeStartElement("Database");


            xmlWriter.writeEndElement();
            xmlWriter.writeEndDocument();

            file.close();
    }
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        std::cout << "Error: Cannot read file " << qPrintable("database.xml")
                  << ": " << qPrintable(file.errorString())
                  << std::endl;

    }
    Rxml.setDevice(&file);
    Rxml.readNext();
    while(!Rxml.atEnd())
        {
            if(Rxml.isStartElement())//
            {
                    if(Rxml.name() == "Database")
                    {
                        READNEXT();
                    }
                    else if(Rxml.isStartElement())
                    {
                        QString chiave=(Rxml.name().toString());
                        Utente* valore=new Utente(Username((chiave)));
                        valore->info= new Info;
                        valore->rete= new Rete;
                        ReadUtente(valore);//entra
                        d.insert(std::pair<QString,Utente*>(chiave,valore));
                    }
                    else
                    {
                        std::cout<<"no bookindex file";
                    }

            }
            else
            {
                READNEXT();
            }
        }
      file.close();
      if (Rxml.hasError())
          {
             std::cout << "Error: Failed to parse file "
                       << qPrintable("database.xml") << ": "
                       << qPrintable(Rxml.errorString()) << std::endl;

          }
      else if (file.error() != QFile::NoError)
      {
          std::cout << "Error: Cannot read file " << qPrintable("prova.xml")
                    << ": " << qPrintable(file.errorString())
                    << std::endl;
      }
}

QString ShowXmlOnScreen()
{
    QFile file("database.xml");
         if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
             return"Errore, impossibile aprire il file!";
         QString risposta="";
         while (!file.atEnd())
         {
             risposta+= file.readLine();
         }
         return risposta;
}

void save_admin_password(QString& password)
{
  QFile file("password.txt");
  file.open(QIODevice::WriteOnly);
  file.write(password.toUtf8());
  file.close();
}

bool Adminlogged(QString password)
{
    QFile file("password.txt");
    if (!file.exists())
    {
        file.open(QIODevice::WriteOnly);
        file.write("Admin");
        file.close();
    }
    if(file.open(QFile::ReadOnly | QFile::Text))
    {
        QString password_corretta;
        QTextStream in(&file);
        while (!in.atEnd())
        {
            password_corretta=in.readLine()+password_corretta;//per evitare inconvenienti faccio così
        }
        if (password==password_corretta)
            return true;
        else
            return false;
    }
    else
        return false;
}

