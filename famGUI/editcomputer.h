#ifndef EDITCOMPUTER_H
#define EDITCOMPUTER_H

#include <QDialog>
#include<cscientist.h>
#include<computer.h>
#include<Domain/computerdomain.h>
#include<ctime>

namespace Ui {
class editComputer;
}

class editComputer : public QDialog
{
    Q_OBJECT

public:
    explicit editComputer(const int& id, QWidget *parent = 0);
    ~editComputer();

private slots:
    void on_updateButton_clicked(); //Run errorcheck if there are none changes are executed

    void on_listConnected_clicked(); //If choosen is from list connected delete buttom is enabled

    void on_listNotConnected_clicked(); //If choosen is from list not connected add buttom is enabled

    void on_deleteButton_clicked(); //Deletes connection

    void on_addButton_clicked(); //Adds connection

private:
    Ui::editComputer *ui;
    //Editing start
    void getObject(); //Sets current computer
    void showInfo(); //Initiates showing current values and connections

    //Fill placeholders
    void showCurrentValues(); //Shows current values for computer
    void showYearBuilt(); //Shows current building year, if not built string appeares
    void showIfBuilt(); //Shows if it was built or not

    //Check for errors
    void clearError(); //Clears errors messages
    bool checkForErrors(); //Main controller for errorcheck
    bool yearError(); //Main controller for errorcheck for year
    bool checkYear(const QString& year); //Is ture if year contains letter
    bool maxYear(int yearB); //Is true if year if higher then current year
    int currentYear(); //Gives current year
    bool typeError(); //Is true if type cointains number

    //Make changes
    void executeChanges(); //Main controller for commiting changes
    void changeName(); //If new name is input then it's saved
    void changeBuildYear(); //If new building year is input then it's saved
    void changeType(); //If new type is input then it's saved
    void changeBuilt(); //If built/not built is changed then it's saved

    //List connections:
    void connections(); //Shows current connections and current connections that you can add

    //Quit:
    void quit(); //Quits application

    computerDomain computerD;
    Computer currentComputer;
    vector<cScientist> con;
    vector<cScientist> notCon;

    int currentId;
    bool built;
};

#endif // EDITCOMPUTER_H
