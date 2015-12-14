#ifndef EDIT_H
#define EDIT_H

#include<QDialog>
#include<cscientist.h>
#include<computer.h>
#include<ctype.h>
#include<Domain/persondomain.h>
#include<Domain/computerdomain.h>

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

private:
    Ui::edit *ui;


    void getObject();
    void editPerson();

    void showCurrentValues();
    void showGender();
    void showYod();

    void clearError();
    bool checkError();
    bool nameError();
    bool yearError();
    bool checkYear(QString year);

    personDomain personD;
    cScientist currentPerson;

    int currentId;
};

#endif // EDIT_H
