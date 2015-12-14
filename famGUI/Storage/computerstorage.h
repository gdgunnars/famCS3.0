#ifndef COMPUTERSTORAGE_H
#define COMPUTERSTORAGE_H

#include <QCoreApplication>
#include <QStringList>
#include <QtSql>
#include <QSqlQuery>
#include <iostream>
#include <vector>
#include "../cscientist.h"
#include "../computer.h"

class computerStorage{

public:
    computerStorage();

    //Queries:
    vector<Computer>execute(QSqlQuery query);//Executes query and returns vector of computers
    Computer getComputer(const int& id);//Returns computer with given id

    //Show list:
    vector<Computer> sortByName(const bool& desc);//Sorts by name
    vector<Computer> sortByYear(const bool& desc);//Sorts by year
    vector<Computer> sortByType(const bool& desc);//Sorts by type
    vector<Computer> sortByBuild(const bool& desc);//Sorts by build

    //Search list:
    vector<Computer> searchByName(string input);//Searches by name

    //Change list:
    int addComputer(const string& nam, const int& yea, const string& typ, const bool& buil);//Adds computer
    void editComputer(const int& id, const QString& value,const int& col);//Edits computer
    void deleteComputer(const int& id);//Deletes computer

    //Connections:
        //List connections:
    vector<cScientist> persConnectedToComp(const int& id);//Lists persons connected to given computer
    vector<cScientist> persNotConnectedToComp(const int& id);
        //Edit connections:
    void addConnection(const int& computerId, const int& personId);//Adds connection
    void deleteConnection(const int& computerId, const int& personId);//Delete connection

    //Recycle bin:
    vector<Computer> listErased();//Lists erased computers
    void restoreFromBin(const int& id);//restores erased person
private:
    QSqlDatabase runningDB;
};

#endif // COMPUTERSTORAGE_H
