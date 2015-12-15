#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStringList>
const int COLUMNS_PERSON = 5;
const int COLUMNS_COMPUTER = 5;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    PC = 0;
    ui->edit->setDisabled(true);
    ui->delete_2->setDisabled(true);
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
    ui->searchName->clear();
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
    QString gender;
    QString yo;

    createTablePersons(a.size());

    ui->listOfScientist->clearContents();
    ui->listOfScientist->setSortingEnabled(false);
    for(unsigned int i = 0;i < a.size(); i++){
        cScientist current = list[i];
        ui->listOfScientist->setItem(i,0, new QTableWidgetItem(QString::number(current.getId())));
        ui->listOfScientist->setItem(i,1, new QTableWidgetItem(QString::fromStdString(current.getName())));
        char ge = current.getSex();
        gender = showGender(ge);
        ui->listOfScientist->setItem(i,2, new QTableWidgetItem(gender));
        ui->listOfScientist->setItem(i,3, new QTableWidgetItem(QString::number(current.getYearBirth())));
        int yod = current.getYearDeath();
        yo = showYear(yod);
        ui->listOfScientist->setItem(i,4, new QTableWidgetItem(yo));
    }
    ui->listOfScientist->setSortingEnabled(true);
    currentVectorP = a;

    QString label = "Row count: ";
    label = label + QString::number(ui->listOfScientist->rowCount());
    ui->rowCount_label->setText(label);
}

QString MainWindow::showGender(char input){
    QString gender;
    if(input == 'M' || input == 'm'){
        gender = "Male";
    }
    else{
        gender = "Female";
    }
    return gender;
}

QString MainWindow::showYear(int input){
    QString year;
    if(input == 0){
        year = "--";
    }
    else{
        year = QString::number(input);
    }
    return year;
}

void MainWindow::createTablePersons(const int& size)
{
    ui->listOfScientist->setRowCount(size);
    ui->listOfScientist->setColumnCount(COLUMNS_PERSON);
    ui->listOfScientist->setColumnWidth(1,200);
    ui->listOfScientist->setColumnWidth(3,80);
    ui->listOfScientist->verticalHeader()->setVisible(true);
    ui->listOfScientist->setColumnHidden(0,true);
    QStringList header;
    header << "ID" << "Name" << "Gender" << "Year of Birth" << "Year of Death";
    ui->listOfScientist->setHorizontalHeaderLabels(header);
}

void MainWindow::displayListComputers(vector<Computer> a)
{
    vector<Computer> list = a;
    QString yea;

    createTableComputers(a.size());

    ui->listOfScientist->clearContents();
    ui->listOfScientist->setSortingEnabled(false);
    for(unsigned int i = 0; i < a.size(); i++){
        Computer current = list[i];
        ui->listOfScientist->setItem(i,0, new QTableWidgetItem(QString::number(current.getId())));
        ui->listOfScientist->setItem(i,1, new QTableWidgetItem(QString::fromStdString(current.getName())));
        int year = current.getYear();
        yea = showYear(year);
        ui->listOfScientist->setItem(i,2, new QTableWidgetItem(yea));
        ui->listOfScientist->setItem(i,3, new QTableWidgetItem(QString::fromStdString(current.getType())));
        bool built = current.getBuilt();
        QString b = showBuilt(built);
        ui->listOfScientist->setItem(i,4, new QTableWidgetItem(b));
    }
    ui->listOfScientist->setSortingEnabled(true);

    QString label = "Row count: ";
    label = label + QString::number(ui->listOfScientist->rowCount());
    ui->rowCount_label->setText(label);
}
QString MainWindow::showBuilt(bool input){
    QString output;
    if(input)
        output = "Built";
    else
        output = "Not built";
    return output;
}

void MainWindow::createTableComputers(const int &size)
{
    ui->listOfScientist->setRowCount(size);
    ui->listOfScientist->setColumnCount(COLUMNS_COMPUTER);
    ui->listOfScientist->verticalHeader()->setVisible(true);
    ui->listOfScientist->setColumnWidth(2,50);
    ui->listOfScientist->setColumnWidth(3,150);

    QStringList header;
    header << "ID" << "Name" << "Year" << "Type" << "Built or not";
    ui->listOfScientist->setHorizontalHeaderLabels(header);
}

void MainWindow::moreInfo()
{
    ui->infoList->clear();


    int id = getIdFromSelected();
    if(PC)
    {
        Computer current = computerD.getComputer(id);
        //ui->infoList->addItem("ID: " + QString::number(current.getId()));
    }
    else
    {
        cScientist current = personD.getPerson(id);
        ui->infoList->addItem(QString::fromStdString(current.getFact()));
    }
}

void MainWindow::connected()
{
    int id = getIdFromSelected();
    if(PC){
        vector<cScientist> list = computerD.persConnectedToComp(id);
        for(unsigned int i = 0; i < list.size();i++){
            ui->compConList->addItem(QString::fromStdString(list[i].getName()));
        }
    }
    else
    {
        vector<Computer> list = personD.compsConnectedToPerson(id);
        for(unsigned int i = 0; i < list.size();i++){
            ui->compConList->addItem(QString::fromStdString(list[i].getName()));
        }
    }
}

void MainWindow::switchLists()
{
    ui->edit->setDisabled(true);
    ui->delete_2->setDisabled(true);
    ui->infoList->clear();
    ui->compConList->clear();
    startingList();
    ui->searchName->clear();
    if(PC){
        ui->searchName->setPlaceholderText("Filter by name, year or type...");
        ui->add->setText("Add computer");
        ui->edit->setText("Edit computer");
        ui->delete_2->setText("Delete computer");
        ui->connectedLabel->setText("Scientists connected:");
        ui->infoList->setHidden(1);
        ui->factLabel->setHidden(1);

    }
    else{
        ui->searchName->setPlaceholderText("Filter by name, year of death/birth");
        ui->add->setText("Add scientist");
        ui->edit->setText("Edit scientist");
        ui->delete_2->setText("Delete scientist");
        ui->connectedLabel->setText("Computers connected:");
        ui->infoList->setHidden(0);
        ui->factLabel->setHidden(0);
    }
}

int MainWindow::getIdFromSelected(){
    int row;
    int column;
    row = ui->listOfScientist->currentRow();
    column = 0;
    QTableWidgetItem* ite = ui->listOfScientist->item(row,column);
    QString id = ite->text();

    return id.toInt();
}

// Buttons ---------
void MainWindow::on_listOfScientist_clicked(const QModelIndex &index)
{
    ui->compConList->clear();
    ui->edit->setEnabled(true);
    ui->delete_2->setEnabled(true);
    moreInfo();
    connected();
    QString id = QString::number(getIdFromSelected());
    ui->label_id->setText("ID: " + id);
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

void MainWindow::on_edit_clicked()
{
    QList<QModelIndex> selectedRows = ui->listOfScientist->selectionModel()->selectedRows();
    if (selectedRows.size() > 0) {
        QString id = QString::number(getIdFromSelected());
        int i = id.toInt();
        if(PC){
            editComputer window(i);
            window.exec();
            startingList();
        }
        else{
            edit window(i);
            window.exec();
            startingList();
        }
    }
}

void MainWindow::on_delete_2_clicked()
{
    QList<QModelIndex> selectedRows = ui->listOfScientist->selectionModel()->selectedRows();
    if (selectedRows.size() > 0) {
        int id = getIdFromSelected();
        if(!PC)
            personD.deletePerson(id);
        else
            computerD.deleteComputer(id);

        ui->listOfScientist->removeRow(ui->listOfScientist->currentRow());
        ui->infoList->clear();
        ui->compConList->clear();
    }
}
void MainWindow::on_trash_clicked()
{
    Trash bin;
    bin.exec();
    if(bin.close()){
        startingList();
    }
}

void MainWindow::on_actionGettingStarted_triggered()
{
    QString GetStarted = "https://github.com/gunnidg/famCS3.0/wiki";
    QDesktopServices::openUrl(QUrl(GetStarted));
}

void MainWindow::on_actionAbout_triggered()
{
    info about;
    about.exec();
}

