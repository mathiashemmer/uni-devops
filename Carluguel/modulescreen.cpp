#include "modulescreen.h"
#include "ui_modulescreen.h"
#include <QMessageBox>

ModuleScreen::ModuleScreen(QWidget *parent) : QDialog(parent), ui(new Ui::ModuleScreen)
{
    ui->setupUi(this);

    // Preenche listas com valores arbritratios
    dbCarros.append(new Carro(0,0, "T", "AMM", "A", "asd", 1, StatusCarro::Disponivel));
    dbCarros.append(new Carro(0,0, "T", "AMM", "A", "asd", 1, StatusCarro::Disponivel));
    dbCarros.append(new Carro(0,0, "T", "AMM", "B", "asd", 1, StatusCarro::Disponivel));
    dbCarros.append(new Carro(0,0, "T", "AMM", "B", "asd", 1, StatusCarro::Disponivel));
    dbCarros.append(new Carro(0,0, "T", "AMM", "C", "asd", 1, StatusCarro::Disponivel));
    dbCarros.append(new Carro(0,0, "T", "AMM", "C", "asd", 1, StatusCarro::Alugado));
    dbCarros.append(new Carro(0,0, "T", "AMM", "C", "asd", 1, StatusCarro::Alugado));
    dbCarros.append(new Carro(0,0, "T", "AMM", "A", "asd", 1, StatusCarro::Alugado));
    dbCarros.append(new Carro(0,0, "T", "AMM", "A", "asd", 1, StatusCarro::Alugado));
    dbCarros.append(new Carro(0,0, "T", "AMM", "A", "asd", 1, StatusCarro::Alugado));



    // Setup das listas
    ui->tbl_carros_registros->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tbl_carros_registros->setColumnWidth(0, 25);
    ui->tbl_carros_registros->verticalHeader()->setDefaultSectionSize(24);
    CarregaListaCarros();
}

ModuleScreen::~ModuleScreen()
{
    delete ui;
}

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
// CARROS
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//


void ModuleScreen::AjustaPadraoEntradaCarros(){
    ui->txt_carros_cadastro_chassi->setText("");
    ui->txt_carros_cadastro_kmatual->setText("");
    ui->txt_carros_cadastro_kmrev->setText("");
    ui->txt_carros_cadastro_modelo->setText("");
    ui->txt_carros_cadastro_placa->setText("");
    ui->cbx_carros_cadstro_cor->setCurrentIndex(0);
    ui->cbx_carros_cadstro_status->setCurrentIndex(1);
    ui->txt_carros_registros_filtro_modelo->setText("");
    ui->cbx_carros_registros_filtro_status->setCurrentIndex(0);
}

void ModuleScreen::on_tab_carros_currentChanged(int index)
{
    // Reseta registros nos campos(Precisa ser no index 0, pois se o usuário já está no 0 e troca para o 1, não pode
    // resetar, caso contrário o sistema não ira carregar nenhum cadastro
    if(index == 0){
        AjustaPadraoEntradaCarros();
    }
}

void ModuleScreen::CarregaListaCarros(){
    unsigned short mask[2] = {0, 0};

    QString fModelo = "";
    int fStatus = 0;

    (fModelo = ui->txt_carros_registros_filtro_modelo->text()).size() >= 1 ? mask[0] = 1 : mask[0] = 0;
    (fStatus = ui->cbx_carros_registros_filtro_status->currentIndex()) != 0 ? mask[1] = 1 : mask[1] = 0;

    int maskR = mask[0] + mask[1]*2;

    ui->tbl_carros_registros->setRowCount(0);

    QLinkedList<Carro*>::Iterator iter = this->dbCarros.begin();
    QLinkedList<Carro> filteredList;
    // Primeira passada, busca os registros que irão para a lista
    while(iter != this->dbCarros.end()){
        Carro* atual = iter.i->t;
        switch (maskR) {
        case 0: // Sem filtro
            filteredList.append(*atual);
            break;
        case 1: // Filtro [Modelo]
            if(atual->getModelo().contains(fModelo)){
                filteredList.append(*atual);
            }
            break;
        case 2: // Filtro [Status]
            if(atual->getDisponibilidade() == fStatus){
                filteredList.append(*atual);
            }
            break;
        case 3: // Filtro [Modelo][Status]
            if(atual->getModelo().contains(fModelo) && atual->getDisponibilidade() == fStatus){
                filteredList.append(*atual);
            }
            break;
        }
        ++iter;
    }
    // Segunda passada, preenche a lista com as informações dos registros
    QLinkedList<Carro>::Iterator filteredIter = filteredList.begin();
    auto carTable = ui->tbl_carros_registros;

    while(filteredIter != filteredList.end()){
        Carro atual = filteredIter.i->t;
        int curRow =carTable->rowCount();
        carTable->insertRow(curRow);
        carTable->setItem(curRow, 0, new QTableWidgetItem(QString::number(atual.getMeuID())));
        carTable->setItem(curRow, 1, new QTableWidgetItem(QString::fromStdString(
            atual.getDisponibilidade() == 1 ? "Alugado" :
            atual.getDisponibilidade() == 2 ? "Disponivel" : "Manutenção")));
        carTable->setItem(curRow, 2, new QTableWidgetItem(atual.getModelo()));
        carTable->setItem(curRow, 3, new QTableWidgetItem(QString::number(atual.getCor())));
        carTable->setItem(curRow, 4, new QTableWidgetItem(atual.getPlaca()));
        carTable->setItem(curRow, 5, new QTableWidgetItem(atual.getChassi()));
        carTable->setItem(curRow, 6, new QTableWidgetItem(QString::number(atual.getKmAtual())));
        ++filteredIter;
    }
}

void ModuleScreen::on_btn_carros_registros_filtro_aplicar_clicked()
{
    CarregaListaCarros();
}

void ModuleScreen::on_cbx_carros_registros_filtro_status_currentIndexChanged(const QString &arg1)
{
    CarregaListaCarros();
}

void ModuleScreen::on_tbl_carros_registros_cellDoubleClicked(int row, int column)
{
    AjustaPadraoEntradaCarros();
    int idCarro = ui->tbl_carros_registros->item(row, 0)->text().toInt();
    ui->lbl_carros_cadastro_id->setText(QString::number(idCarro));

    Carro *atual;
}
