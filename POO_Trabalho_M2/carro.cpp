#include "carro.h"

int Carro::id = 0;

QString Carro::getCor() const
{
    return cor;
}

void Carro::setCor(const QString &value)
{
    cor = value;
}

QString Carro::getPlaca() const
{
    return placa;
}

void Carro::setPlaca(const QString &value)
{
    placa = value;
}

int Carro::getID() const
{
    return this->myID;
}

int Carro::getKmAtual() const
{
    return kmAtual;
}

void Carro::setKmAtual(int value)
{
    kmAtual = value;
}

bool Carro::getDisponivel() const
{
    return disponivel;
}

void Carro::setDisponivel(bool value)
{
    disponivel = value;
}

Carro::Carro()
{
    this->myID = Carro::id;
    Carro::id++;
    this->setKmAtual(0);
    this->setDisponivel(true);
}

Carro::~Carro()
{

}
