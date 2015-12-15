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



void add::on_pushButtonAddPerson_clicked()
{
    string name = ui->lineEdit_name->text().toStdString();
    char
    if(ui->radioButtonFemale->isChecked())
        personD.editPerson(currentId,"F",3);
    personD.editPerson(currentId,"M",3);

}
void edit::clearError()
{
    ui->errorName->clear();
    ui->errorYob->clear();
    ui->errorYod->clear();
}

bool edit::checkForErrors()
{
    bool error = false;
    error = nameError();
    if(error == true){
        return error;
    }
    error = yearError();
    return error;
}

bool edit::nameError()
{
    bool error = false;
    string name = ui->lineName->text().toStdString();

    for(unsigned int i = 0; i < name.length();i++){
        if(isdigit(name[i])){
            error = true;
            ui->errorName->setText("Name cannot include numbers");
        }
    }
    return error;
}

bool edit::yearError()
{
    bool error = false;

    error = checkYear(ui->lineYob->text());
    if(error == true){
        ui->errorYob->setText("Year cannot include letters");
        return error;
    }
    error = checkYear(ui->lineYod->text());
    if(error == true){
        ui->errorYod->setText("Year cannot include letters");
        return error;
    }

    int yearB = ui->lineYob->text().toInt();
    int yearD = ui->lineYod->text().toInt();

    error = maxYear(yearB, yearD);
    if (error == true){
        return error;
    }

      if(!(ui->checkIfAlive->isChecked())){
        error = yearCompareson(yearB, yearD);
    }

    return error;
}

bool edit::checkYear(QString year)
{
    string ye = year.toStdString();
    for(unsigned int i = 0; i < ye.length(); i++){
        if(isalpha(ye[i])){
            return true;
        }
    }
    return false;
}
int edit::currentYear(){
    time_t t = time(0);
    struct tm * now = localtime( & t );
    return (now->tm_year + 1900);
}
bool edit::maxYear(int yearB, int yearD){
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

bool edit::yearCompareson(int yearB, int yearD){
    bool error = false;

    QString yearBi = ui->lineYob->text();
    QString yearDe = ui->lineYod->text();

    if ((yearBi.isEmpty())&&(!(yearDe.isEmpty()))){
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
   }
    return error;
}

