#ifndef ADDCOMPUTER_H
#define ADDCOMPUTER_H

#include <QDialog>
#include "cscientist.h"
#include "Domain/computerdomain.h"
#include "Domain/persondomain.h"
namespace Ui {
class addComputer;
}

class addComputer : public QDialog
{
    Q_OBJECT

public:
    explicit addComputer(QWidget *parent = 0);
    ~addComputer();

private slots:
    void on_pushButton_addComputer_clicked();

private:
    Ui::addComputer *ui;
    vector<cScientist> allPers;
    personDomain personD;
    computerDomain computerD;

    void fillPersList();

    //Check for errors
    void clearError(); //Clears all former errors
    bool checkForErrors(); //Main controller to start all error check
    bool nameError(); //Is true if name contains number
    bool yearError(); //Main controller for error check in year
    bool checkYear(QString year); //Is true if year contains letter
    int currentYear(); //Gives current year
    bool maxYear(int yearB); //Is true if input year is greater then current year
};

#endif // ADDCOMPUTER_H
