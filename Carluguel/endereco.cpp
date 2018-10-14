#include "endereco.h"

int Endereco::getNumero() const
{
    return numero;
}

void Endereco::setNumero(int value)
{
    numero = value;
}

int Endereco::getCEP() const
{
    return CEP;
}

void Endereco::setCEP(int value)
{
    CEP = value;
}

QString Endereco::getRua() const
{
    return rua;
}

void Endereco::setRua(const QString &value)
{
    rua = value;
}

QString Endereco::getBairro() const
{
    return bairro;
}

void Endereco::setBairro(const QString &value)
{
    bairro = value;
}

QString Endereco::getCidade() const
{
    return cidade;
}

void Endereco::setCidade(const QString &value)
{
    cidade = value;
}

Endereco::Endereco()
{

}
