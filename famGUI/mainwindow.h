#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QModelIndex>
#include <QVariant>
#include <QStandardItem>
#include "cscientist.h"
#include "computer.h"
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
    void createTablePersons(const int& size);
    void displayListComputers(vector<Computer> a);
    void createTableComputers(const int& size);

    //Switch:
    void switchLists();


};

#endif // MAINWINDOW_H
