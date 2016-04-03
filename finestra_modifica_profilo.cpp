#include<finestra_modifica_profilo.h>
#include<qmessagebox.h>
void Profilo::conferma()
{
    for (int i=0; i<campi; i++)
    {
        if (lineEdit[i]->text()=="") lineEdit[i]->setText("non specificato");
        profilo->modifica(i,lineEdit[i]->text());
    }
    db->save(); close();
    QMessageBox msgBox;
    msgBox.setText("Operazione completata con successo.");
    msgBox.exec();
}

void Profilo::inizializza(Info* profile, DB*d){profilo=profile;db=d;}

void Profilo::inizializza_contenuto()
{
    lineEdit[0]->setText(profilo->Nome);

    lineEdit[1]->setText(profilo->Cognome);

    lineEdit[2]->setText(profilo->data_nascita);

    lineEdit[3]->setText(profilo->Citta);

    lineEdit[5]->setText(profilo->lingue);

    lineEdit[6]->setText(profilo->telefono);

    lineEdit[7]->setText(profilo->email);
}

void Profilo::inizializza_label()
{
    label[0]->setText("Nome");

    label[1]->setText("Cognome");

    label[2]->setText("Data di nascita");

    label[3]->setText("città di residenza");

    label[4]->setText("lavori");
    lineEdit[4]->setText(profilo->lavori);

    label[5]->setText("lingue parlate");

    label[6]->setText("telefono");

    label[7]->setText("email");
}

Profilo::Profilo(Info*u , DB*db) {
inizializza(u,db);
setWindowTitle("modifica profilo");
// Layout principale della dialog
QVBoxLayout* mainLayout = new QVBoxLayout(this);
for(int i=0;i<campi;i++)
{
label[i]=new QLabel(this);
lineEdit[i]=new QLineEdit(this);
label[i]->setBuddy(lineEdit[i]);
}
button[0]=new QPushButton(this);
button[1]=new QPushButton(this);

inizializza_label();
inizializza_contenuto();

for(int i=0;i<campi;i++)
{
mainLayout->addWidget(label[i]);
mainLayout->addWidget(lineEdit[i]);
}


button[0]->setText("Conferma le modifiche");
mainLayout->addWidget(button[0]);
connect(button[0], SIGNAL(clicked()), this, SLOT(conferma()));


button[1]->setText("Esci senza salvare");
mainLayout->addWidget(button[1]);
connect(button[1], SIGNAL(clicked()), this, SLOT(close()));


setLayout(mainLayout);

}
