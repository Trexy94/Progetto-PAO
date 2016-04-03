#ifndef LOGIN_H
#define LOGIN_H
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
#include<mainwindow.h>
#include<admin.h>
#include<QSharedPointer>


class LoginDialog : public QDialog
{
    Q_OBJECT

private:
    QTextEdit* mostrastato;

    QLabel* labelUsername;

    QLabel* labelPassword;


    QComboBox* comboUsername;


    QLineEdit* editPassword;

    QDialogButtonBox* buttons;

    QSharedPointer<MyWidget> w;

    QSharedPointer<AdminGUI> admin;

    void setUpGUI();

    DB*database;

public:
    explicit LoginDialog(QWidget *parent = 0);




signals:


    void acceptLogin( QString& username);

public slots:

    void slotAcceptLogin();

};

#endif // LOGIN_H
