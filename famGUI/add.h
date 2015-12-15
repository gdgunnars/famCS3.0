#ifndef ADD_H
#define ADD_H

#include <QDialog>
#include <ctime>
#include "Domain/computerdomain.h"
#include "Domain/persondomain.h"

namespace Ui {
class add;
}

class add : public QDialog
{
    Q_OBJECT

public:
    explicit add(QWidget *parent = 0);
    void fillComList();
    ~add();

private slots:
    void on_pushButtonAddPerson_clicked();  //Run errorcheck if there are none new scientist is added

private:
    Ui::add *ui;
    vector<Computer> allComp;
    personDomain personD;
    computerDomain computerD;

    //Check for errors
    void clearError(); //Clears all former errors
    bool checkForErrors(); //Main controller to start all error check
    bool nameError(); //Is true if name contains number
    bool yearError(); //Main controller for error check in year
    bool checkYear(QString year); //Is true if year contains letter
    int currentYear(); //Gives current year
    bool maxYear(int yearB, int yearD); //Is true if input year is greater then current year
    bool yearComparison(int yearB, int yearD); //Gives error if year is invalid in compareson to each other

};

#endif // ADD_H
