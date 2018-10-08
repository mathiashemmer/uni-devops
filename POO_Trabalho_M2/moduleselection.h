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
    QList<Carro*> dbCarros;

    explicit ModuleSelection(QWidget *parent = nullptr);
    ~ModuleSelection();

private slots:
    void on_btn_carros_clicked();
    void on_btn_clientes_clicked();
    void on_btn_contratos_clicked();
    void on_btn_financeiro_clicked();
    void on_btn_funcionarios_clicked();
    void on_tbl_carros_cellDoubleClicked(int row, int column);
    void on_tab_carros_currentChanged(int index);
    void on_btn_carros_cadastro_novo_clicked();
    void on_btn_carros_cadastro_atualiza_clicked();
    void on_btn_carros_cadastro_exclui_clicked();

private:
    Ui::ModuleSelection *ui;


    void EscondeTodasTabs();
    void PreencheListaCarros();
};

#endif // MODULESELECTION_H
