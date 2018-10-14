#ifndef MODULESELECTION_H
#define MODULESELECTION_H

#include <QDialog>
#include <QLinkedList>
#include "carro.h"
#include "cliente.h"

namespace Ui {
class ModuleSelection;
}

class ModuleSelection : public QDialog
{
    Q_OBJECT

public:
    QLinkedList<Carro*> dbCarros;
    QLinkedList<Cliente*> dbClientes;

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

    void on_tbl_clientes_cellDoubleClicked(int row, int column);

    void on_tab_clientes_currentChanged(int index);

    void on_btn_clientes_cadastro_novo_clicked();

    void on_btn_clientes_cadastro_atualiza_clicked();

    void on_btn_clientes_cadastro_exclui_clicked();

private:
    Ui::ModuleSelection *ui;


    void EscondeTodasTabs();
    void PreencheListaCarros();
    void PreencheListaClientes();
};

#endif // MODULESELECTION_H
