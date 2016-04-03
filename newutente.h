#ifndef NEWUTENTE_H
#define NEWUTENTE_H
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
#include<qcombobox.h>

class NewUtente : public QWidget {
Q_OBJECT
public:
NewUtente(LinQedInAdmin*);
public slots:
void conferma();
private:
// campo dati logico
LinQedInAdmin* administrator;
// inizializzazione logica
void inizializza(LinQedInAdmin*);
void inizializza_campi();
// Componenti grafiche di MyWidget
static const int campi=10;
QLabel* label[campi];
QLineEdit* lineEdit[campi];
QPushButton* button[2];
QComboBox* tipou;
QTextEdit* barra_stato;
};
#endif // NEWUTENTE_H
