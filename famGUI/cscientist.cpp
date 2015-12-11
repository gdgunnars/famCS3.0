#include "cscientist.h"

cScientist::cScientist(){

}
cScientist::cScientist(const int& i, const string& nam,const char& se,const int& yearB,const int& yearD,const string& fact){
    id = i;
    name = nam;
    sex = se;
    yearOfBirth = yearB;
    yearOfDeath = yearD;
    funFact = fact;
}

int cScientist::getId()const{
    return id;
}

string cScientist::getName()const{
    return name;
}
char cScientist::getSex()const{
    return sex;
}

unsigned int cScientist::getYearBirth()const{
    return yearOfBirth;
}

unsigned int cScientist::getYearDeath()const{
    return yearOfDeath;
}

string cScientist::getFact()const{
    return funFact;
}

/*void cScientist::setName(const string& newName){
    name = newName;
}

void cScientist::setSex(const char& newSex){
    sex = newSex;
}

void cScientist::setYearBirth(const int& newyear){
    yearOfBirth = newyear;
}

void cScientist::setYearDeath(const int& newyear){
    yearOfDeath = newyear;
}

void cScientist::setFact(const string& newString){
    funFact = newString;
}*/
