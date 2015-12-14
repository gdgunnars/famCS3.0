#-------------------------------------------------
#
# Project created by QtCreator 2015-12-10T14:51:00
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    computer.cpp \
    cscientist.cpp \
    database.cpp \
    Domain/computerdomain.cpp \
    Domain/persondomain.cpp \
    Storage/computerstorage.cpp \
    Storage/personstorage.cpp \
    trash.cpp \
    edit.cpp \
    editcomputer.cpp\
    info.cpp

HEADERS  += mainwindow.h \
    computer.h \
    connection.h \
    cscientist.h \
    database.h \
    Domain/computerdomain.h \
    Domain/persondomain.h \
    Storage/computerstorage.h \
    Storage/personstorage.h \
    trash.h \
    edit.h \
    editcomputer.h\
    info.h

FORMS    += mainwindow.ui \
    trash.ui \
    edit.ui \
    editcomputer.ui\
    info.ui

RESOURCES += \
    resources.qrc
