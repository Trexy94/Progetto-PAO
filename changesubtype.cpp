#include<admin.h>
#include<LinQuedinAdmin.h>
#include<changesubtype.h>
#include<qmessagebox.h>
ChangeSubType::ChangeSubType(LinQedInAdmin* admin)
{
    inizializza(admin);
    setUpGUI();
    setWindowTitle( tr("Cambia tipo iscrizione") );
}

void ChangeSubType::setUpGUI(){
    // set up layout
    QGridLayout* formGridLayout = new QGridLayout( this );
    writeutente= new QLineEdit( this );
    labelutente = new QLabel( this );
    labelutente->setText( tr( "scrivi lo username" ) );
    labelutente->setBuddy( writeutente );
    tipou=new QLabel(this);
    tipou->setText(tr("seleziona tipologia di destinazione"));
    seleziona_arrivo=new QComboBox(this);
    seleziona_arrivo->setEditable(false);
    seleziona_arrivo->addItem("basic");
    seleziona_arrivo->addItem("business");
    seleziona_arrivo->addItem("executive");
    tipou->setBuddy(seleziona_arrivo);
    stato=new QTextEdit(this);
    stato->setText("Da qui puoi modificare la tipologia di un utente nel database");
    stato->setReadOnly(true);
    stato->setSizeAdjustPolicy(QTextEdit::AdjustToContents);
    // initialize buttons
    buttons = new QDialogButtonBox( this );
    buttons->addButton( QDialogButtonBox::Ok );
    buttons->addButton( QDialogButtonBox::Cancel );
    buttons->button( QDialogButtonBox::Ok )->setText( tr("Conferma") );
    buttons->button( QDialogButtonBox::Cancel )->setText( tr("Esci") );

    // connects
    connect( buttons->button( QDialogButtonBox::Cancel ),
             SIGNAL(clicked()),
             this,
             SLOT(close())
             );

    connect( buttons->button( QDialogButtonBox::Ok ),
             SIGNAL(clicked()),
             this,
             SLOT(confirm()));

    // piazzo i componenti
    formGridLayout->addWidget(labelutente,0,0);
    formGridLayout->addWidget( writeutente,0,1);
    formGridLayout->addWidget(tipou);
    formGridLayout->addWidget(seleziona_arrivo);
    formGridLayout->addWidget(stato,2,0);
    formGridLayout->addWidget( buttons,3,0);
    setLayout( formGridLayout );
}

void ChangeSubType::inizializza(LinQedInAdmin* admin){administrator=admin;}

void ChangeSubType::confirm()
{
    if (!administrator->db->findbool(writeutente->text()))
        stato->setText("<font color='red'>Errore, utente non presente nel database</font>");
    else if (seleziona_arrivo->currentText()==administrator->db->find(Username(writeutente->text()))->second->get_tipologia_utente())
    {
        stato->setText("<font color='grey'>Errore, l'utente è già di questa tipologia</font>");
    }
    else
    {
        administrator->changeSubscriptionType(Username(writeutente->text()),seleziona_arrivo->currentText());
        administrator->save();
        close();
        QMessageBox msgBox;
        msgBox.setText("Operazione completata con successo.");
        msgBox.exec();
        stato->setText("Da qui puoi modificare la tipologia di un utente nel database");
    }
}
