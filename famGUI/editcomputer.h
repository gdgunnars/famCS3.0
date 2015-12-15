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
    void on_updateButton_clicked();

    void on_listConnected_clicked();

    void on_listNotConnected_clicked();

    void on_deleteButton_clicked();

    void on_addButton_clicked();

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
    bool maxYear(int yearB);
    bool typeError();
    int currentYear();

    //Make changes
    void executeChanges();
    void changeName();
    void changeBuildYear();
    void changeType();
    void changeBuilt();

    //List connections:
    void connections();

    //Quit:
    void quit();

    computerDomain computerD;
    Computer currentComputer;
    vector<cScientist> con;
    vector<cScientist> notCon;

    int currentId;
    bool built;
};

#endif // EDITCOMPUTER_H
