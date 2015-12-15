#include "persondomain.h"

personDomain::personDomain(){
    //sjálfgefinn smiður tómur
}

 cScientist personDomain::getPerson(const int& id){

     cScientist person = data.getPerson(id);
     return person;
 }

//Show list:
vector<cScientist> personDomain::sortByName(const bool& desc){

    vector<cScientist> list = data.sortByName(desc);
    return list;
}

//Search list:
vector<cScientist> personDomain::searchByName(string input){

    vector<cScientist> list = data.searchByName(input);
    return list;
}

//Change list:
int personDomain::addPerson(const string& nam, const char& se, const int& yearB, const int& yearD, const string& fact){

    int id = data.addPerson(nam,se,yearB, yearD,fact);
    return id;
}

void personDomain::editPerson(const int& id, const QString& value,const int& col){

    data.editPerson(id,value,col);
}

void personDomain::deletePerson(const int& id){

    data.deletePerson(id);
}

//Connections:
    //List connections:
vector<Computer> personDomain::compsConnectedToPerson(const int &id){

    vector<Computer> list = data.compsConnectedToPerson(id);
    return list;
}
vector<Computer> personDomain::compsNotConnectedToPerson(const int &id){

    vector<Computer> list = data.compsNotConnectedToPerson(id);
    return list;
}

    //Edit connections:
void personDomain::addConnection(const int& personId, const int& computerId){

    data.addConnection(personId,computerId);
}

void personDomain::deleteConnection(const int& personId, const int& computerId){

    data.deleteConnection(personId,computerId);
}

vector<cScientist> personDomain::listErased(){

    vector<cScientist> list = data.listErased();
    return list;
}
void personDomain::restoreFromBin(const int& id){

    data.restoreFromBin(id);
}
//Quit:
void personDomain::quit(){

    data.quit();
}
