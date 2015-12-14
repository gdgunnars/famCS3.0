#ifndef EDIT_H
#define EDIT_H

#include<QDialog>
#include<cscientist.h>
#include<computer.h>
#include<ctime>
#include<Domain/persondomain.h>

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

    void on_listNotConnected_clicked(const QModelIndex &index);

    void on_deleteButton_clicked();

    void on_addButton_clicked();

private:
    Ui::edit *ui;
    //Editing start
    void getObject();
    void showInfo();

    //Fill placeholders
    void showCurrentValues();
    void showGender();
    void showYod();

    //Check for errors
    void clearError();
    bool checkForErrors();
    bool nameError();
    bool yearError();
    bool checkYear(QString year);
    int currentYear();

    //Make changes
    void executeChanges();
    void changeName();
    void changeGender();
    void changeYob();
    void changeYod();
    void changeFact();

    //List connections:
    void connections();

    //Quit:
    void quit();

    personDomain personD;
    cScientist currentPerson;
    vector<Computer> con;
    vector<Computer> notCon;

    int currentId;
    bool male;
};

#endif // EDIT_H
