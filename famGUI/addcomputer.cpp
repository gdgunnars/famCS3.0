#include "addcomputer.h"
#include "ui_addcomputer.h"

addComputer::addComputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addComputer)
{
    ui->setupUi(this);
    fillPersList();
}

addComputer::~addComputer()
{
    delete ui;
}

void addComputer::fillPersList(){

    allPers = personD.sortByName(0);
    for(unsigned int i = 0; i < allPers.size(); i++){
        ui->listAllPersons->addItem(QString::fromStdString(allPers[i].getName()));
    }
}

void addComputer::clearError(){

    ui->errorName->clear();
    ui->errorYear->clear();
    ui->errorYod->clear();
}

bool addComputer::checkForErrors(){

    bool error = false;
    error = nameError();
    if(error == true){
        return error;
    }
    error = yearError();
    return error;
}

bool addComputer::nameError(){

    bool error = false;
    string name = ui->lineEdit_name->text().toStdString();

    for(unsigned int i = 0; i < name.length();i++){
        if(isdigit(name[i])){
            error = true;
            ui->errorName->setText("Name cannot include numbers");
        }
    }
    return error;
}

bool addComputer::yearError(){

    bool error = false;

    error = checkYear(ui->lineEdit_buildYear->text());
    if(error == true){
        ui->errorYear->setText("Year cannot include letters");
        return error;
    }

    int yearB = ui->lineEdit_buildYear->text().toInt();

    error = maxYear(yearB);

    return error;
}

bool addComputer::checkYear(QString year){

    string ye = year.toStdString();
    for(unsigned int i = 0; i < ye.length(); i++){
        if(isalpha(ye[i])){
            return true;
        }
    }
    return false;
}

int addComputer::currentYear(){
    time_t t = time(0);
    struct tm * now = localtime( & t );
    return (now->tm_year + 1900);
}

bool addComputer::maxYear(int yearB){
    bool error = false;

    if ((yearB - currentYear()) > 0){
        error = true;
        ui->errorYob->setText("Invalid build year");
    }

    return error;
}

void addComputer::on_pushButton_addComputer_clicked()
{
   // clearError();
  //  if(!checkForErrors()){
       string name = ui->lineEdit_name->text().toStdString();
       bool wasItBuilt;
       int buildYear;
       if(ui->checkBox_buildYear->isChecked()){
           wasItBuilt = false;
           buildYear = 0;
       } else {
           wasItBuilt = true;
           buildYear = ui->lineEdit_buildYear->text().toInt();
       }
       string type = ui->lineEdit_type->text().toStdString();

       int newComputerId = computerD.addComputer(name, buildYear, type, wasItBuilt);
       //        addPerson(name, gender, YoB, YoD, funFact);

    /*   if(ui->checkBoxConnectCPU->isChecked()){
          QList<QListWidgetItem *> cpuIDs = ui->listWidgetComputers->selectedItems();
          for(int i = 0; i < cpuIDs.size(); i++){
              personD.addConnection(newPersonId,allComp[ui->listWidgetComputers->row(cpuIDs.at(i))].getId());
          }
       }
      */ close();
    //}
}
