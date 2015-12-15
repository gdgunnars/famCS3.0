#ifndef TRASH_H
#define TRASH_H

#include <QDialog>
#include "cscientist.h"
#include "computer.h"
#include "Domain/computerdomain.h"
#include "Domain/persondomain.h"

namespace Ui {
class Trash;
}

class Trash : public QDialog
{
    Q_OBJECT

public:
    explicit Trash(QWidget *parent = 0);
    ~Trash();

private slots:
    void on_pushButton_clicked(); //Restores current selected scientist back to list

    void on_pushButton_2_clicked(); //Restores currents computer back to list

private:
    Ui::Trash *ui;
    //vectors
    vector<cScientist>  currentPersonVector;
    vector<Computer>    currentComputerVector;

    //objects
    personDomain personD;
    computerDomain computerD;

    //funcs
    void getErased(); //Gets list of computer and scientist that have been erased and list them

};

#endif // TRASH_H
