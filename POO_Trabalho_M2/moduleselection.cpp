#include "moduleselection.h"
#include "ui_moduleselection.h"
#include "carro.h"

ModuleSelection::ModuleSelection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModuleSelection)
{
    Carro c1,c2,c3;
    c1.setCor("azul"); c1.setPlaca("MMM");
    c2.setCor("branco"); c2.setPlaca("AAA");
    c3.setCor("preto"); c3.setPlaca("BBB");

    this->dbCarros.append(c1);
    this->dbCarros.append(c2);
    this->dbCarros.append(c3);
    ui->setupUi(this);
}

ModuleSelection::~ModuleSelection()
{
    delete ui;
}

void ModuleSelection::on_btn_carros_clicked()
{
    ui->tab_cadastros->setCurrentIndex(0);
    Carro carro;
    for(int i = 0; i < dbCarros.size(); i++){
        carro = dbCarros.at(i);
        ui->tbl_carros->insertRow(ui->tbl_carros->rowCount());
        ui->tbl_carros->setItem(ui->tbl_carros->rowCount()-1, 0, new QTableWidgetItem(QString::fromStdString(carro.getPlaca())));
        ui->tbl_carros->setItem(ui->tbl_carros->rowCount()-1, 1, new QTableWidgetItem(QString::fromStdString(carro.getCor())));
    }
}

void ModuleSelection::on_btn_clientes_clicked()
{
    ui->tab_cadastros->setCurrentIndex(1);
}

void ModuleSelection::on_btn_contratos_clicked()
{
    ui->tab_cadastros->setCurrentIndex(2);
}

void ModuleSelection::on_btn_financeiro_clicked()
{
    ui->tab_cadastros->setCurrentIndex(3);
}

void ModuleSelection::on_btn_funcionarios_clicked()
{
    ui->tab_cadastros->setCurrentIndex(4);
}
