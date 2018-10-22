#include "contrato.h"

unsigned int Contrato::ID = 0;

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

void Contrato::setTipo(const short &value)
{
    tipo = value;
}

short Contrato::getTipo() const
{
    return tipo;
}

bool Contrato::AutoInc()
{
    ID++;
    return true;
}

Contrato::Contrato()
{
    AutoInc();
}

Contrato::~Contrato()
{

}

Contrato::Contrato(unsigned int idCarro, QDate inicio, QDate fim, short tipo)
{
    this->setIdCarro(idCarro);
    this->setInicio(inicio);
    this->setFim(fim);
    this->setTipo(tipo);

    this->meuID = Contrato::ID;
    AutoInc();
}
