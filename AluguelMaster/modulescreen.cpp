#include "modulescreen.h"
#include "ui_modulescreen.h"

ModuleScreen::ModuleScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModuleScreen)
{
    ui->setupUi(this);
}

ModuleScreen::~ModuleScreen()
{
    delete ui;
}

void ModuleScreen::on_pbtn_Veiculos_clicked()
{

}

void ModuleScreen::on_tabWidget_tabBarDoubleClicked(int index)
{

}
