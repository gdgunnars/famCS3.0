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

editComputer::~editComputer()
{
    delete ui;
}

void editComputer::getObject()
{
    currentComputer = computerD.getComputer(currentId);
    showInfo();
}

void editComputer::showInfo()
{
    showCurrentValues();
    //connections();
}

void editComputer::showCurrentValues()
{
    ui->lineName->setPlaceholderText(QString::fromStdString(currentComputer.getName()));
    showYearBuilt();
    ui->lineType->setPlaceholderText(QString::fromStdString(currentComputer.getType()));
    showIfBuilt();
}

void editComputer::showYearBuilt()
{
    if(currentComputer.getYear() == 0){
        ui->lineYear->setPlaceholderText("Not built");
    }
    else{
        ui->lineYear->setPlaceholderText(QString::number(currentComputer.getYear()));
    }
}

void editComputer::showIfBuilt()
{
    if(currentComputer.getBuilt() == 0){
        ui->wasNotBuilt->setChecked(1);
    }
}

void editComputer::connections()
{

}
