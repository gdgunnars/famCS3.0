#include "mainwindow.h"
#include "database.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    database db;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
