#ifndef TRASH_H
#define TRASH_H

#include <QDialog>

namespace Ui {
class Trash;
}

class Trash : public QDialog
{
    Q_OBJECT

public:
    explicit Trash(QWidget *parent = 0);
    ~Trash();

private:
    Ui::Trash *ui;
};

#endif // TRASH_H
