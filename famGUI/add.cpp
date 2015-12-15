#include "add.h"
#include "ui_add.h"

add::add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add)
{
    ui->setupUi(this);
    fillComList();
}

add::~add()
{
    delete ui;
}

void add::fillComList(){
    allComp = computerD.sortByName(0);
    for(unsigned int i = 0; i < allComp.size(); i++){
        ui->listWidgetComputers->addItem(QString::fromStdString(allComp[i].getName()));
    }
}

void add::clearError()
{
    ui->errorName->clear();
    ui->errorYob->clear();
    ui->errorYod->clear();
}

bool add::checkForErrors()
{
    bool error = false;
    error = nameError();
    if(error == true){
        return error;
    }
    error = yearError();
    return error;
}

bool add::nameError()
{
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

bool add::yearError()
{
    bool error = false;

    error = checkYear(ui->lineEdit_yob->text());
    if(error == true){
        ui->errorYob->setText("Year cannot include letters");
        return error;
    }
    error = checkYear(ui->lineEdit_yod->text());
    if(error == true){
        ui->errorYod->setText("Year cannot include letters");
        return error;
    }

    int yearB = ui->lineEdit_yob->text().toInt();
    int yearD = ui->lineEdit_yod->text().toInt();

    error = maxYear(yearB, yearD);
    if (error == true){
        return error;
    }

      if(!(ui->checkBox_deceaced->isChecked())){
        error = yearComparison(yearB, yearD);
    }

    return error;
}

bool add::checkYear(QString year)
{
    string ye = year.toStdString();
    for(unsigned int i = 0; i < ye.length(); i++){
        if(isalpha(ye[i])){
            return true;
        }
    }
    return false;
}
int add::currentYear(){
    time_t t = time(0);
    struct tm * now = localtime( & t );
    return (now->tm_year + 1900);
}
bool add::maxYear(int yearB, int yearD){
    bool error = false;

    if ((yearB - currentYear()) > 0){
        error = true;
        ui->errorYob->setText("Invalid year of birth");
    }

    if (yearD - currentYear() > 0){
        error = true;
        ui->errorYod->setText("Invalid year of death");
    }
    return error;
}

bool add::yearComparison(int yearB, int yearD){
    bool error = false;

    QString yearBi = ui->lineEdit_yob->text();
    QString yearDe = ui->lineEdit_yod->text();

/*    if ((yearBi.isEmpty())&&(!(yearDe.isEmpty()))){
       yearB = currentPerson.getYearBirth();
       if ((yearD - yearB) < 0){
           error = true;
           ui->errorYob->setText("Year of death invalid in comparison to year of birth");
       }
   }
   else if(!(yearBi.isEmpty())&&(yearDe.isEmpty())){
        yearD = currentPerson.getYearDeath();
        if((yearD - yearB) < 0){
            error = true;
            ui->errorYob->setText("Year of death invalid in comparison to year of birth");
        }
    }
   else if((yearD - yearB) < 0){
       error = true;
       ui->errorYob->setText("Year of death invalid in comparison to year of birth");
   }*/
    return error;
}

void add::on_pushButtonAddPerson_clicked()
{
    clearError();
    if(!checkForErrors()){
        string name = ui->lineEdit_name->text().toStdString();
        char gender;
        if(ui->radioButtonFemale->isChecked())
            gender = 'F';
        else
            gender = 'M';
        int YoB = ui->lineEdit_yob->text().toInt();
        int YoD;
        if(ui->checkBox_deceaced->isChecked())
            YoD = 0;
        else
            YoD = ui->checkBox_deceaced->text().toInt();
        string funFact = ui->lineEdit_funfact->text().toStdString();
        int newPersonId = personD.addPerson(name, gender, YoB, YoD, funFact);

        if(ui->checkBoxConnectCPU->isChecked()){
           QList<QListWidgetItem *> cpuIDs = ui->listWidgetComputers->selectedItems();
           for(unsigned int i = 0; i < cpuIDs.size(); i++){
               personD.addConnection(newPersonId,allComp[ui->listWidgetComputers->row(cpuIDs.at(i))].getId());
           }
        }
        close();
    }
}
