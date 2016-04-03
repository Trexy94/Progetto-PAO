#ifndef RICERCA_H
#define RICERCA_H
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QLineEdit>
#include <QComboBox>
#include <QGridLayout>
#include <QStringList>
#include <QDebug>
#include<LinquedinClient.h>
#include<qtextedit.h>

class Ricerca : public QWidget
{
    Q_OBJECT
private:
    QLabel* labelparametro;
    QComboBox* seleziona_parametro;
    QLabel* write;
    QLineEdit* stringa;
    QDialogButtonBox* buttons;
    QTextEdit* stato;
    void setUpGUI();
    void inizializza(LinQedInClient*);
    LinQedInClient* client;
public:
    Ricerca(LinQedInClient*);
public slots:
    void search();

};
#endif // RICERCA_H
