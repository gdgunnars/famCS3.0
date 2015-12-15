#include "trash.h"
#include "ui_trash.h"

Trash::Trash(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Trash)
{
    ui->setupUi(this);
    getErased();
}

Trash::~Trash()
{
    delete ui;
}

void Trash::getErased(){
    ui->person_listWidget->clear();
    ui->computer_listWidget->clear();
    currentPersonVector = personD.listErased();
    currentComputerVector = computerD.listErased();

    for(unsigned int i = 0; i < currentPersonVector.size(); i++){
        ui->person_listWidget->addItem(QString::fromStdString(currentPersonVector[i].getName()));
    }

    for(unsigned int i = 0; i < currentComputerVector.size(); i++){
        ui->computer_listWidget->addItem(QString::fromStdString(currentComputerVector[i].getName()));
    }
}

void Trash::on_pushButton_clicked()
{
    if(ui->person_listWidget->currentRow() >= 0){
        int rowId = ui->person_listWidget->currentRow();
        int id = currentPersonVector[rowId].getId();
        personD.restoreFromBin(id);
        getErased();
    }
}

void Trash::on_pushButton_2_clicked()
{
    if(ui->computer_listWidget->currentRow() >= 0){
        int rowId = ui->computer_listWidget->currentRow();
        int id = currentComputerVector[rowId].getId();
        computerD.restoreFromBin(id);
        getErased();
    }
}
