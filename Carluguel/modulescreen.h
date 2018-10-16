#ifndef MODULESCREEN_H
#define MODULESCREEN_H

#include <QDialog>
#include <QLinkedList>
#include <carro.h>

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

    // Auxiliares
    void CarregaListaCarros();
    void AjustaPadraoEntradaCarros();

private slots:
    void on_tab_carros_currentChanged(int index);
    void on_btn_carros_registros_filtro_aplicar_clicked();
    void on_cbx_carros_registros_filtro_status_currentIndexChanged(const QString &arg1);
    void on_tbl_carros_registros_cellDoubleClicked(int row, int column);

    void on_btn_carros_cadastro_gravar_clicked();

    void on_btn_carros_cadastro_novo_clicked(bool checked);

    void on_btn_carros_cadastro_excluir_clicked();

    void on_txt_carros_registros_filtro_modelo_textChanged(const QString &arg1);

private:
    Ui::ModuleScreen *ui;
};

#endif // MODULESCREEN_H
