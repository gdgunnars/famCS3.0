#ifndef EDIT_H
#define EDIT_H

#include<QDialog>
#include<cscientist.h>
#include<computer.h>
#include<ctime>
#include<Domain/persondomain.h>

namespace Ui {
class edit;
}

class edit : public QDialog
{
    Q_OBJECT

public:
    explicit edit(const int& id,QWidget *parent = 0);
    ~edit();

private slots:
    void on_updateButton_clicked();

    void on_listConnected_clicked();

    void on_listNotConnected_clicked();

    void on_deleteButton_clicked();

    void on_addButton_clicked();

private:
    Ui::edit *ui;
    //Editing start
    void getObject(); //Gets currentPerson
    void showInfo(); //Starts show current values and connenctions

    //Fill placeholders
    void showCurrentValues(); //Shows current values for scientist
    void showGender(); //Marks right buttom for gender
    void showYod(); //Marks alive buttom if person is currently alive

    //Check for errors
    void clearError(); //Clears all former errors
    bool checkForErrors(); //Main controller to start all error check
    bool nameError(); //Is true if name contains number
    bool yearError(); //Main controller for error check in year
    bool checkYear(QString year); //Is true if year contains letter
    int currentYear(); //Gives current year
    bool maxYear(int yearB, int yearD); //Is true if input year is greater then current year
    bool yearComparison(int yearB, int yearD); //Gives error if year is invalid in compareson to each other

    //Make changes
    void executeChanges(); //Main controller for commiting changes
    void changeName(); //If new name is input it's saved
    void changeGender(); //If gender has been changed then it's saved
    void changeYob(); //If year of birth has been changed then it's saved
    void changeYod(); //If year of death has been changed then it's saved
    void changeFact(); //If fact has been changed then it's saved

    //List connections:
    void connections(); //Shows current connections and current connections that you can add

    //Quit:
    void quit();

    personDomain personD;
    cScientist currentPerson;
    vector<Computer> con;
    vector<Computer> notCon;

    int currentId;
    bool male;
};

#endif // EDIT_H
