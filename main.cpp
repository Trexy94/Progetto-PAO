// main.cpp
#include <QApplication>
#include<login.h>
#include<qsharedpointer.h>
#include <QIcon>

int main(int argc, char* argv[]) {
QApplication app(argc,argv);
app.setWindowIcon(QIcon(":/logo/linquedin.png"));
QSharedPointer<LoginDialog> logindialog=QSharedPointer<LoginDialog>(new LoginDialog());
logindialog->show();
return app.exec();
}
