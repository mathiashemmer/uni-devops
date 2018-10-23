#include "modulescreen.h"
#include "ui_modulescreen.h"
#include <QMessageBox>

ModuleScreen::ModuleScreen(QWidget *parent) : QDialog(parent), ui(new Ui::ModuleScreen)
{
    ui->setupUi(this);

    // Preenche listas com valores arbritratios
    dbCarros.append(new Carro(100,0, "A45T", "AMM-2019", "Volkswagen - Golf GTI", "asd", 1, StatusCarro::Disponivel));
    dbCarros.append(new Carro(50,0, "B67R", "MCJ-2819", "Volkswagen - Polo", "asd", 1, StatusCarro::Disponivel));
    dbCarros.append(new Carro(85,0, "C11C", "QIU-1291", "Volkswagen - Gol", "asd", 1, StatusCarro::Disponivel));

    Endereco endereco;
    QDate data = QDate::currentDate();
    dbClientes.append(new Cliente(endereco, "Roberto", "1234567899", data, ConceitoCliente::Ruim));
    dbClientes.append(new Cliente(endereco, "Alex", "987654321", data, ConceitoCliente::Mediano));
    dbClientes.append(new Cliente(endereco, "Cleberson", "159753", data, ConceitoCliente::Otimo));

    dbFinanceiro.append(new Financeiro(5, "aluguel tal", 0, 195.23, QDate::currentDate()));
    dbFinanceiro.append(new Financeiro(3, "coisa doida", 1, 333.33, QDate::currentDate()));


    // Setup das listas-----------------------

    //Carros
    ui->tbl_carros_registros->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tbl_carros_registros->setColumnWidth(0, 25);
    ui->tbl_carros_registros->verticalHeader()->setDefaultSectionSize(24);
    ui->tbl_carros_registros->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    //Clientes
    ui->tbl_clientes_registros->setColumnWidth(0, 25);
    ui->tbl_clientes_registros->setColumnWidth(1, 325);
    ui->tbl_clientes_registros->setColumnWidth(2, 175);
    ui->tbl_clientes_registros->verticalHeader()->setDefaultSectionSize(24);
    ui->tbl_clientes_registros->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //Contratos
    ui->tbl_contratos_registros->verticalHeader()->setDefaultSectionSize(24);
    ui->tbl_contratos_registros->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //Financeiro

    CarregaListaCarros();
    CarregaListaClientes();
    CarregaListaContratos();
    CarregaListaFinanceiro();
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
    auto iter = dbCarros.begin();
    while(iter != dbCarros.end()){
        atual = iter.i->t;
        if(atual->getMeuID() == idCarro){
            break;
        }
        ++iter;
    }
    if(atual != nullptr){
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

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
// CLIENTES
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//


void ModuleScreen::CarregaListaClientes()
{
    unsigned short mask[2] = {0, 0};
    QString fNome;
    int fConceito = -1;
    (fNome = ui->txt_clientes_registros_filtro_nome->text()).length() > 1 ? mask[0] = 1 : mask[0] = 1;
    (fConceito = ui->cbx_clientes_registros_filtro_conceito->currentIndex() -1) >= 0 ? mask[1] = 1 : mask[1] = 0;

    int filtro = mask[0] + mask[1]*2;

    ui->tbl_clientes_registros->setRowCount(0);

    QLinkedList<Cliente> filteredList;
    auto iter = dbClientes.begin();
    Cliente *atual = nullptr;
    while(iter != dbClientes.end()){
        atual = iter.i->t;
        switch (filtro) {
        case 0: // Sem filtro
            filteredList.append(*atual);
            break;
        case 1: // Filtro por [nome]
            if(atual->getNome().contains(fNome)){
                filteredList.append(*atual);
            }
            break;
        case 2: // Filtro por [conceito]
            if(atual->getConceito() == fConceito){
                filteredList.append(*atual);
            }
            break;
        case 3: // Filtro por [nome] [conceito]
            if(atual->getNome().contains(fNome) && atual->getConceito() == fConceito){
                filteredList.append(*atual);
            }
            break;
        }
        ++iter;
    }
    auto filteredIter = filteredList.begin();
    auto tabela = ui->tbl_clientes_registros;
    while(filteredIter != filteredList.end()){
        Cliente atual = filteredIter.i->t;
        int curRow = tabela->rowCount();
        tabela->insertRow(curRow);
        tabela->setItem(curRow, 0, new QTableWidgetItem(QString::number(atual.getMeuID())));
        tabela->setItem(curRow, 1, new QTableWidgetItem(atual.getNome()));
        tabela->setItem(curRow, 2, new QTableWidgetItem(atual.getCPF()));
        tabela->setItem(curRow, 3, new QTableWidgetItem(
                            atual.getConceito() == 0 ? "Ruim" :
                            atual.getConceito() == 1 ? "Mediano" :
                            atual.getConceito() == 2 ? "Bom" : "Otimo"));
        ++filteredIter;
    }
}

void ModuleScreen::AjustaPadraoEntradaClientes()
{

}

void ModuleScreen::on_tab_clientes_currentChanged(int index)
{
    if(index == 0){
        CarregaListaClientes();
    }
}

void ModuleScreen::on_tbl_clientes_registros_cellDoubleClicked(int row, int column)
{
    unsigned int codigo = ui->tbl_clientes_registros->item(row, 0)->text().toUInt();
    auto iter = dbClientes.begin();
    bool found = false;
    Cliente *atual = nullptr;
    while(iter != dbClientes.end() && !found){
        if(iter.i->t->getMeuID() == codigo){
            atual = iter.i->t;
            found = true;
        }
        ++iter;
    }
    if(found){
        ui->tab_clientes->setCurrentIndex(1);
        ui->lbl_clientes_cadastro_id->setText(QString::number(atual->getMeuID()));
        ui->txt_clientes_cadastro_nome->setText(atual->getNome());
        ui->txt_clientes_cadastro_CPF->setText(atual->getCPF());
        ui->txt_clientes_cadastro_rua->setText(atual->getEndereco().getRua());
        ui->txt_clientes_registro_bairro->setText(atual->getEndereco().getBairro());
        ui->txt_clientes_registro_cidade->setText(atual->getEndereco().getCidade());
        ui->dtf_clientes_cadastro_nascimento->setDate(atual->getDataNacimento());
        ui->sbx_clientes_cadastro_CEP->setValue(atual->getEndereco().getCEP());
        ui->sbx_clientes_cadastro_numero->setValue(atual->getEndereco().getNumero());
        ui->cb_clientes_cadastro_conceito->setCurrentIndex(atual->getConceito());
        ui->sbx_clientes_cadastro_desconto->setValue(atual->getPercDesc());
        ui->lbl_clientes_cadastro_conceito_display->setText(
                    atual->getConceito() == 0 ? "Ruim" :
                    atual->getConceito() == 1 ? "Mediano" :
                    atual->getConceito() == 2 ? "Bom" : "Ótimo");
    }
}

void ModuleScreen::on_btn_clientes_cadastro_gravar_clicked()
{
    unsigned int codigo = ui->lbl_clientes_cadastro_id->text().toUInt();
    auto iter = dbClientes.begin();
    bool found = false;
    Cliente *atual = nullptr;
    while(iter != dbClientes.end() && !found){
        if(iter.i->t->getMeuID() == codigo){
            atual = iter.i->t;
            found = true;
        }
        ++iter;
    }
    if(found){
        atual->setConceito((ConceitoCliente)ui->cb_clientes_cadastro_conceito->currentIndex());
        atual->setCPF(ui->txt_clientes_cadastro_CPF->text());
        atual->setDataNacimento(ui->dtf_clientes_cadastro_nascimento->date());
        atual->setNome(ui->txt_clientes_cadastro_nome->text());
        atual->setPercDesc(ui->sbx_clientes_cadastro_desconto->value());
        Endereco novoEndereco;

        novoEndereco.setBairro(ui->txt_clientes_registro_bairro->text());
        novoEndereco.setCEP(ui->sbx_clientes_cadastro_CEP->value());
        novoEndereco.setCidade(ui->txt_clientes_registro_cidade->text());
        novoEndereco.setNumero(ui->sbx_clientes_cadastro_numero->value());
        novoEndereco.setRua(ui->txt_clientes_cadastro_rua->text());

        atual->setEndereco(novoEndereco);
    }
    ui->tab_clientes->setCurrentIndex(0);
}

void ModuleScreen::on_btn_clientes_cadastro_novo_clicked()
{
    Endereco novoEndereco;

    novoEndereco.setBairro(ui->txt_clientes_registro_bairro->text());
    novoEndereco.setCEP(ui->sbx_clientes_cadastro_CEP->value());
    novoEndereco.setCidade(ui->txt_clientes_registro_cidade->text());
    novoEndereco.setNumero(ui->sbx_clientes_cadastro_numero->value());
    novoEndereco.setRua(ui->txt_clientes_cadastro_rua->text());

    Cliente *atual = new Cliente(
                novoEndereco,
                ui->txt_clientes_cadastro_nome->text(),
                ui->txt_clientes_cadastro_CPF->text(),
                ui->dtf_clientes_cadastro_nascimento->date(),
                (ConceitoCliente)ui->cb_clientes_cadastro_conceito->currentIndex()
                );
    atual->setPercDesc(ui->sbx_clientes_cadastro_desconto->value());
    dbClientes.append(atual);
    ui->tab_clientes->setCurrentIndex(0);
}

void ModuleScreen::on_btn_clientes_cadastro_excluir_clicked()
{
    unsigned int codigo = ui->lbl_clientes_cadastro_id->text().toUInt();
    auto iter = dbClientes.begin();
    bool found = false;
    Cliente *atual = nullptr;
    while(iter != dbClientes.end() && !found){
        if(iter.i->t->getMeuID() == codigo){
            atual = iter.i->t;
            found = true;
        }
        ++iter;
    }
    if(found && atual != nullptr){
        dbClientes.removeOne(atual);
    }
    ui->tab_clientes->setCurrentIndex(0);
}

void ModuleScreen::on_txt_clientes_registros_filtro_nome_textChanged(const QString &arg1)
{
    CarregaListaClientes();
}

void ModuleScreen::on_cbx_clientes_registros_filtro_conceito_currentIndexChanged(int index)
{
    CarregaListaClientes();
}

////////////////////////////////////////
// CONTRATOS - ALUGUEIS E MANUTENÇÕES //
////////////////////////////////////////

void ModuleScreen::AjustaPadraoEntradaContratos()
{
    QDate data = QDate::currentDate();
    ui->de_contratos_cadastro_inicio->setDate(data);
    data.setDate(data.year(), data.month(), data.day() + 1);
    ui->de_contratos_cadastro_fim->setDate(data);
    ui->txt_contratos_cadastro_idPartic->setText("");
    ui->txt_contratos_cadastro_idCarros->setText("");
    ui->cb_contratos_cadastro_tipo->setCurrentIndex(0);
    ui->dsb_contratos_cadastro_valor->setValue(0.00);
}

void ModuleScreen::on_tab_contratos_currentChanged(int index)
{
    if(index == 0)
    {
        AjustaPadraoEntradaContratos();
    }
}

void ModuleScreen::on_btn_contratos_cadastro_novo_clicked()
{
    if(ui->cb_contratos_cadastro_tipo->currentIndex() == 0) {

        auto idCliente = ui->txt_contratos_cadastro_idPartic->text().toUInt();
        Cliente *atual = nullptr;
        auto iter = dbClientes.begin();
        while(iter != dbClientes.end()){
            if(iter.i->t->getMeuID() == idCliente)
                atual = iter.i->t;
            ++iter;
        }
        if(atual==nullptr){
            QMessageBox::warning(this, "Aviso!", "Cliente não encontrado!");
            return;
        }
        Aluguel *novoAluguel = new Aluguel(
                    ui->txt_contratos_cadastro_idCarros->text().toUInt(),
                    ui->de_contratos_cadastro_inicio->date(),
                    ui->de_contratos_cadastro_fim->date(),
                    idCliente,
                    0
        );
        novoAluguel->setValor(ui->dsb_contratos_cadastro_valor->value(), atual->getPercDesc());
        if(novoAluguel != nullptr)
            dbAlugueis.append(novoAluguel);
    } else if(ui->cb_contratos_cadastro_tipo->currentIndex() == 1) {
        Manuten *novaManuten = new Manuten(
                    ui->txt_contratos_cadastro_idCarros->text().toUInt(),
                    ui->de_contratos_cadastro_inicio->date(),
                    ui->de_contratos_cadastro_fim->date(),
                    ui->txt_contratos_cadastro_idPartic->text().toUInt(),
                    1
        );
        novaManuten->setValor(ui->dsb_contratos_cadastro_valor->value(), 0);
        if(novaManuten != nullptr)
            dbManuten.append(novaManuten);
    }
    ui->tab_contratos->setCurrentIndex(0);
    CarregaListaContratos();
}

void ModuleScreen::CarregaListaContratos()
{

    ui->tbl_contratos_registros->setRowCount(0);
    auto tabela = ui->tbl_contratos_registros;
    auto iter = dbAlugueis.begin();
    Aluguel *atual = nullptr;
    while(iter != dbAlugueis.end()) {
        atual = iter.i->t;
        int curRow = tabela->rowCount();
        tabela->insertRow(curRow);
        tabela->setItem(curRow, 0, new QTableWidgetItem(QString::number(atual->getMeuID())));
        tabela->setItem(curRow, 1, new QTableWidgetItem(QString::number(atual->getIdCliente())));
        tabela->setItem(curRow, 2, new QTableWidgetItem(QString::number(atual->getIdCarro())));
        tabela->setItem(curRow, 3, new QTableWidgetItem(
                            atual->getTipo() == 0 ? "Aluguel" : "Manutenção"));
        tabela->setItem(curRow, 4, new QTableWidgetItem(QString::number(atual->getValor())));
        tabela->setItem(curRow, 5, new QTableWidgetItem(atual->getInicio().toString("yyyy.MM.dd")));
        tabela->setItem(curRow, 6, new QTableWidgetItem(atual->getFim().toString("yyyy.MM.dd")));
        ++iter;
    }

    auto iter2 = dbManuten.begin();
    Manuten *atual2 = nullptr;
    while(iter2 != dbManuten.end()) {
        atual2 = iter2.i->t;
        int curRow = tabela->rowCount();
        tabela->insertRow(curRow);
        tabela->setItem(curRow, 0, new QTableWidgetItem(QString::number(atual2->getMeuID())));
        tabela->setItem(curRow, 1, new QTableWidgetItem(QString::number(atual2->getIdTerceiro())));
        tabela->setItem(curRow, 2, new QTableWidgetItem(QString::number(atual2->getIdCarro())));
        tabela->setItem(curRow, 3, new QTableWidgetItem(
                            atual2->getTipo() == 0 ? "Aluguel" : "Manutenção"));
        tabela->setItem(curRow, 4, new QTableWidgetItem(QString::number(atual2->getValor())));
        tabela->setItem(curRow, 5, new QTableWidgetItem(atual->getInicio().toString("dd.MM.yyyy")));
        tabela->setItem(curRow, 6, new QTableWidgetItem(atual->getFim().toString("dd.MM.yyyy")));
        ++iter2;
    }
}

///////////////////////////////////////////
// FINANCEIRO - CONTAS A PAGAR E RECEBER //
///////////////////////////////////////////


void ModuleScreen::AjustaPadraoEntradaFinanceiro()
{
    QDate data = QDate::currentDate();
    ui->txt_financeiro_cadastro_envolvido->setText("");
    ui->txt_financeiro_cadastro_referente->setText("");
    ui->cb_financeiro_cadastro_tipo->setCurrentIndex(0);
    ui->dsb_financeiro_cadastro_valor->setValue(150.00);
    ui->de_financeiro_cadastro_datapag->setDate(data);
    ui->de_contratos_cadastro_inicio->setDate(data);
}

void ModuleScreen::on_tab_financeiro_currentChanged(int index)
{
    if(index == 0)
    {
        AjustaPadraoEntradaFinanceiro();
    }
}

void ModuleScreen::CarregaListaFinanceiro()
{

    ui->tbl_financeiro_registros->setRowCount(0);
    auto tabela = ui->tbl_financeiro_registros;
    auto iter = dbFinanceiro.begin();
    Financeiro *atual = nullptr;
    while(iter != dbFinanceiro.end()) {
        atual = iter.i->t;
        int curRow = tabela->rowCount();
        tabela->insertRow(curRow);
        tabela->setItem(curRow, 0, new QTableWidgetItem(QString::number(atual->getMeuID())));
        tabela->setItem(curRow, 1, new QTableWidgetItem(QString::number(atual->getIdEnvolvido())));
        tabela->setItem(curRow, 2, new QTableWidgetItem(atual->getReferente()));
        tabela->setItem(curRow, 3, new QTableWidgetItem(
                            atual->getTipo() == 0 ? "A Receber" : "Pagamento"));
        tabela->setItem(curRow, 4, new QTableWidgetItem(QString::number(atual->getValor())));
        tabela->setItem(curRow, 5, new QTableWidgetItem(atual->getData().toString("dd.MM.yyyy")));
        ++iter;
    }
}

void ModuleScreen::on_btn_financeiro_cadastro_novo_clicked()
{
    Financeiro *novaConta = new Financeiro(
                ui->txt_financeiro_cadastro_envolvido->text().toUInt(),
                ui->txt_financeiro_cadastro_referente->text(),
                ui->cb_financeiro_cadastro_tipo->currentIndex(),
                ui->dsb_financeiro_cadastro_valor->value(),
                ui->de_financeiro_cadastro_datapag->date()
    );
    if(novaConta != nullptr)
        dbFinanceiro.append(novaConta);
    ui->tab_financeiro->setCurrentIndex(0);
    CarregaListaFinanceiro();
}

void ModuleScreen::on_tbl_financeiro_registros_cellDoubleClicked(int row, int column)
{
    unsigned int codigo = ui->tbl_financeiro_registros->item(row, 0)->text().toUInt();
    auto iter = dbFinanceiro.begin();
    bool found = false;
    Financeiro *atual = nullptr;
    while(iter != dbFinanceiro.end() && !found){
        if(iter.i->t->getMeuID() == codigo){
            atual = iter.i->t;
            found = true;
        }
        ++iter;
    }
    if(found){
        ui->tab_financeiro->setCurrentIndex(1);
        ui->lbl_financeiro_cadastro_id->setText(QString::number(atual->getMeuID()));
        ui->txt_financeiro_cadastro_envolvido->setText(QString::number(atual->getIdEnvolvido()));
        ui->txt_financeiro_cadastro_referente->setText(atual->getReferente());
        ui->cb_financeiro_cadastro_tipo->setCurrentIndex(atual->getTipo());
        ui->dsb_financeiro_cadastro_valor->setValue(atual->getValor());
        ui->de_financeiro_cadastro_datapag->setDate(atual->getData());
    }
}

void ModuleScreen::on_btn_financeiro_cadastro_excluir_clicked()
{
    unsigned int codigo = ui->lbl_financeiro_cadastro_id->text().toUInt();
    auto iter = dbFinanceiro.begin();
    bool found = false;
    Financeiro *atual = nullptr;
    while(iter != dbFinanceiro.end() && !found){
        if(iter.i->t->getMeuID() == codigo){
            atual = iter.i->t;
            found = true;
        }
        ++iter;
    }
    if(found && atual != nullptr){
        dbFinanceiro.removeOne(atual);
    }
    CarregaListaFinanceiro();
    ui->tab_financeiro->setCurrentIndex(0);
}
