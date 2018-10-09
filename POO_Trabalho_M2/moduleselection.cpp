#include "moduleselection.h"
#include "ui_moduleselection.h"
#include <QMessageBox>

ModuleSelection::ModuleSelection(QWidget *parent) : QDialog(parent), ui(new Ui::ModuleSelection)
{
    ui->setupUi(this);

    ui->tbl_carros->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tbl_carros->setColumnWidth(0, 25);
    EscondeTodasTabs();
}

ModuleSelection::~ModuleSelection()
{
    delete ui;
}

void ModuleSelection::EscondeTodasTabs()
{
    ui->tab_carros->hide();
}

void ModuleSelection::on_btn_clientes_clicked()
{
    EscondeTodasTabs();
}

void ModuleSelection::on_btn_contratos_clicked()
{

}

void ModuleSelection::on_btn_financeiro_clicked()
{

}

void ModuleSelection::on_btn_funcionarios_clicked()
{

}

/*
===========================================================================================================================
CADASTRO E VISUALIZAÇÃO DE CARROS <---|>===================================================================================
===========================================================================================================================
*/

// Visualiza cadastro e lista de carros ao clicar no módulo
void ModuleSelection::on_btn_carros_clicked()
{
    EscondeTodasTabs();
    ui->tab_carros->show();
    PreencheListaCarros();
}

//Preenche a TableView com todos os carros do sistema
void ModuleSelection::PreencheListaCarros()
{
    ui->tbl_carros->setRowCount(0);
    QLinkedList<Carro*>::iterator iter = dbCarros.begin();
    while(iter != dbCarros.end()){
        ui->tbl_carros->insertRow(ui->tbl_carros->rowCount());
        ui->tbl_carros->setItem(ui->tbl_carros->rowCount()-1, 0, new QTableWidgetItem(QString::number(iter.i->t->getID())));
        ui->tbl_carros->setItem(ui->tbl_carros->rowCount()-1, 1, new QTableWidgetItem(iter.i->t->getPlaca()));
        ui->tbl_carros->setItem(ui->tbl_carros->rowCount()-1, 2, new QTableWidgetItem(iter.i->t->getCor()));
        ui->tbl_carros->setItem(ui->tbl_carros->rowCount()-1, 3, new QTableWidgetItem(QString::number(iter.i->t->getKmAtual())));
        ui->tbl_carros->setItem(ui->tbl_carros->rowCount()-1, 4, new QTableWidgetItem(iter.i->t->getDisponivel() == true? "Livre":"Ocupado"));
        ++iter;
    }
}

//Mudar tela para ediçao ao duplo clique na tabela
void ModuleSelection::on_tbl_carros_cellDoubleClicked(int row, int column)
{
    int idcarro = ui->tbl_carros->takeItem(row, 0)->text().toInt();
    ui->tab_carros->setCurrentIndex(1);
    ui->lbl_carros_id->setText(QString::number(idcarro));

    Carro *carroAtual = nullptr;

    ui->tbl_carros->setRowCount(0);
    QLinkedList<Carro*>::iterator iter = dbCarros.begin();
    while(iter != dbCarros.end() && iter.i->t->getID() != idcarro){
        ++iter;
    }
    carroAtual = iter.i->t;
    if(carroAtual != nullptr){
        ui->txt_carros_cor->setText(carroAtual->getCor());
        ui->txt_carros_kmatual->setText(QString::number(carroAtual->getKmAtual()));
        ui->txt_carros_placa->setText(carroAtual->getPlaca());
    }
}

//Atualiza TableView quando trocado a tab para da Table
void ModuleSelection::on_tab_carros_currentChanged(int index)
{
    if(index == 0){
        PreencheListaCarros();
        ui->txt_carros_cor->setText("");
        ui->txt_carros_kmatual->setText("");
        ui->txt_carros_placa->setText("");

    }
}

//Insere novo veiculo nos registros
void ModuleSelection::on_btn_carros_cadastro_novo_clicked()
{
    if(ui->txt_carros_cor->text().size() < 1 || ui->txt_carros_kmatual->text().size() < 1 || ui->txt_carros_placa->text().size() < 1){
        QMessageBox::warning(this, "Erro no Cadastro!", "Alguns dos campos estão muito pequenos ou em branco!");
        return;
    }else{
        Carro* novoCarro = new Carro();
        novoCarro->setCor(ui->txt_carros_cor->text());
        novoCarro->setPlaca(ui->txt_carros_placa->text());
        novoCarro->setKmAtual(ui->txt_carros_kmatual->text().toInt());

        dbCarros.append(novoCarro);
        ui->tab_carros->setCurrentIndex(0);
    }
}

//Atualiza cadastro de carro no sistema
void ModuleSelection::on_btn_carros_cadastro_atualiza_clicked()
{
    int idCarro = ui->lbl_carros_id->text().toInt();
    bool foundCar = false;

    QLinkedList<Carro*>::iterator iter = dbCarros.begin();
    do{
        Carro *atual = iter.i->t;
        if(atual->getID() == idCarro){
            atual->setPlaca( ui->txt_carros_placa->text());
            atual->setCor( ui->txt_carros_cor->text());
            atual->setKmAtual(ui->txt_carros_kmatual->text().toInt());
            foundCar = true;
        }
        ++iter;
    }while(iter != dbCarros.end() && !foundCar);
    if(foundCar){
        ui->tab_carros->setCurrentIndex(0);
    }else{
        QMessageBox::warning(this, "Aviso!", "Nenhum veículo encontrado para atualizar!");
    }
}

//Exclui registro selecionado
void ModuleSelection::on_btn_carros_cadastro_exclui_clicked()
{
    int idcarro = ui->lbl_carros_id->text().toInt();
    bool foundCar = false;
    QLinkedList<Carro*>::iterator iter = dbCarros.begin();
    do{
        Carro *atual = iter.i->t;
        if(atual->getID() == idcarro){
            dbCarros.removeOne(atual);
            foundCar = true;
        }
        ++iter;
    }while(iter != dbCarros.end() && !foundCar);
    if(!foundCar){
        QMessageBox::warning(this, "Aviso!", "Nenhum veículo encontrado para excluir!");
    }else{
        ui->tab_carros->setCurrentIndex(0);
    }
}
