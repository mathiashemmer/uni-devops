#include "cad_carros.h"
#include "ui_cad_carros.h"

cad_carros::cad_carros(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cad_carros)
{
    ui->setupUi(this);
}

cad_carros::~cad_carros()
{
    delete ui;
}
