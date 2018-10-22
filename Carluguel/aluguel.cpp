#include "aluguel.h"

unsigned int Aluguel::getIdCliente() const
{
    return idCliente;
}

void Aluguel::setIdCliente(unsigned int value)
{
    idCliente = value;
}

Aluguel::Aluguel()
{

}

Aluguel::~Aluguel()
{

}

Aluguel::Aluguel(unsigned int idCarro, QDate inicio, QDate fim, unsigned int idCliente, short tipo) : Contrato(idCarro, inicio, fim, tipo)
{
    this->setIdCliente(idCliente);
}

double Aluguel::getValor() const
{
    return this->valor;
}

void Aluguel::setValor(double value, int mod)
{
    double desc = value * ((double)mod/100);
    this->valor = value - desc;
}
