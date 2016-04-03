#ifndef CHANGESUBTYPE_H
#define CHANGESUBTYPE_H
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QLineEdit>
#include <QComboBox>
#include <QGridLayout>
#include <QStringList>
#include <QDebug>
#include<LinQuedinAdmin.h>
#include<qtextedit.h>

class ChangeSubType : public QWidget
{
    Q_OBJECT
private:
    QLabel* labelutente;
    QLineEdit* writeutente;
    QLabel* tipou;
    QComboBox* seleziona_arrivo;
    QDialogButtonBox* buttons;
    QTextEdit* stato;
    void setUpGUI();
    void inizializza(LinQedInAdmin* );
    LinQedInAdmin* administrator;
public:
    ChangeSubType(LinQedInAdmin*);
public slots:
    void confirm();

};
#endif // CHANGESUBTYPE_H
