#include<ricerca.h>
#include<LinquedinClient.h>

int translate(QString campo);

Ricerca::Ricerca(LinQedInClient* utente)
{
    inizializza(utente);
    setUpGUI();
    setWindowTitle( tr("Ricerca") );
}


void Ricerca::setUpGUI(){
    // set up layout
    QGridLayout* formGridLayout = new QGridLayout( this );
    seleziona_parametro= new QComboBox( this );
    seleziona_parametro->setEditable(false);

    seleziona_parametro->addItem("Nome");
    seleziona_parametro->addItem("Cognome");
    seleziona_parametro->addItem("Data di nascita");
    seleziona_parametro->addItem("Città");
    seleziona_parametro->addItem("Lavoro");
    seleziona_parametro->addItem("Lingue parlate");
    seleziona_parametro->addItem("Telefono");
    seleziona_parametro->addItem("E-mail");

    // initialize labels
    labelparametro = new QLabel( this );
    labelparametro->setText( tr( "seleziona il campo in cui cercare" ) );
    labelparametro->setBuddy( seleziona_parametro );
    write=new QLabel(this);
    write->setText(tr("scrivi qui sotto il testo che vuoi cercare nel campo"));
    stringa=new QLineEdit(this);
    write->setBuddy(stringa);
    stato=new QTextEdit(this);
    stato->setText("Da qui puoi cercare le corrispondenze dei campi nel database, la ricerca è case unsensitive");
    stato->setReadOnly(true);
    stato->setSizeAdjustPolicy(QTextEdit::AdjustToContents);
    // initialize buttons
    buttons = new QDialogButtonBox( this );
    buttons->addButton( QDialogButtonBox::Ok);
    buttons->addButton( QDialogButtonBox::Cancel );
    buttons->button( QDialogButtonBox::Ok )->setText( tr("Cerca") );
    buttons->button( QDialogButtonBox::Cancel )->setText( tr("Esci") );

    // connects
    connect(stringa, SIGNAL(returnPressed()),this,SLOT(search()));
    connect( buttons->button( QDialogButtonBox::Cancel ),
             SIGNAL(clicked()),
             this,
             SLOT(close())
             );

    connect( buttons->button( QDialogButtonBox::Ok ),
             SIGNAL(clicked()),
             this,
             SLOT(search()));

    // piazzamento componenti
    formGridLayout->addWidget(labelparametro,0,0);
    formGridLayout->addWidget(seleziona_parametro,1,0);
    formGridLayout->addWidget(write,0,1,Qt::AlignCenter);
    formGridLayout->addWidget(stringa,1,1);
    formGridLayout->addWidget( buttons,2,1);
    formGridLayout->addWidget(stato,3,0,25,2);
    setLayout( formGridLayout );
}

void Ricerca::inizializza(LinQedInClient* utente){client=utente;}

void Ricerca::search()
{
 if ((stringa->text()=="") || (stringa->text()==" ")) stato->setText("<font color='red'>scrivi qualcosa!</font>");
 else
stato->setText("Ecco il risultato: \n\n"+client->search(translate(seleziona_parametro->currentText()),stringa->text()));
}
