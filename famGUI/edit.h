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

    void on_listConnected_clicked(const QModelIndex &index);

private:
    Ui::edit *ui;
    //Editing start
    void getObject();
    void editPerson();

    //Fill placeholders
    void showCurrentValues();
    void showGender();
    void showYod();

    //Check for errors
    void clearError();
    bool checkError();
    bool nameError();
    bool yearError();
    bool checkYear(QString year);

    //Make changes
    void executeChanges();
    void changeName();
    void changeGender();
    void changeYob();
    void changeYod();
    void changeFact();

    void connections();

    void quit();

    personDomain personD;
    cScientist currentPerson;

    int currentId;
    bool male;
};

#endif // EDIT_H
