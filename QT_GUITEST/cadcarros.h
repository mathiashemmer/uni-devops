#ifndef CADCARROS_H
#define CADCARROS_H

#include <QDialog>

namespace Ui {
class CadCarros;
}

class CadCarros : public QDialog
{
    Q_OBJECT

public:
    explicit CadCarros(QWidget *parent = nullptr);
    ~CadCarros();

private:
    Ui::CadCarros *ui;
};

#endif // CADCARROS_H
