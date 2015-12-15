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

private:
    Ui::editComputer *ui;
    //Editing start
    void getObject();
    void showInfo();

    //Fill placeholders
    void showCurrentValues();
    void showYearBuilt();
    void showIfBuilt();

    //Check for errors
    void clearError();
    bool checkForErrors();
    bool yearError();
    bool checkYear(const QString& year);
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

    void quit();

    computerDomain computerD;
    Computer currentComputer;
    vector<cScientist> con;
    vector<cScientist> notCon;

    int currentId;
    bool built;
};

#endif // EDITCOMPUTER_H
