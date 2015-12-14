#include "edit.h"
#include "ui_edit.h"

edit::edit(const int& id,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit),
    currentId(id)
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
     currentPerson = personD.getPerson(currentId);
     editPerson();
}

void edit::editPerson()
{
    showCurrentValues();
    connections();
}

void edit::showCurrentValues()
{
    ui->lineName->setPlaceholderText(QString::fromStdString(currentPerson.getName()));
    showGender();
    ui->lineYob->setPlaceholderText(QString::number(currentPerson.getYearBirth()));
    showYod();
    ui->lineFact->setPlaceholderText(QString::fromStdString(currentPerson.getFact()));
}
void edit::showGender()
{
    char gender = currentPerson.getSex();
    if(gender == 'F' || gender == 'f'){
        ui->femaleButton->setChecked(1);
        male = 0;
    }
    else{
        ui->maleButton->setChecked(1);
        male = 1;
    }
}

void edit::showYod()
{
    int yod = currentPerson.getYearDeath();
    if(yod == 0){
        ui->checkIfAlive->setChecked(1);
        ui->lineYod->setPlaceholderText("Alive");
    }
    else{
        ui->lineYod->setPlaceholderText(QString::number(currentPerson.getYearDeath()));
    }

}

void edit::clearError()
{
    ui->errorName->clear();
    ui->errorYob->clear();
    ui->errorYod->clear();
}

bool edit::checkError()
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

    if(!(ui->checkIfAlive->isChecked())){
        if((yearB-yearD) > 0){
            error = true;
            ui->errorYob->setText("Cannot be born before dying");
        }
        else if ((currentPerson.getYearBirth()-yearD) > 0){
            error = true;
            ui->errorYob->setText("Cannot be born before dying");
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

void edit::executeChanges()
{
    changeName();
    changeGender();
    changeYob();
    changeYod();
    changeFact();
    quit();
    /*clearAll();
    getObject();
    showCurrentValues();*/
}

void edit::changeName()
{
    QString name = ui->lineName->text();

    if(name.isEmpty()){
        return;
    }
    else{
        personD.editPerson(currentId,name,2);
    }
}

void edit::changeGender()
{
    if(ui->femaleButton->isChecked() && male == true){
        personD.editPerson(currentId,"F",3);
    }
    else if (ui->maleButton->isChecked() && male == false){
        personD.editPerson(currentId,"M",3);
    }
    else
        return;
}

void edit::changeYob()
{
    QString year = ui->lineYob->text();
    if(year.isEmpty()){
        return;
    }
    else{
        personD.editPerson(currentId,year,4);
    }

}

void edit::changeYod()
{
   QString year = ui->lineYod->text();
   if(ui->checkIfAlive->isChecked() && currentPerson.getYearDeath() == 0)
   {
       return;
   }
   else if(ui->checkIfAlive->isChecked())
   {
       personD.editPerson(currentId,"0",5);
   }
   else if(!(ui->checkIfAlive->isChecked()) && year.isEmpty())
   {
      return;
   }
   else
   {
      personD.editPerson(currentId,year,5);
   }
}

void edit::changeFact()
{
    QString fact = ui->lineFact->text();
    if(fact.isEmpty()){
        return;
    }
    else{
        personD.editPerson(currentId,fact,6);
    }
}

void edit::clearAll()
{
    ui->lineName->clear();
    ui->lineYob->clear();
    ui->lineYod->clear();
    ui->lineFact->clear();
}

void edit::connections()
{
    vector<Computer> con = personD.compsConnectedToPerson(currentId);
    for(unsigned int i = 0; i < con.size(); i++){
        ui->listConnected->addItem(QString::fromStdString(con[i].getName()));
    }
    vector<Computer> notCon = personD.compsNotConnectedToPerson(currentId);
    for(unsigned int i = 0; i < notCon.size(); i++){
        ui->listNotConnected->addItem(QString::fromStdString(notCon[i].getName()));
    }
}

void edit::quit()
{
    close();
}

void edit::on_updateButton_clicked()
{
    clearError();
    bool error = checkError();
    if(error == false){
        executeChanges();
    }
    else
        return;
}


