#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStringList>
const int COLUMNS_PERSON = 5;
const int COLUMNS_COMPUTER = 4;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    PC = 0;
    ui->scientistButton->setChecked(!PC);
    ui->computerButton->setChecked(PC);
    startingList();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startingList()
{
    if(PC){
        vector<Computer> list = computerD.sortByName(0);
        displayListComputers(list);
    }
    else{
        vector<cScientist> list = personD.sortByName(0);
        displayListPersons(list);
    }
}
void MainWindow::displayListPersons(vector<cScientist> a)
{

    vector<cScientist> list = a;
    createTablePersons(a.size());

    ui->listOfScientist->setSortingEnabled(false);
    for(unsigned int i = 0;i < a.size(); i++){
        cScientist current = list[i];
        ui->listOfScientist->setItem(i,0, new QTableWidgetItem(QString::number(current.getId())));
        ui->listOfScientist->setItem(i,1, new QTableWidgetItem(QString::fromStdString(current.getName())));
        char ge = current.getSex();
        QString gender;
        if(ge == 'M' || ge == 'm'){
            gender = "Male";
        }
        else
        {
            gender = "Female";
        }
        ui->listOfScientist->setItem(i,2, new QTableWidgetItem(gender));
        ui->listOfScientist->setItem(i,3, new QTableWidgetItem(QString::number(current.getYearBirth())));
        int yod = current.getYearDeath();
        if(yod == 0){
            QString yo = "--";
            ui->listOfScientist->setItem(i,4, new QTableWidgetItem(yo));
        }
        else{
            ui->listOfScientist->setItem(i,4, new QTableWidgetItem(QString::number(yod)));
        }

    }
    ui->listOfScientist->setSortingEnabled(true);
}
void MainWindow::createTablePersons(const int& size)
{
    ui->listOfScientist->setRowCount(size);
    ui->listOfScientist->setColumnCount(COLUMNS_PERSON);
    ui->listOfScientist->verticalHeader()->setVisible(false);

    QStringList header;
    header << "ID" << "Name" << "Gender" << "Year of Birth" << "Year of Death";
    ui->listOfScientist->setHorizontalHeaderLabels(header);
}

void MainWindow::displayListComputers(vector<Computer> a)
{
    vector<Computer> list = a;
    createTableComputers(a.size());

    ui->listOfScientist->setSortingEnabled(false);
    for(unsigned int i = 0;i < a.size(); i++){
        Computer current = list[i];
        ui->listOfScientist->setItem(i,0, new QTableWidgetItem(QString::number(current.getId())));
        ui->listOfScientist->setItem(i,1, new QTableWidgetItem(QString::fromStdString(current.getName())));
        int year = current.getYear();
        QString yea;
        if(year == 0){
            yea = "--";
            ui->listOfScientist->setItem(i,2, new QTableWidgetItem(yea));
        }
        else{
            ui->listOfScientist->setItem(i,2, new QTableWidgetItem(QString::number(year)));
        }
        ui->listOfScientist->setItem(i,3, new QTableWidgetItem(QString::fromStdString(current.getType())));
        bool built = current.getBuilt();
        QString b;
        if(built)
            b = "Built";
        else
            b = "Not built";
        ui->listOfScientist->setItem(i,4, new QTableWidgetItem(b));

    }
    ui->listOfScientist->setSortingEnabled(true);
}

void MainWindow::createTableComputers(const int &size)
{
    ui->listOfScientist->setRowCount(size);
    ui->listOfScientist->setColumnCount(COLUMNS_COMPUTER);
    ui->listOfScientist->verticalHeader()->setVisible(false);

    QStringList header;
    header << "ID" << "Name" << "Year" << "Type" << "Built or not";
    ui->listOfScientist->setHorizontalHeaderLabels(header);
}

void MainWindow::switchLists()
{
    if(PC){
        startingList();
        ui->searchName->clear();
        ui->searchName->setPlaceholderText("Filter by name... (more later)");
        ui->add->setText("Add computer");
        ui->edit->setText("Edit computer");
        ui->delete_2->setText("Delete computer");
    }
    else{
        startingList();
        ui->searchName->clear();
        ui->searchName->setPlaceholderText("Filter by name, year of death/birth");
        ui->add->setText("Add scientist");
        ui->edit->setText("Edit scientist");
        ui->delete_2->setText("Delete scientist");
    }
}

void MainWindow::on_listOfScientist_clicked(const QModelIndex &index)
{
   QList<QTableWidgetItem*> sci = ui->listOfScientist->selectedItems();
   QTableWidgetItem* s = sci[0];
 //   personD.editPerson(
}

void MainWindow::on_searchName_textChanged(const QString &arg1)
{
        if(PC){
            string input = ui->searchName->text().toStdString();
            vector<Computer> list = computerD.searchByName(input);
            if(input == ""){
                startingList();
                return;
            }
            displayListComputers(list);
        }
        else{
            string input = ui->searchName->text().toStdString();
            vector<cScientist> list = personD.searchByName(input);
            if(input == ""){
                startingList();
                return;
            }
            displayListPersons(list);
        }
}

void MainWindow::on_scientistButton_clicked()
{
    if(PC){
        PC = 0;
        switchLists();
    }
    else{
        return;
    }
}

void MainWindow::on_computerButton_clicked()
{
    if(PC){
        return;
    }
    else{
        PC = 1;
        switchLists();
    }
}
