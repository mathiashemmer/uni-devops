#include "financeiro.h"

unsigned int Financeiro::ID = 0;

unsigned int Financeiro::getIdEnvolvido() const
{
    return idEnvolvido;
}

void Financeiro::setIdEnvolvido(unsigned int value)
{
    idEnvolvido = value;
}

QString Financeiro::getReferente() const
{
    return referente;
}

void Financeiro::setReferente(const QString &value)
{
    referente = value;
}

short Financeiro::getTipo() const
{
    return tipo;
}

void Financeiro::setTipo(short value)
{
    tipo = value;
}

double Financeiro::getValor() const
{
    return valor;
}

void Financeiro::setValor(double value)
{
    valor = value;
}

QDate Financeiro::getData() const
{
    return data;
}

void Financeiro::setData(const QDate &value)
{
    data = value;
}

unsigned int Financeiro::getMeuID() const
{
    return meuID;
}

Financeiro::Financeiro()
{

}

Financeiro::Financeiro(unsigned int idEnvolvido, QString referente, short tipo, double valor, QDate data)
{
    this->idEnvolvido = idEnvolvido;
    this->referente = referente;
    this->tipo = tipo;
    this->valor = valor;
    this->data = data;

    this->meuID = Financeiro::ID;
    AutoInc();
}

bool Financeiro::AutoInc()
{
    ID++;
    return true;
}
