#ifndef CAMBIAPASSWORD_H
#define CAMBIAPASSWORD_H
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QLineEdit>
#include <QComboBox>
#include <QGridLayout>
#include <QStringList>
#include <QDebug>
#include<Info.h>
#include<qtextedit.h>


class ChangePassword : public QDialog
{
    Q_OBJECT
private:
    QLabel* labelNewPassword;
    QLineEdit* editPassword;
    QDialogButtonBox* buttons;
    void setUpGUI();

public:
    explicit ChangePassword(QWidget *parent = 0);
public slots:
    void PasswordWrite();

};
#endif // CAMBIAPASSWORD_H
