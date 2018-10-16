#include "modulescreen.h"
#include "ui_modulescreen.h"
#include <QMessageBox>

ModuleScreen::ModuleScreen(QWidget *parent) : QDialog(parent), ui(new Ui::ModuleScreen)
{
    ui->setupUi(this);

    // Preenche listas com valores arbritratios
    dbCarros.append(new Carro(100,0, "T", "AMM", "A", "asd", 1, StatusCarro::Disponivel));
    dbCarros.append(new Carro(50,0, "T", "AMM", "A", "asd", 1, StatusCarro::Disponivel));
    dbCarros.append(new Carro(20,0, "T", "AMM", "B", "asd", 1, StatusCarro::Disponivel));
    dbCarros.append(new Carro(35,0, "T", "AMM", "B", "asd", 1, StatusCarro::Disponivel));
    dbCarros.append(new Carro(99,0, "T", "AMM", "C", "asd", 1, StatusCarro::Disponivel));
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

// Auxiliar para resetar a UI;
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

// Reseta registros nos campos
void ModuleScreen::on_tab_carros_currentChanged(int index)
{
    // Reseta registros nos campos(Precisa ser no index 0, pois se o usuário já está no 0 e troca para o 1, não pode
    // resetar, caso contrário o sistema não ira carregar nenhum cadastro
    if(index == 0){
        AjustaPadraoEntradaCarros();
    }
}

// Carrega toda a lista de carros, com ou sem filtro
void ModuleScreen::CarregaListaCarros(){
    unsigned short mask[2] = {0, 0};

    QString fModelo = "";
    int fStatus = -1;

    (fModelo = ui->txt_carros_registros_filtro_modelo->text()).size() >= 1 ? mask[0] = 1 : mask[0] = 0;
    (fStatus = ui->cbx_carros_registros_filtro_status->currentIndex() -1) >= 0 ? mask[1] = 1 : mask[1] = 0;

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
            atual.getDisponibilidade() == 0 ? "Alugado" :
            atual.getDisponibilidade() == 1 ? "Disponivel" : "Manutenção")));
        carTable->setItem(curRow, 2, new QTableWidgetItem(atual.getModelo()));
        carTable->setItem(curRow, 3, new QTableWidgetItem(QString::number(atual.getCor())));
        carTable->setItem(curRow, 4, new QTableWidgetItem(atual.getPlaca()));
        carTable->setItem(curRow, 5, new QTableWidgetItem(atual.getChassi()));
        carTable->setItem(curRow, 6, new QTableWidgetItem(QString::number(atual.getKmAtual())));
        ++filteredIter;
    }
}

// Atualiza filtros
void ModuleScreen::on_btn_carros_registros_filtro_aplicar_clicked()
{
    CarregaListaCarros();
}

void ModuleScreen::on_cbx_carros_registros_filtro_status_currentIndexChanged(const QString &arg1)
{
    CarregaListaCarros();
}

void ModuleScreen::on_txt_carros_registros_filtro_modelo_textChanged(const QString &arg1)
{
    CarregaListaCarros();
}
// Traz os dados do cadastro selecionado
void ModuleScreen::on_tbl_carros_registros_cellDoubleClicked(int row, int column)
{
    AjustaPadraoEntradaCarros();
    unsigned int idCarro = ui->tbl_carros_registros->item(row, 0)->text().toUInt();
    ui->lbl_carros_cadastro_id->setText(QString::number(idCarro));

    Carro *atual = nullptr;
    QLinkedList<Carro*>::Iterator iter = dbCarros.begin();
    while(iter != dbCarros.end()){
        atual = iter.i->t;
        if(atual->getMeuID() == idCarro){
            break;
        }
        ++iter;
    }
    if(atual != nullptr){
       //😋🐦🌂🥃⛱📦📁🇩🇪
        ui->tab_carros->setCurrentIndex(1);
        ui->cbx_carros_cadstro_cor->setCurrentIndex(atual->getCor());
        ui->cbx_carros_cadstro_status->setCurrentIndex(atual->getDisponibilidade());
        ui->txt_carros_cadastro_chassi->setText(atual->getChassi());
        ui->txt_carros_cadastro_kmatual->setText(QString::number(atual->getKmAtual()));
        ui->lcd_carros_cadastro_kmatual->display(atual->getKmAtual());
        ui->txt_carros_cadastro_kmrev->setText(QString::number(atual->getKmRev()));
        ui->txt_carros_cadastro_modelo->setText(atual->getModelo());
        ui->txt_carros_cadastro_placa->setText(atual->getPlaca());
        ui->rtx_carros_cadastro_observacao->setText(atual->getObservacao());
    }

}

// Gravar alterações
void ModuleScreen::on_btn_carros_cadastro_gravar_clicked()
{
    //Carro(int kmAtual, int kmRev, QString chassi, QString placa, QString modelo, QString obs, int cor, StatusCarro disp);
    unsigned int idCarro = ui->lbl_carros_cadastro_id->text().toUInt();
    Carro *atual = nullptr;
    QLinkedList<Carro*>::Iterator iter = dbCarros.begin();
    while(iter != dbCarros.end()){
        atual = iter.i->t;
        if(atual->getMeuID() == idCarro){
            break;
        }
        ++iter;
    }
    if(atual != nullptr){
        atual->setChassi(ui->txt_carros_cadastro_chassi->text());
        atual->setCor((Cor)ui->cbx_carros_cadstro_cor->currentIndex());
        atual->setDisponibilidade((StatusCarro)ui->cbx_carros_cadstro_status->currentIndex());
        atual->setKmAtual(ui->txt_carros_cadastro_kmatual->text().toInt());
        atual->setKmRev(ui->txt_carros_cadastro_kmrev->text().toInt());
        atual->setModelo(ui->txt_carros_cadastro_modelo->text());
        atual->setObservacao(ui->rtx_carros_cadastro_observacao->toPlainText());
        atual->setPlaca(ui->txt_carros_cadastro_placa->text());
    }
    ui->tab_carros->setCurrentIndex(0);
    CarregaListaCarros();
}
// Incluir novo registro
void ModuleScreen::on_btn_carros_cadastro_novo_clicked(bool checked)
{
    Carro* novoCarro = new Carro(
                ui->txt_carros_cadastro_kmatual->text().toInt(),
                ui->txt_carros_cadastro_kmrev->text().toInt(),
                ui->txt_carros_cadastro_chassi->text(),
                ui->txt_carros_cadastro_placa->text(),
                ui->txt_carros_cadastro_modelo->text(),
                ui->rtx_carros_cadastro_observacao->toPlainText(),
                ui->cbx_carros_cadstro_cor->currentIndex(),
                (StatusCarro)ui->cbx_carros_cadstro_status->currentIndex()
    );
    if(novoCarro != nullptr){
        dbCarros.append(novoCarro);
    }
    ui->tab_carros->setCurrentIndex(0);
    CarregaListaCarros();
}

// Excluir registro
void ModuleScreen::on_btn_carros_cadastro_excluir_clicked()
{
    unsigned int idCarro = ui->lbl_carros_cadastro_id->text().toUInt();
    Carro *atual = nullptr;
    QLinkedList<Carro*>::Iterator iter = dbCarros.begin();
    while(iter != dbCarros.end()){
        atual = iter.i->t;
        if(atual->getMeuID() == idCarro){
            break;
        }
        ++iter;
    }
    dbCarros.removeOne(atual);
    ui->tab_carros->setCurrentIndex(0);
    CarregaListaCarros();
}

