#include "carro.h"

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

Carro::Carro()
{

}

Carro::~Carro()
{

}
