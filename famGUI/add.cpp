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
