#ifndef INFO_H
#define INFO_H

#include <QDialog>

namespace Ui {
class info;
}

class info : public QDialog
{
    Q_OBJECT

public:
    explicit info(QWidget *parent = 0);
    ~info();

private:
    Ui::info *ui;
};

#endif // INFO_H
