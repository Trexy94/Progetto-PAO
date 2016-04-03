#include<qfile.h>
#include<cambiapassword.h>
#include<qmessagebox.h>

void save_admin_password(QString&);

ChangePassword::ChangePassword(QWidget *parent) :
    QDialog(parent)
{
    setUpGUI();
    setWindowTitle( tr("Cambio password") );
    setModal( true );
}

void ChangePassword::setUpGUI(){
    // set up layout
    QGridLayout* formGridLayout = new QGridLayout( this );
    editPassword = new QLineEdit( this );
    editPassword->setParent(this);
    // initialize labels
    labelNewPassword = new QLabel( this );
    labelNewPassword->setText( tr( "nuova password:" ) );
    labelNewPassword->setBuddy( editPassword );
    // initialize buttons
    buttons = new QDialogButtonBox( this );
    buttons->addButton( QDialogButtonBox::Ok );
    buttons->addButton( QDialogButtonBox::Cancel );
    buttons->button( QDialogButtonBox::Ok )->setText( tr("Conferma cambio password") );
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
             SLOT(PasswordWrite()));

    // piazzamento widget
    formGridLayout->addWidget(labelNewPassword,0,0);
    formGridLayout->addWidget( editPassword,0,1,1,3);
    formGridLayout->addWidget( buttons,1, 2, 1, 2);
    setLayout( formGridLayout );


}

void ChangePassword::PasswordWrite()
{
    QString password = editPassword->text();
    if (password=="" || password == "non inserire una password vuota!")
    {
        editPassword->setText("non inserire una password vuota!");
        editPassword->setFocus();
        editPassword->selectAll();
    }
    else
    {
            save_admin_password(password);
            close();
            QMessageBox msgBox;
            msgBox.setText("Password modificata");
            msgBox.exec();
    }
}


