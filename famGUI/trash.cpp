#include "trash.h"
#include "ui_trash.h"

Trash::Trash(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Trash)
{
    ui->setupUi(this);
}

Trash::~Trash()
{
    delete ui;
}
