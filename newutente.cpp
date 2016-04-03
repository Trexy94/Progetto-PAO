#include <QMainWindow>
#include <QApplication>
#include <QLabel>
#include <QFont>
#include <QPushButton>
#include <QWidget>
#include<qtextedit.h>
#include<QGroupBox>
#include<QLineEdit>
#include<QAction>
#include<QBoxLayout>
#include<QMenu>
#include<QMenuBar>
#include<string>
#include<LinQuedinAdmin.h>
#include<newutente.h>
#include<admin.h>
#include<qmessagebox.h>

void NewUtente::conferma()
{

    if (administrator->db->findbool(lineEdit[0]->text()))
    {
        barra_stato->setText("<font color='red'>Errore,utente già presente nel database</font>");
    }
    else if (lineEdit[0]->text()=="") barra_stato->setText("<font color='red'>Inserisci almeno lo username!</font>"); else
    {
        for(int i=1;i<(campi-1);i++)
        {
            if(lineEdit[i]->text()=="") lineEdit[i]->setText("non specificato");
        }
        administrator->insert(lineEdit[0]->text(),tipou->currentText(),lineEdit[1]->text(),lineEdit[2]->text(),lineEdit[3]->text(),lineEdit[4]->text(),lineEdit[5]->text(),lineEdit[6]->text(),lineEdit[7]->text(),lineEdit[8]->text());
        administrator->save();
        for(int i=0;i<(campi-1);i++)
        {
           lineEdit[i]->setText("");
        }
        close();
        QMessageBox msgBox;
        msgBox.setText("Utente aggiunto con successo");
        msgBox.exec();
    }
}

void NewUtente::inizializza (LinQedInAdmin* admin){administrator=admin;}

void NewUtente::inizializza_campi()
{

    label[0]->setText("Tipologia utente");
    label[0]->setBuddy(tipou);
    tipou->setEditable(false);
    tipou->addItem("basic");
    tipou->addItem("business");
    tipou->addItem("executive");

    label[1]->setText("Username");
    label[1]->setBuddy(lineEdit[0]);


    label[2]->setText("Nome");
    label[2]->setBuddy(lineEdit[1]);

    label[3]->setText("Cognome");
    label[3]->setBuddy(lineEdit[2]);

    label[4]->setText("città di residenza");
    label[4]->setBuddy(lineEdit[3]);

    label[5]->setText("lavori");
    label[5]->setBuddy(lineEdit[4]);

    label[6]->setText("Data di nascita");
    label[6]->setBuddy(lineEdit[5]);

    label[7]->setText("lingue parlate");
    label[7]->setBuddy(lineEdit[6]);

    label[8]->setText("telefono");
    label[8]->setBuddy(lineEdit[7]);

    label[9]->setText("email");
    label[9]->setBuddy(lineEdit[8]);
}

NewUtente::NewUtente(LinQedInAdmin * admin) {
inizializza(admin);
setWindowTitle("Inserisci utente");
// Layout principale della dialog
QVBoxLayout* mainLayout = new QVBoxLayout(this);
for(int i=0;i<campi;i++)
{
label[i]=new QLabel(this);
if (i!=(campi-1))
lineEdit[i]=new QLineEdit(this);
}
tipou=new QComboBox(this);
button[0]=new QPushButton(this);
button[1]=new QPushButton(this);

inizializza_campi();
mainLayout->addWidget(label[0]);
mainLayout->addWidget(tipou);
for(int i=0;i<(campi-1);i++)
{
mainLayout->addWidget(label[i+1]);
mainLayout->addWidget(lineEdit[i]);
}

barra_stato=new QTextEdit(this);
barra_stato->setText("compila i campi e clicca 'conferma le modifiche' per inserire un nuovo utente");
barra_stato->setReadOnly(true);
mainLayout->addWidget(barra_stato);

button[0]->setText("Conferma le modifiche");
mainLayout->addWidget(button[0]);
connect(button[0], SIGNAL(clicked()), this, SLOT(conferma()));


button[1]->setText("Esci");
mainLayout->addWidget(button[1]);
connect(button[1], SIGNAL(clicked()), this, SLOT(close()));


setLayout(mainLayout);

}
