#ifndef EDIT_H
#define EDIT_H

#include<QDialog>
#include<cscientist.h>
#include<computer.h>
#include<Domain/persondomain.h>
#include<Domain/computerdomain.h>

namespace Ui {
class edit;
}

class edit : public QDialog
{
    Q_OBJECT

public:
    explicit edit(QWidget *parent = 0);
    ~edit();

private:
    Ui::edit *ui;
    void getObject();
    void editPerson();
    void editComputer();
    void showCurrentValues();

    personDomain personD;
    computerDomain computerD;
    cScientist currentPerson;
    Computer currentComp;

    int currentId;
    bool PC;
};

#endif // EDIT_H
