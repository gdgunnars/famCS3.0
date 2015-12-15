#include "editcomputer.h"
#include "ui_editcomputer.h"

editComputer::editComputer(const int& id, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editComputer),
    currentId(id)
{
    ui->setupUi(this);
    getObject();
}

editComputer::~editComputer(){

    delete ui;
}

void editComputer::getObject(){

    currentComputer = computerD.getComputer(currentId);
    showInfo();
}

void editComputer::showInfo(){

    showCurrentValues();
    connections();
}

void editComputer::showCurrentValues(){

    ui->lineName->setPlaceholderText(QString::fromStdString(currentComputer.getName()));
    showYearBuilt();
    ui->lineType->setPlaceholderText(QString::fromStdString(currentComputer.getType()));
    showIfBuilt();
}

void editComputer::showYearBuilt(){

    if(currentComputer.getYear() == 0){
        ui->lineYear->setPlaceholderText("Not built");
    }
    else{
        ui->lineYear->setPlaceholderText(QString::number(currentComputer.getYear()));
    }
}

void editComputer::showIfBuilt(){

    if(currentComputer.getBuilt() == 0){
        ui->wasNotBuilt->setChecked(1);
        built = 0;
    }
    else
        built = 1;
}

void editComputer::clearError(){

    ui->errorYear->clear();
    ui->errorType->clear();
}

bool editComputer::checkForErrors(){

    bool error = false;
    error = yearError();
    if(error == true){
        return error;
    }
    error = typeError();
    return error;
}

bool editComputer::yearError(){

    bool error = false;

    error = checkYear(ui->lineYear->text());
    if(error == true){
        ui->errorYear->setText("Year cannot include letters");
        return error;
    }

    int yearB = ui->lineYear->text().toInt();
    error = maxYear(yearB);

    return error;
}

bool editComputer::checkYear(const QString& year){

    string ye = year.toStdString();
    for(unsigned int i = 0; i < ye.length(); i++){
        if(isalpha(ye[i])){
            return true;
        }
    }
    return false;
}

bool editComputer::maxYear(int yearB){

    bool error = false;

    if ((yearB - currentYear()) > 0){
        error = true;
        ui->errorYear->setText("Invalid building year");
    }
    return error;
}

int editComputer::currentYear(){

    time_t t = time(0);
    struct tm * now = localtime( & t );
    return (now->tm_year + 1900);
}

bool editComputer::typeError(){
    string type = ui->lineType->text().toStdString();
    for(unsigned int i = 0; i < type.length(); i++){
        if(isdigit(type[i])){
            return true;
        }
    }
    return false;
}

void editComputer::executeChanges(){

    changeName();
    changeBuildYear();
    changeType();
    changeBuilt();
    quit();
}

void editComputer::changeName(){

    QString name = ui->lineName->text();

    if(name.isEmpty()){
        return;
    }
    else{
        computerD.editComputer(currentId,name,2);
    }
}

void editComputer::changeBuildYear(){

    QString year = ui->lineYear->text();
    if(year.isEmpty()){
        return;
    }
    else{
        computerD.editComputer(currentId,year,3);
    }
}

void editComputer::changeType(){

    QString type = ui->lineType->text();

    if(type.isEmpty()){
        return;
    }
    else{
        computerD.editComputer(currentId,type,4);
    }
}

void editComputer::changeBuilt(){

    if(ui->wasNotBuilt->isChecked() && built == 1){
        computerD.editComputer(currentId,"0",5);
    }
    else if (!(ui->wasNotBuilt->isChecked()) && built == 0){
        computerD.editComputer(currentId,"1",5);
    }
    else
        return;
}

void editComputer::connections(){

    ui->listConnected->clear();
    ui->listNotConnected->clear();

    con = computerD.persConnectedToComp(currentId);
    for(unsigned int i = 0; i < con.size(); i++){
        ui->listConnected->addItem(QString::fromStdString(con[i].getName()));
    }
    notCon = computerD.persNotConnectedToComp(currentId);
    for(unsigned int j = 0; j < notCon.size(); j++){
        ui->listNotConnected->addItem(QString::fromStdString(notCon[j].getName()));
    }
}

void editComputer::quit(){

    close();
}

void editComputer::on_updateButton_clicked(){

    clearError();
    bool error = checkForErrors();
    if(error == false){
        executeChanges();
    }
    else
        return;
}

void editComputer::on_listConnected_clicked(){

    ui->deleteButton->setEnabled(1);
    ui->addButton->setDisabled(1);
}

void editComputer::on_listNotConnected_clicked(){

    ui->deleteButton->setDisabled(1);
    ui->addButton->setEnabled(1);
}

void editComputer::on_deleteButton_clicked(){

    int index = ui->listConnected->currentRow();
    int id = con[index].getId();

    computerD.deleteConnection(currentId,id);
    connections();
}

void editComputer::on_addButton_clicked(){

    int index = ui->listNotConnected->currentRow();
    int id = notCon[index].getId();

    computerD.addConnection(currentId,id);
    connections();
}
