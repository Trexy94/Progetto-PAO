#ifndef ADMIN_H
#define ADMIN_H
#include <LinQuedinAdmin.h>
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
#include<newutente.h>
#include<changesubtype.h>
#include<QSharedPointer>
#include<cambiapassword.h>
using std::string;

class AdminGUI : public QWidget {
Q_OBJECT
public:
AdminGUI();
public slots:
void insertUtente();
void removeUtente();
void ShowXml();
void cercautente();
void change_subtype();
void cambiapassword();
private:
// campi dati logici
QSharedPointer<LinQedInAdmin> admin;
QSharedPointer<NewUtente> insert_U;
QSharedPointer<ChangeSubType> cambia;
QSharedPointer<ChangePassword> cp;
// inizializzazione logica
void logicInitialize();

// Componenti grafiche di AdminGUI
QGroupBox* VerticalGroupBox;
QGroupBox* gridGroupBox;
QTextEdit* smallEditor;
QTextEdit* bigEditor;
QLabel* label;
QLineEdit* lineEdit;
QPushButton* buttons[6];

// metodi privati di set-up di AdminGUI
void createVerticalGroupBox();
void createGridGroupBox();
void  closeEvent(QCloseEvent*);
};

#endif // ADMIN_H
