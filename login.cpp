#include<login.h>
#include<mainwindow.h>
#include<admin.h>
#include<qfile.h>
#include<LinQuedinAdmin.h>
#include<LinquedinClient.h>
bool Adminlogged(QString);
LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent)
{
    database=0;
    setUpGUI();
    setWindowTitle( tr("User Login") );
    setModal( true );
}

void LoginDialog::setUpGUI(){
    // set up the layout
    QGridLayout* formGridLayout = new QGridLayout(this);
    mostrastato=new QTextEdit(this);
    mostrastato->setParent(this);
    mostrastato->setReadOnly(true);
    mostrastato->setSizeAdjustPolicy(QTextEdit::AdjustToContents);
    comboUsername = new QComboBox( this );
    comboUsername->setParent(this);
    comboUsername->addItem("Normal Users");
    comboUsername->addItem("Admin");
    comboUsername->setEditable( false );
    editPassword = new QLineEdit( this );
    editPassword->setParent(this);
    // initialize labels
    labelUsername = new QLabel(this);
    labelPassword = new QLabel( this );
    mostrastato->setText(tr("seleziona la tipologia di accesso e inserisci il tuo username/password\nattenzione, è case sensitive"));
    labelUsername->setText( tr( "Tipologia accesso" ) );
    labelUsername->setBuddy( comboUsername );
    labelPassword->setText( tr( "Username o Password" ) );
    labelPassword->setBuddy( editPassword );



    // initialize buttons
    buttons = new QDialogButtonBox( this );
    buttons->setParent(this);
    buttons->addButton( QDialogButtonBox::Ok );
    buttons->addButton( QDialogButtonBox::Cancel );
    buttons->button( QDialogButtonBox::Ok )->setText( tr("Login") );
    buttons->button( QDialogButtonBox::Cancel )->setText( tr("Quit") );

    // connects
    connect( buttons->button( QDialogButtonBox::Cancel ),
             SIGNAL(clicked()),
             this,
             SLOT(close())
             );

    connect( buttons->button( QDialogButtonBox::Ok ),
             SIGNAL(clicked()),
             this,
             SLOT(slotAcceptLogin()) );

    // metto i componenti
    formGridLayout->addWidget(mostrastato,0,0,1,2);
    formGridLayout->addWidget( labelUsername, 1, 0 );
    formGridLayout->addWidget( comboUsername, 1, 1 );
    formGridLayout->addWidget( labelPassword, 2, 0 );
    formGridLayout->addWidget( editPassword, 2, 1 );
    formGridLayout->addWidget( buttons, 3, 0, 1, 2 );
    setLayout( formGridLayout );


}

void LoginDialog::slotAcceptLogin(){
    QString username = comboUsername->currentText();
    QString password = editPassword->text();
    if (username=="Admin")
    {
        if(Adminlogged(password))
        {
            admin=QSharedPointer<AdminGUI>(new AdminGUI());
            if (database) delete database;
            admin->showMaximized();
            close();
        }
        else
        {
            mostrastato->setText(tr("<font color='red'>password non corretta</font>"));
            editPassword->setFocus();
        }
    }
    else
        if (username=="Normal Users")
        {
            if(!database)
            {
                database=new DB();//la delete viene fatta, quindi non devo preoccuparmene nel distruttore dell'interfaccia
                database->load();
            }
            if(database->findbool(password))
            {
                delete database;
                w=QSharedPointer<MyWidget>(new MyWidget(password));
                w->showMaximized();
                close();
            }
            else
            {
                mostrastato->setText(tr("<font color='red'>username non presente nel database</font>"));
                editPassword->setFocus();
            }
        }
}
