#ifndef DATABASE_H
#define DATABASE_H
#include <QCoreApplication>
#include <QtSql>
#include <QSqlQuery>

class database
{
public:
    database();
    void close();

private:
    QSqlDatabase db;
};

#endif // DATABASE_H
