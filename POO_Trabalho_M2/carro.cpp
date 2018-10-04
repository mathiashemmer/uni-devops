#include "carro.h"

int Carro::id = 0;

std::string Carro::getCor() const
{
    return cor;
}

void Carro::setCor(const std::string &value)
{
    cor = value;
}

std::string Carro::getPlaca() const
{
    return placa;
}

void Carro::setPlaca(const std::string &value)
{
    placa = value;
}

int Carro::getID() const
{
    return this->myID;
}

Carro::Carro()
{
    this->myID = Carro::id;
    Carro::id++;
}

Carro::~Carro()
{

}
