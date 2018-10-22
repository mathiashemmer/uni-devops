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

Manuten::Manuten(unsigned int idCarro, QDate inicio, QDate fim, unsigned int idTerceiro, short tipo) : Contrato(idCarro, inicio, fim, tipo)
{
    this->setIdTerceiro(idTerceiro);
}

double Manuten::getValor() const
{
    return this->valor;
}

void Manuten::setValor(double value, int mod)
{
    this->valor = value;
}
