#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QModelIndex>
#include <QVariant>
#include <QStandardItem>
#include <QDesktopServices>
#include <QUrl>
#include "cscientist.h"
#include "computer.h"
#include "trash.h"
#include "edit.h"
#include "editcomputer.h"
#include "Domain/persondomain.h"
#include "Domain/computerdomain.h"
#include "info.h"
#include "add.h"
#include "addcomputer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_listOfScientist_clicked(); //Enables more info on selected scientist and enables edit and delete buttins

    void on_searchName_textChanged(); //Takes in search string and sneds it to domain

    void on_scientistButton_clicked(); //Switches list to scientist

    void on_computerButton_clicked(); //Switches list to computer

    void on_edit_clicked(); //Opens up edit window for choosen id

    void on_delete_2_clicked(); //Deletes and removes from list

    void on_trash_clicked(); //Opens trash

    void on_actionGettingStarted_triggered(); //Opens link to getting started wiki

    void on_actionAbout_triggered(); //Opens about logo

    void on_add_clicked(); //Opens up add window

    void on_actionNewScientist_triggered(); //Other way to trigger add window for scientist

    void on_actionNewComputer_triggered(); //Other way to trigger add window for computer

private:
    Ui::MainWindow *ui;
    personDomain personD;
    computerDomain computerD;
    vector<cScientist> currentVectorP;
    bool PC;

    //Starting
    void startingList(); //clears search window and shows choosen list

    //Display table
    void displayListPersons(vector<cScientist> a); //Main controller for displaying each scientist in vector a
    QString showGender(char input); //Gets gender as a char and returns QString with gender
    QString showYear(int input); //Gets year as int and returns QString with year
    void createTablePersons(const int& size); //Creates a empty table of input size for scientists
    void displayListComputers(vector<Computer> a); //Main controller for displaying each computer in vector a
    QString showBuilt(bool input); //Changes bool value to built/not built
    void createTableComputers(const int& size); //Creates a empty table of input size for computers
    void moreInfo(); //Adds fact and id info on selected scientist/computer
    void connected(); //Shows connections on selected scientist/computer

    //Switch:
    void switchLists(); //Clears and sets up new list in list switch between computer and scientist list

    //Utilities:
    int getIdFromSelected(); //Returns id of selected

};

#endif // MAINWINDOW_H
