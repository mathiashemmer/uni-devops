#include "contrato.h"

unsigned int Contrato::getMeuID() const
{
    return meuID;
}

unsigned int Contrato::getIdCarro() const
{
    return idCarro;
}

void Contrato::setIdCarro(unsigned int value)
{
    idCarro = value;
}

double Contrato::getValor() const
{
    return valor;
}

void Contrato::setValor(double value)
{
    valor = value;
}

QDate Contrato::getInicio() const
{
    return inicio;
}

void Contrato::setInicio(const QDate &value)
{
    inicio = value;
}

QDate Contrato::getFim() const
{
    return fim;
}

void Contrato::setFim(const QDate &value)
{
    fim = value;
}

Contrato::Contrato()
{
    
}
