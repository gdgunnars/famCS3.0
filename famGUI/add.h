#ifndef ADD_H
#define ADD_H

#include <QDialog>
#include "Domain/computerdomain.h"

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
    void on_pushButtonAddPerson_clicked();

private:
    Ui::add *ui;
    vector<Computer> allComp;
    computerDomain computerD;

    //Check for errors
    void clearError();
    bool checkForErrors();
    bool nameError();
    bool yearError();
    bool checkYear(QString year);
    int currentYear();

};

#endif // ADD_H
