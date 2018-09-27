#include "cadcarros.h"
#include "ui_cadcarros.h"

CadCarros::CadCarros(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CadCarros)
{
    ui->setupUi(this);
}

CadCarros::~CadCarros()
{
    delete ui;
}
