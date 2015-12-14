#include "edit.h"
#include "ui_edit.h"

edit::edit(const bool& pc, const int& id,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit),
    currentId(id),
    PC(pc)
{
    ui->setupUi(this);

    getObject();

}
edit::~edit()
{
    delete ui;
}

void edit::getObject()
{

    if(PC)
    {
         currentComp = computerD.getComputer(currentId);
         editComputer();
    }
    else
    {
         currentPerson = personD.getPerson(currentId);
         editPerson();
    }
}

void edit::editPerson()
{
    showCurrentValues();
}

void edit::editComputer()
{

}

void edit::showCurrentValues()
{
    if(PC)
    {

    }
    else
    {
        ui->lineOne->setPlaceholderText(QString::fromStdString(currentPerson.getName()));
        showGender();
        ui->lineThree->setPlaceholderText(QString::number(currentPerson.getYearBirth()));
        showYod();
        ui->lineFive->setPlaceholderText(QString::fromStdString(currentPerson.getFact()));
    }
}
void edit::showGender()
{
    char gender = currentPerson.getSex();
    if(gender == 'F' || gender == 'f'){
        ui->femaleButton->setChecked(1);
    }
    else{
        ui->maleButton->setChecked(1);
    }
}

void edit::showYod()
{
    int yod = currentPerson.getYearDeath();
    if(yod == 0){
        ui->checkIfAlive->setChecked(1);
        ui->lineFour->setPlaceholderText("Alive");
    }
    else{
        ui->lineFour->setPlaceholderText(QString::number(currentPerson.getYearDeath()));
    }

}

void edit::clearError()
{
    ui->errorOne->clear();
    ui->errorThree->clear();
    ui->errorFour->clear();
    ui->errorFive->clear();
}

bool edit::checkError()
{
    bool error = false;
    error = nameError();
    error = yearError();
    return error;

}

bool edit::nameError()
{
    bool error = false;
    string name = ui->lineOne->text().toStdString();

    for(unsigned int i = 0; i < name.length();i++){
        if(isdigit(name[i])){
            error = true;
            ui->errorOne->setText("Name cannot include numbers");
        }
    }
    return error;
}

bool edit::yearError()
{
    bool error = false;

    error = checkYear(ui->lineThree->text());
    if(error == true){
        ui->errorThree->setText("Year cannot include letters");
    }
    error = checkYear(ui->lineFour->text());
    if(error == true){
        ui->errorFour->setText("Year cannot include letters");
        return error;
    }

    int yearB = ui->lineThree->text().toInt();
    int yearD = ui->lineFour->text().toInt();

    if(!(ui->checkIfAlive->isChecked())){
        if((yearB-yearD) > 0){
            error = true;
            ui->errorThree->setText("Cannot be born before dying");
        }
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

void edit::on_updateButton_clicked()
{
    clearError();
    bool error = checkError();
    if(error == false);
        //executeChanges();
   /* else
        return;*/
}
