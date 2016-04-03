#include<LinquedinClient.h>
#include<mainwindow.h>
#include<finestra_modifica_profilo.h>

MyWidget::MyWidget(QString& user) {
setWindowTitle(user);
logicInitialize(user);
bigEditor = new QTextEdit(this);
bigEditor->setReadOnly(true);
createVerticalGroupBox();
createGridGroupBox();
// Layout principale della dialog
QHBoxLayout* mainLayout = new QHBoxLayout(this);
// crea menu
QMenuBar* menuBar = new QMenuBar(this);
menuBar->setParent(this);
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
}
void MyWidget::createGridGroupBox() {
gridGroupBox = new QGroupBox(this);
QGridLayout* layout = new QGridLayout(this);

label=new QLabel(tr("* scrivi qui"));
label->setParent(this);
lineEdit=new QLineEdit(this);
label->setBuddy(lineEdit);
layout->addWidget(label,0,0,1,1);
layout->addWidget(lineEdit,1,0,1,1);

smallEditor = new QTextEdit(this);
smallEditor->setParent(this);
smallEditor->setReadOnly(true);
QFont font = smallEditor->font();
font.setPointSize(font.pointSize() + 5);
smallEditor->setFont(font);


layout->addWidget(smallEditor,2,0,1,1);

gridGroupBox->setLayout(layout);
}
void MyWidget::logicInitialize(QString& user) {
utente = QSharedPointer<LinQedInClient>(new LinQedInClient(Username(user)));
}

// slot
void MyWidget::insertContatto() {
smallEditor->setText(utente->insertRete(Username(lineEdit->text())));
}

// slot
void MyWidget::removeContatto() {
smallEditor->setText(utente->removeRete(Username(lineEdit->text())));
}

// slot
void MyWidget::mostraProfilo() {
bigEditor->setText(utente->showProfilo());
}

//slot
void MyWidget::mostraDB()
{
  bigEditor->setText(utente->ricerca());
}

//slot
void MyWidget::modificaprofilo()
{
    if(!p)
    {
    p =QSharedPointer<Profilo>(new Profilo(utente->u->info,utente->db));    
    p->show();
    }
    else
    {
    p->inizializza_contenuto();
    p->show();
    p->activateWindow();
    }
}

//slot
void MyWidget::cercautente()
{
smallEditor->setText(utente->ricerca_per_username(lineEdit->text()));
}

//slot
void MyWidget::ricercaDB()
{
    if(!R)
        R=QSharedPointer<Ricerca>(new Ricerca(utente.data()));
        R->showMaximized();
        R->activateWindow();
}

void MyWidget::createVerticalGroupBox() {
VerticalGroupBox = new QGroupBox(this);
QVBoxLayout* layout = new QVBoxLayout(this);

buttons[0] = new QPushButton("Inserisci nuovo contatto nella rete *");
buttons[0]->setParent(this);
layout->addWidget(buttons[0]);
connect(buttons[0], SIGNAL(clicked()), this, SLOT(insertContatto()));

buttons[1] = new QPushButton("Rimuovi contatto dalla rete *");
buttons[1]->setParent(this);
layout->addWidget(buttons[1]);
connect(buttons[1], SIGNAL(clicked()),this, SLOT(removeContatto()));

buttons[2] = new QPushButton("Mostra il mio profilo");
buttons[2]->setParent(this);
layout->addWidget(buttons[2]);
connect(buttons[2], SIGNAL(clicked()),this, SLOT( mostraProfilo() ));

buttons[3] = new QPushButton("Modifica il mio profilo");
buttons[3]->setParent(this);
layout->addWidget(buttons[3]);
connect(buttons[3], SIGNAL(clicked()),this, SLOT( modificaprofilo()));

buttons[4] = new QPushButton("Cerca un utente *");
buttons[4]->setParent(this);
layout->addWidget(buttons[4]);
connect(buttons[4], SIGNAL(clicked()),this, SLOT( cercautente()));

buttons[5] = new QPushButton("Mostra il Database");
buttons[5]->setParent(this);
layout->addWidget(buttons[5]);
connect(buttons[5], SIGNAL(clicked()),this, SLOT( mostraDB()));

if (dynamic_cast<UtenteBasic*>(utente->u))
{
    bigEditor->setText("<font color='blue'>Non restare un utente base!\n passa ad una tipologia superiore per avere accesso alla ricerca filtrata per campo!</font>");
}
else
{
buttons[6] = new QPushButton("Ricerca in un campo");
buttons[6]->setParent(this);
layout->addWidget(buttons[6]);
connect(buttons[6], SIGNAL(clicked()),this, SLOT( ricercaDB()));
}
VerticalGroupBox->setLayout(layout);
}

void   MyWidget::closeEvent(QCloseEvent*)
{
    qApp->quit();
}
