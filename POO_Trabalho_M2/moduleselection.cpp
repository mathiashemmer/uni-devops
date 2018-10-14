#include "moduleselection.h"
#include "ui_moduleselection.h"
#include <QMessageBox>
#include "cliente.h"

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
    ui->tab_clientes->hide();
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
    ui->tab_carros->setCurrentIndex(0);
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
        ui->tbl_carros->setItem(ui->tbl_carros->rowCount()-1, 3, new QTableWidgetItem(QString::number(iter.i->t->getQuilometragem())));
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
        ui->txt_carros_quilometragem->setText(QString::number(carroAtual->getQuilometragem()));
        ui->txt_carros_placa->setText(carroAtual->getPlaca());
    }
}

//Atualiza TableView quando trocado a tab para da Table
void ModuleSelection::on_tab_carros_currentChanged(int index)
{
    if(index == 0){
        PreencheListaCarros();
        ui->txt_carros_cor->setText("");
        ui->txt_carros_quilometragem->setText("");
        ui->txt_carros_placa->setText("");

    }
}

//Insere novo veiculo nos registros
void ModuleSelection::on_btn_carros_cadastro_novo_clicked()
{
    if(ui->txt_carros_cor->text().size() < 1 || ui->txt_carros_quilometragem->text().size() < 1 || ui->txt_carros_placa->text().size() < 1){
        QMessageBox::warning(this, "Erro no Cadastro!", "Alguns dos campos estão muito pequenos ou em branco!");
        return;
    }else{
        Carro* novoCarro = new Carro();
        novoCarro->setCor(ui->txt_carros_cor->text());
        novoCarro->setPlaca(ui->txt_carros_placa->text());
        novoCarro->setQuilometragem(ui->txt_carros_quilometragem->text().toInt());

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
            atual->setQuilometragem(ui->txt_carros_quilometragem->text().toInt());
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

/*
===========================================================================================================================
CADASTRO E VISUALIZAÇÃO DE CLIENTES <---|>=================================================================================
===========================================================================================================================
*/

// Visualiza cadastro e lista de clientes ao clicar no módulo
void ModuleSelection::on_btn_clientes_clicked()
{
    EscondeTodasTabs();
    ui->tab_clientes->show();
    PreencheListaClientes();
    ui->tab_clientes->setCurrentIndex(0);
}

// Preenche a TableView com todos os clientes do sistema
void ModuleSelection::PreencheListaClientes()
{
    ui->tbl_clientes->setRowCount(0);
    QLinkedList<Cliente*>::iterator iter = dbClientes.begin();
    while(iter != dbClientes.end()){
        ui->tbl_clientes->insertRow(ui->tbl_clientes->rowCount());
        ui->tbl_clientes->setItem(ui->tbl_clientes->rowCount()-1, 0, new QTableWidgetItem(QString::number(iter.i->t->getID())));
        ui->tbl_clientes->setItem(ui->tbl_clientes->rowCount()-1, 1, new QTableWidgetItem(iter.i->t->getNome()));
        ui->tbl_clientes->setItem(ui->tbl_clientes->rowCount()-1, 2, new QTableWidgetItem(iter.i->t->getCpf()));
        ui->tbl_clientes->setItem(ui->tbl_clientes->rowCount()-1, 3, new QTableWidgetItem(iter.i->t->getRg()));
        ui->tbl_clientes->setItem(ui->tbl_clientes->rowCount()-1, 4, new QTableWidgetItem(iter.i->t->getNascimento()));
        ui->tbl_clientes->setItem(ui->tbl_clientes->rowCount()-1, 5, new QTableWidgetItem(iter.i->t->getCnh()));
        ++iter;
    }
}

// Muda tela para edição ao dar duplo clique em um índice
void ModuleSelection::on_tbl_clientes_cellDoubleClicked(int row, int column)
{
    int idcliente = ui->tbl_clientes->takeItem(row, 0)->text().toInt();
    ui->tab_clientes->setCurrentIndex(1);
    ui->lbl_clientes_id->setText(QString::number(idcliente));

    Cliente *clienteAtual = nullptr;

    ui->tbl_clientes->setRowCount(0);
    QLinkedList<Cliente*>::iterator iter = dbClientes.begin();
    while(iter != dbClientes.end() && iter.i->t->getID() != idcliente){
        ++iter;
    }
    clienteAtual = iter.i->t;
    if(clienteAtual != nullptr){
        ui->txt_clientes_nome->setText(clienteAtual->getNome());
        ui->txt_clientes_cpf->setText(clienteAtual->getCpf());
        ui->txt_clientes_rg->setText(clienteAtual->getRg());
        ui->txt_clientes_nascimento->setText(clienteAtual->getNascimento());
        ui->txt_clientes_cnh->setText(clienteAtual->getCnh());
    }
}

// Preenche a lista toda vez que muda-se de tabela
void ModuleSelection::on_tab_clientes_currentChanged(int index)
{
    if(index == 0){
        PreencheListaClientes();
        ui->txt_clientes_nome->setText("");
        ui->txt_clientes_cpf->setText("");
        ui->txt_clientes_rg->setText("");
        ui->txt_clientes_nascimento->setText("");
        ui->txt_clientes_cnh->setText("");
    }
}

// Insere um novo cadastro de cliente
void ModuleSelection::on_btn_clientes_cadastro_novo_clicked()
{
    if(ui->txt_clientes_nome->text().size() < 1 || ui->txt_clientes_cpf->text().size() < 1 || ui->txt_clientes_rg->text().size() < 1
            || ui->txt_clientes_nascimento->text().size() < 1 || ui->txt_clientes_cnh->text().size() < 1){
        QMessageBox::warning(this, "Erro no Cadastro!", "Alguns dos campos estão muito pequenos ou em branco!");
        return;
    }else{
        Cliente *novoCliente = new Cliente();
        novoCliente->setNome(ui->txt_clientes_nome->text());
        novoCliente->setCpf(ui->txt_clientes_cpf->text());
        novoCliente->setRg(ui->txt_clientes_rg->text());
        novoCliente->setNascimento(ui->txt_clientes_nascimento->text());
        novoCliente->setCnh(ui->txt_clientes_cnh->text());

        dbClientes.append(novoCliente);
        ui->tab_clientes->setCurrentIndex(0);
    }
}

// Atualiza um cadastro atual
void ModuleSelection::on_btn_clientes_cadastro_atualiza_clicked()
{
    int idCliente = ui->lbl_clientes_id->text().toInt();
    bool foundCliente = false;

    QLinkedList<Cliente*>::iterator iter = dbClientes.begin();
    do{
        Cliente *atual = iter.i->t;
        if(atual->getID() == idCliente){
            atual->setNome(ui->txt_clientes_nome->text());
            atual->setCpf(ui->txt_clientes_cpf->text());
            atual->setRg(ui->txt_clientes_rg->text());
            atual->setNascimento(ui->txt_clientes_nascimento->text());
            atual->setCnh(ui->txt_clientes_cnh->text());
            foundCliente = true;
        }
        ++iter;
    }while(iter != dbClientes.end() && !foundCliente);
    if(foundCliente){
        ui->tab_clientes->setCurrentIndex(0);
    }else{
        QMessageBox::warning(this, "Aviso!", "Nenhum cliente encontrado para atualizar!");
    }
}

// Remove um cadastro de cliente
void ModuleSelection::on_btn_clientes_cadastro_exclui_clicked()
{
    int idCliente = ui->lbl_clientes_id->text().toInt();
    bool foundCliente = false;
    QLinkedList<Cliente*>::iterator iter = dbClientes.begin();
    do{
        Cliente *atual = iter.i->t;
        if(atual->getID() == idCliente){
            dbClientes.removeOne(atual);
            foundCliente = true;
        }
        ++iter;
    }while(iter != dbClientes.end() && !foundCliente);
    if(!foundCliente){
        QMessageBox::warning(this, "Aviso!", "Nenhum cliente encontrado para excluir!");
    }else{
        ui->tab_clientes->setCurrentIndex(0);
    }
}
