#include "pessoa.h"

QString Pessoa::getNome() const
{
    return nome;
}

void Pessoa::setNome(const QString &value)
{
    nome = value;
}

QString Pessoa::getCpf() const
{
    return cpf;
}

void Pessoa::setCpf(const QString &value)
{
    cpf = value;
}

QString Pessoa::getRg() const
{
    return rg;
}

void Pessoa::setRg(const QString &value)
{
    rg = value;
}

QString Pessoa::getNascimento() const
{
    return nascimento;
}

void Pessoa::setNascimento(const QString &value)
{
    nascimento = value;
}

Pessoa::Pessoa()
{

}

Pessoa::~Pessoa()
{

}
