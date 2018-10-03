#ifndef MODULESELECTION_H
#define MODULESELECTION_H

#include <QDialog>
#include <QList>
#include "carro.h"

namespace Ui {
class ModuleSelection;
}

class ModuleSelection : public QDialog
{
    Q_OBJECT

public:
    QList<Carro> dbCarros;

    explicit ModuleSelection(QWidget *parent = nullptr);
    ~ModuleSelection();

private slots:
    void on_btn_carros_clicked();

    void on_btn_clientes_clicked();

    void on_btn_contratos_clicked();

    void on_btn_financeiro_clicked();

    void on_btn_funcionarios_clicked();

private:
    Ui::ModuleSelection *ui;
};

#endif // MODULESELECTION_H
