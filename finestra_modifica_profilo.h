#ifndef FINESTRA_MODIFICA_PROFILO_H
#define FINESTRA_MODIFICA_PROFILO_H
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

class Profilo : public QWidget {
Q_OBJECT
public:
Profilo(Info*,DB*);
void inizializza_contenuto();
public slots:
void conferma();
private:
// campo dati logico
Info* profilo;
DB*db;
// inizializzazione logica
void inizializza(Info*,DB*);
void inizializza_label();
// Componenti grafiche di MyWidget
static const int campi=8;
QLabel* label[campi];
QLineEdit* lineEdit[campi];
QPushButton* button[2];
};

#endif // FINESTRA_MODIFICA_PROFILO_H
