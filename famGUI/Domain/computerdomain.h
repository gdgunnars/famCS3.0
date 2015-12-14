#ifndef COMPUTERDOMAIN_H
#define COMPUTERDOMAIN_H
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <QString>
#include "../computer.h"
#include "../cscientist.h"
#include "../Storage/computerstorage.h"
//#include "../connection.h"

class computerDomain
{
public:
    computerDomain();

    //Get function:
    Computer getComputer(const int& id);//Returns an instance of computer with given id

    //Show list:
    vector<Computer> sortByName(const bool& desc);//Sorts by name
    vector<Computer> sortByYear(const bool& desc);//Sorts by year
    vector<Computer> sortByType(const bool& desc);//Sorts by type
    vector<Computer> sortByBuild(const bool& desc);//Sorts by build

    //Search list:
    vector<Computer> searchByName(string input);//Searches by name

    //Change list:
    int addComputer(const string& nam, const int& yea, const string& typ, const bool& buil);//Adds computer
    void editComputer(const int& id, const QString& value,const int& col);//Edits computer (id,newInfo,column number)
    void deleteComputer(const int& id);//Deletes computer

    //Connections:
        //List connections:
    vector<cScientist> persConnectedToComp(const int &id);//Lists persons connected to given computer
    vector<cScientist> persNotConnectedToComp(const int &id);
        //Edit connections:
    void addConnection(const int& computerId, const int& personId);//Adds new connection
    void deleteConnection(const int& computerId, const int& personId);//Deletes connection

    //Recycle bin:
    vector<Computer> listErased();//Lists computers that have been erased
    void restoreFromBin(const int& id);//Restores computer with given id

    //Quit fall:
    void quit();//Quit
private:
    computerStorage data;
};

#endif // COMPUTERDOMAIN_H
