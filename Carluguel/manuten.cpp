#include "manuten.h"

unsigned int Manuten::getIdTerceiro() const
{
    return idTerceiro;
}

void Manuten::setIdTerceiro(unsigned int value)
{
    idTerceiro = value;
}

Manuten::Manuten()
{

}

Manuten::~Manuten()
{

}

Manuten::Manuten(unsigned int idCarro, double valor, QDate inicio, QDate fim, unsigned int idTerceiro, short tipo) : Contrato(idCarro, valor, inicio, fim, tipo)
{
    this->setIdTerceiro(idTerceiro);
}
