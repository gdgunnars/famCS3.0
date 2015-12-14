#ifndef PERSONDOMAIN_H
#define PERSONDOMAIN_H
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <QString>
#include <QtSql>
#include <QSqlQuery>
#include "../cscientist.h"
#include "../computer.h"
#include "../Storage/personstorage.h"
//#include "../connection.h"

using namespace std;

class personDomain
{
public:
    personDomain();//Constructor

    //Get function
    cScientist getPerson(const int& id);

    //Show list:
    vector<cScientist> sortByName(const bool& desc);//Sorts alphabetically
    vector<cScientist> sortBySex(const bool& desc);//Sorts by sex
    vector<cScientist> sortByYear(const bool& desc, const bool& bord);//Sorts by year of birth/death

    //Search list:
    vector<cScientist> searchByName(string input);//Searches by name

    //Change list:
    int addPerson(const string& nam, const char& se, const int& yearB, const int& yearD, const string& fact);//Adds person
    void editPerson(const int& id, const QString& value,const int& col);//EditPerson(id,newinfo,column number)
    void deletePerson(const int& id);//Deletes person with given id

    //Connections:
        //List connections:
    vector<Computer> compsConnectedToPerson(const int &id);//Lists persons connected to computer
    vector<Computer> compsNotConnectedToPerson(const int &id);
        //Edit connections:
    void addConnection(const int& persontId, const int& computerId);//Add a connection
    void deleteConnection(const int& personId, const int& computerId);//Delete a connection

    //Recycle bin:
    vector<cScientist> listErased();//Lists persons with that have been erased
    void restoreFromBin(const int& id);//Restores person with given id

    //Quit fall:
    void quit();

private:
    //Instance af storage layer
    personStorage data;
};

#endif // PERSONDOMAIN_H
