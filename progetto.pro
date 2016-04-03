#-------------------------------------------------
#
# Project created by QtCreator 2014-12-29T15:59:32
#
#-------------------------------------------------

QT       += widgets
TARGET = progetto
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    io.cpp \
    login.cpp \
    admin.cpp \
    metodi_utenti.cpp \
    finestra_modifica_profilo.cpp \
    newutente.cpp \
    cambiapassword.cpp \
    changesubtype.cpp \
    DB.cpp \
    Info.cpp \
    rete.cpp \
    linquedinclient.cpp \
    linquedinadmin.cpp \
    ricerca.cpp

HEADERS  += \
    mainwindow.h \
    login.h \
    admin.h \
    finestra_modifica_profilo.h \
    newutente.h \
    cambiapassword.h \
    changesubtype.h \
    Info.h \
    utente.h \
    DB.h \
    Rete.h \
    tipi_di_utenti.h \
    LinQuedinAdmin.h \
    LinquedinClient.h \
    ricerca.h

FORMS    +=

RESOURCES += \
    progetto.qrc
