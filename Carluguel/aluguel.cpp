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

Aluguel::Aluguel(unsigned int idCarro, double valor, QDate inicio, QDate fim, unsigned int idCliente, short tipo) : Contrato(idCarro, valor, inicio, fim, tipo)
{
    this->setIdCliente(idCliente);
}
