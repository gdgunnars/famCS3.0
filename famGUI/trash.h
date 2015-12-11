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
    void on_pushButton_clicked();

private:
    Ui::Trash *ui;
    //vectors
    vector<cScientist>  currentPersonVector;
    vector<Computer>    currentComputerVector;

    //objects
    personDomain personD;
    computerDomain computerD;

    //funcs
    void getErased();

};

#endif // TRASH_H
