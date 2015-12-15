#ifndef ADDCOMPUTER_H
#define ADDCOMPUTER_H

#include <QDialog>

namespace Ui {
class addComputer;
}

class addComputer : public QDialog
{
    Q_OBJECT

public:
    explicit addComputer(QWidget *parent = 0);
    ~addComputer();

private:
    Ui::addComputer *ui;
};

#endif // ADDCOMPUTER_H
