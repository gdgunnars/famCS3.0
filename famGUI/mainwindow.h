#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QModelIndex>
#include <QVariant>
#include <QStandardItem>
#include "cscientist.h"
#include "computer.h"
#include "trash.h"
#include "edit.h"
#include "Domain/persondomain.h"
#include "Domain/computerdomain.h"

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
    void on_listOfScientist_clicked(const QModelIndex &index);

    void on_searchName_textChanged(const QString &arg1);

    void on_scientistButton_clicked();

    void on_computerButton_clicked();

    void on_edit_clicked();

    void on_delete_2_clicked();

    void on_trash_clicked();

private:
    Ui::MainWindow *ui;
    personDomain personD;
    computerDomain computerD;
    vector<cScientist> currentVectorP;
    bool PC;

    //Starting
    void startingList();

    //Display table
    void displayListPersons(vector<cScientist> a);
    QString showGender(char input); //Gets gender as a char and returns QString with gender
    QString showYear(int input); //Gets year as int and returns QString with year
    void createTablePersons(const int& size);
    void displayListComputers(vector<Computer> a);
    QString showBuilt(bool input);
    void createTableComputers(const int& size);
    void moreInfo();
    void connectedComputers();

    //Switch:
    void switchLists();

    //Utilities:
    int getIdFromSelected();

};

#endif // MAINWINDOW_H
