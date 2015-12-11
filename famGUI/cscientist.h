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
    int getId()const;
    string getName()const;
    char getSex()const;
    unsigned int getYearBirth()const;
    unsigned int getYearDeath()const;
    string getFact()const;

private:
    int id;
    string name;
    char sex;
    int yearOfBirth;
    int yearOfDeath;
    string funFact;

};

#endif // CSCIENTIST_H
