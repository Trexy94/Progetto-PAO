#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <LinquedinClient.h>
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
#include<finestra_modifica_profilo.h>
#include<QSharedPointer>
#include<ricerca.h>
using std::string;

// MyWidget.h
class MyWidget : public QWidget {
Q_OBJECT
public:
MyWidget(QString&);
public slots:
void insertContatto();
void removeContatto();
void mostraProfilo();
void modificaprofilo();
void cercautente();
void mostraDB();
void ricercaDB();
private:
// campo dati logico
QSharedPointer<LinQedInClient> utente;
QSharedPointer<Profilo> p;
QSharedPointer<Ricerca> R;
// inizializzazione logica
void logicInitialize(QString&);

// Componenti grafiche di MyWidget
QGroupBox* VerticalGroupBox;
QGroupBox* gridGroupBox;
QTextEdit* smallEditor;
QTextEdit* bigEditor;
static const int bottoni=7;
QLabel* label;
QLineEdit* lineEdit;
QPushButton* buttons[bottoni];

// metodi privati di set-up di MyWidget
void createVerticalGroupBox();
void createGridGroupBox();
void  closeEvent(QCloseEvent*);
};

#endif // MAINWINDOW_H
