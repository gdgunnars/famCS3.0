#include "computerdomain.h"

computerDomain::computerDomain()
{

}
Computer computerDomain::getComputer(const int& id){
    Computer comp = data.getComputer(id);
    return comp;
}

//Show list:
vector<Computer> computerDomain::sortByName(const bool& desc){
    vector<Computer> list = data.sortByName(desc);
    return list;
}
vector<Computer> computerDomain::sortByYear(const bool& desc){
    vector<Computer> list = data.sortByYear(desc);
    return list;
}

vector<Computer> computerDomain::sortByType(const bool& desc){
    vector<Computer> list = data.sortByType(desc);
    return list;
}

vector<Computer> computerDomain::sortByBuild(const bool& desc){
    vector<Computer> list = data.sortByBuild(desc);
    return list;
}
//Search list:
vector<Computer> computerDomain::searchByName(string input){
    vector<Computer> list = data.searchByName(input);
    return list;
}

//Change list:
int computerDomain::addComputer(const string& nam, const int& yea, const string& typ, const bool& buil){
    int id = data.addComputer(nam,yea,typ,buil);
    return id;
}

void computerDomain::editComputer(const int& id, const QString& value,const int& col){
    data.editComputer(id,value,col);
}

void computerDomain::deleteComputer(const int& id){
    data.deleteComputer(id);
}

//Connections:
    //List connections:
vector<cScientist> computerDomain::persConnectedToComp(const int &id){
    vector<cScientist> list = data.persConnectedToComp(id);
    return list;
}
    //Edit connections:
void computerDomain::addConnection(const int& computerId, const int& personId){
    data.addConnection(computerId,personId);
}

void computerDomain::deleteConnection(const int& computerId, const int& personId){
    data.deleteConnection(computerId,personId);
}
vector<Computer> computerDomain::listErased(){
    vector<Computer> list = data.listErased();
    return list;
}
void computerDomain::restoreFromBin(const int& id){
    data.restoreFromBin(id);
}
