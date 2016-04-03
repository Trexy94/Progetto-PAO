#include<LinQuedinAdmin.h>
#include<mainwindow.h>
#include<admin.h>
#include<cambiapassword.h>
#include<changesubtype.h>

AdminGUI::AdminGUI() {
setWindowTitle("ADMIN");
createVerticalGroupBox();
createGridGroupBox();
bigEditor = new QTextEdit();
bigEditor->setReadOnly(true);

// Layout principale della dialog
QHBoxLayout* mainLayout = new QHBoxLayout(this);
// crea menu
QMenuBar* menuBar = new QMenuBar(this);
QMenu* fileMenu = menuBar->addMenu(tr("File"));
QAction* exitAction = fileMenu->addAction(tr("Close LinQedIn"));
QMenu* viewMenu = menuBar->addMenu(tr("&View"));
QAction* fullScreenAction = viewMenu->addAction(tr("Full screen"));
QAction* normalViewAction = viewMenu->addAction(tr("Small view"));

// connessione signal-slot
connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));
connect(fullScreenAction, SIGNAL(triggered()), this, SLOT(showFullScreen()));
connect(normalViewAction, SIGNAL(triggered()), this, SLOT(showNormal()));


mainLayout->setMenuBar(menuBar);
mainLayout->addWidget(VerticalGroupBox);
mainLayout->addWidget(gridGroupBox);
mainLayout->addWidget(bigEditor);
setLayout(mainLayout);
logicInitialize();
}
void AdminGUI::createGridGroupBox() {
gridGroupBox = new QGroupBox(this);
QGridLayout* layout = new QGridLayout(this);

label=new QLabel(tr("* scrivi qui"));
lineEdit=new QLineEdit(this);
label->setBuddy(lineEdit);
layout->addWidget(label,0,0,1,1);
layout->addWidget(lineEdit,1,0,1,1);

smallEditor = new QTextEdit(this);
smallEditor->setReadOnly(true);
QFont font = smallEditor->font();
font.setPointSize(font.pointSize() + 3);
smallEditor->setFont(font);


layout->addWidget(smallEditor,2,0,1,1);

gridGroupBox->setLayout(layout);
}
void AdminGUI::logicInitialize()
{
admin = QSharedPointer<LinQedInAdmin>(new LinQedInAdmin());
}

// slot
void AdminGUI::insertUtente()
{
    if(!insert_U)
    insert_U=QSharedPointer<NewUtente>(new NewUtente(admin.data()));
    insert_U->show();
    insert_U->activateWindow();
}

// slot
void AdminGUI::removeUtente()
{
    smallEditor->setText(admin->remove(Username(lineEdit->text())));
    admin->save();
}

// slot
void AdminGUI::ShowXml()
{
    bigEditor->setText(admin->mostradb());
}

//slot
void AdminGUI::change_subtype()
{
    if(!cambia)
    cambia=QSharedPointer<ChangeSubType>(new ChangeSubType(admin.data()));
    cambia->show();
    cambia->activateWindow();
}

//slot
void AdminGUI::cercautente()
{
    smallEditor->setText(admin->find(lineEdit->text()));
}

// slot
void AdminGUI::cambiapassword()
{
    if(!cp)
    cp=QSharedPointer<ChangePassword>(new ChangePassword(this));
    cp->show();
    cp->activateWindow();
}

void AdminGUI::createVerticalGroupBox() {
VerticalGroupBox = new QGroupBox(this);
QVBoxLayout* layout = new QVBoxLayout(this);

buttons[0] = new QPushButton("Inserisci utente nel DB");
buttons[0]->setParent(this);
layout->addWidget(buttons[0]);
connect(buttons[0], SIGNAL(clicked()), this, SLOT(insertUtente()));

buttons[1] = new QPushButton("Rimuovi contatto dal DB *");
buttons[1]->setParent(this);
layout->addWidget(buttons[1]);
connect(buttons[1], SIGNAL(clicked()),this, SLOT(removeUtente()));

buttons[2] = new QPushButton("Mostra l'XML del database");
buttons[2]->setParent(this);
layout->addWidget(buttons[2]);
connect(buttons[2], SIGNAL(clicked()),this, SLOT( ShowXml()));

buttons[3] = new QPushButton("Cerca un utente *");
buttons[3]->setParent(this);
layout->addWidget(buttons[3]);
connect(buttons[3], SIGNAL(clicked()),this, SLOT( cercautente()));

buttons[4] = new QPushButton("Cambia tipologia di iscrizione");
buttons[4]->setParent(this);
layout->addWidget(buttons[4]);
connect(buttons[4], SIGNAL(clicked()),this, SLOT( change_subtype()));

buttons[5] = new QPushButton("Cambia la password di amministratore");
buttons[5]->setParent(this);
layout->addWidget(buttons[5]);
connect(buttons[5], SIGNAL(clicked()),this, SLOT(cambiapassword()));


VerticalGroupBox->setLayout(layout);
}

void   AdminGUI::closeEvent(QCloseEvent*)
{
    qApp->quit();
}
