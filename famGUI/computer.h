#ifndef COMPUTER_H
#define COMPUTER_H
#include<string>
#include<iostream>

using namespace std;


class Computer
{
public:
    //Constructors
    Computer();
    Computer(const int& i, const string& nam,const int& buildY, const string& typ, const bool& bu);

    //Get functions
    int getId()const;//Returns id
    string getName()const;//Returns name
    int getYear()const;//Returns year
    string getType()const;//Returns type
    bool getBuilt()const;//Returns if computer was built or not

private:
    int id;
    string name;
    int buildYear;
    string type;
    bool built;
};

#endif // COMPUTER_H
