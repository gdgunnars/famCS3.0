#include "edit.h"
#include "ui_edit.h"

edit::edit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit)
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
    }
}
