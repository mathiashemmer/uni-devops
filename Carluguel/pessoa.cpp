#include "Pessoa.h"

Endereco Pessoa::getEndereco() const
{
    return endereco;
}

void Pessoa::setEndereco(const Endereco &value)
{
    endereco = value;
}

QString Pessoa::getNome() const
{
    return nome;
}

void Pessoa::setNome(const QString &value)
{
    nome = value;
}

QString Pessoa::getSobrenome() const
{
    return sobrenome;
}

void Pessoa::setSobrenome(const QString &value)
{
    sobrenome = value;
}

QDate Pessoa::getDataNacimento() const
{
    return dataNacimento;
}

void Pessoa::setDataNacimento(const QDate &value)
{
    dataNacimento = value;
}

QString Pessoa::getCPF() const
{
    return CPF;
}

void Pessoa::setCPF(const QString &value)
{
    CPF = value;
}

Pessoa::Pessoa()
{

}

Pessoa::Pessoa(Endereco endereco, QString nome, QString sobrenome, QString CPF, QDate nacimento)
{
    this->endereco = endereco;
    this->nome = nome;
    this->sobrenome = sobrenome;
    this->CPF = CPF;
    this->dataNacimento = nacimento;
}
