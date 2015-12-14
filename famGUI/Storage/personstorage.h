#ifndef PERSONSTORAGE_H
#define PERSONSTORAGE_H

#include <QCoreApplication>
#include <QStringList>
#include <QString>
#include <QChar>
#include <QtSql>
#include <QSqlQuery>
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "../computer.h"
#include "../cscientist.h"

class personStorage
{
    public:
      personStorage();
    //Queries:
    vector<cScientist> execute(QSqlQuery query);
    cScientist getPerson(const int& id);
    //Show list:
    vector<cScientist> sortByName(const bool& desc);//Sorts alphabetically
    vector<cScientist> sortBySex(const bool& desc);//Sorts by sex
    vector<cScientist> sortByYear(const bool& desc, const bool& bord);//Sorts by year of birth/death

    //Search list:
    vector<cScientist> searchByName(string input);//Searches by name

    //Change list:
    int addPerson(const string& nam, const char& se, const int& yearB, const int& yearD, const string& fact);//adds person
    void editPerson(const int& id, const QString& value,const int& col);//editPerson(id,newinfo,column number)
    void deletePerson(const int& id);//deletes person with given id

    //Connections:
        //List connections:
    vector<Computer> compsConnectedToPerson(const int &id);//Lists persons connected to computer
    vector<Computer> compsNotConnectedToPerson(const int &id);
        //Edit connections:
    void addConnection(const int& personId, const int& computerId);//Add a connection
    void deleteConnection(const int& personId, const int& computerId);//Delete a connection

    //Recycle bin:
    vector<cScientist> listErased();//Lists people that have been erased
    void restoreFromBin(const int& id);//Restores erased person

    //Quit fall:
    void quit();


    private:
        QSqlDatabase runningDB;
};

#endif // PERSONSTORAGE_H
