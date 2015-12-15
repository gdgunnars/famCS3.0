#ifndef CSCIENTIST_H
#define CSCIENTIST_H
#include<string>
#include<iostream>

using namespace std;

class cScientist
{
public:

    //Constructors:
    cScientist();
    cScientist(const int& i, const string& nam,const char& se,const int& yearB,const int& yearD,const string& fact);

    //Get functions:
    int getId()const; //Returns id
    string getName()const; //Returns name
    char getSex()const; //Returns gender
    unsigned int getYearBirth()const; //Returns year of birth
    unsigned int getYearDeath()const; //Returns year of death
    string getFact()const; //Returns fact

private:
    int id;
    string name;
    char sex;
    int yearOfBirth;
    int yearOfDeath;
    string funFact;

};

#endif // CSCIENTIST_H
