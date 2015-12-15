#include "computer.h"

Computer::Computer(){

}

Computer::Computer(const int& i, const string& nam,const int& buildY, const string& typ, const bool& bu){

    id = i;
    name = nam;
    buildYear = buildY;
    type = typ;
    built = bu;
}

int Computer::getId()const{

    return id;
}

string Computer::getName()const{

    return name;
}

int Computer::getYear()const{

    return buildYear;
}

string Computer::getType()const{

    return type;
}

bool Computer::getBuilt()const{

    return built;
}

