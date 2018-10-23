#ifndef MODULESCREEN_H
#define MODULESCREEN_H

#include <QDialog>
#include <QLinkedList>
#include <carro.h>
#include <cliente.h>
#include <aluguel.h>
#include <manuten.h>
#include <financeiro.h>

namespace Ui {
class ModuleScreen;
}

class ModuleScreen : public QDialog
{
    Q_OBJECT

public:
    explicit ModuleScreen(QWidget *parent = nullptr);
    ~ModuleScreen();

    QLinkedList<Carro*> dbCarros;
    QLinkedList<Cliente*> dbClientes;
    QLinkedList<Aluguel*> dbAlugueis;
    QLinkedList<Manuten*> dbManuten;
    QLinkedList<Financeiro*> dbFinanceiro;

    // Auxiliares
    void CarregaListaCarros();
    void AjustaPadraoEntradaCarros();

    void CarregaListaClientes();
    void AjustaPadraoEntradaClientes();

    void CarregaListaContratos();
    void AjustaPadraoEntradaContratos();

    void CarregaListaFinanceiro();
    void AjustaPadraoEntradaFinanceiro();

private slots:
    void on_tab_carros_currentChanged(int index);
    void on_btn_carros_registros_filtro_aplicar_clicked();
    void on_cbx_carros_registros_filtro_status_currentIndexChanged(const QString &arg1);
    void on_tbl_carros_registros_cellDoubleClicked(int row, int column);

    void on_btn_carros_cadastro_gravar_clicked();

    void on_btn_carros_cadastro_novo_clicked(bool checked);

    void on_btn_carros_cadastro_excluir_clicked();

    void on_txt_carros_registros_filtro_modelo_textChanged(const QString &arg1);
    void on_tab_clientes_currentChanged(int index);

    void on_txt_clientes_registros_filtro_nome_textChanged(const QString &arg1);

    void on_cbx_clientes_registros_filtro_conceito_currentIndexChanged(int index);

    void on_tab_contratos_currentChanged(int index);

    void on_btn_contratos_cadastro_novo_clicked();

    void on_tbl_clientes_registros_cellDoubleClicked(int row, int column);

    void on_btn_clientes_cadastro_gravar_clicked();

    void on_btn_clientes_cadastro_novo_clicked();

    void on_btn_clientes_cadastro_excluir_clicked();

    void on_tab_financeiro_currentChanged(int index);

    void on_btn_financeiro_cadastro_novo_clicked();

    void on_tbl_financeiro_registros_cellDoubleClicked(int row, int column);

    void on_btn_financeiro_cadastro_excluir_clicked();

    void on_btn_contratos_cadastro_excluir_clicked();

    void on_tbl_contratos_registros_cellDoubleClicked(int row, int column);

private:
    Ui::ModuleScreen *ui;
};

#endif // MODULESCREEN_H
