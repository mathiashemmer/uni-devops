#include "cliente.h"

unsigned int Cliente::ID = 0;

ConceitoCliente Cliente::getConceito() const
{
    return conceito;
}

void Cliente::setConceito(const ConceitoCliente &value)
{
    conceito = value;
}

unsigned int Cliente::getMeuID() const
{
    return meuID;
}

int Cliente::getPercDesc() const
{
    return percDesc;
}

void Cliente::setPercDesc(int value)
{
    percDesc = value;
}

bool Cliente::AutoInc()
{
    ID++;
    return true;
}

Cliente::Cliente(Endereco endereco, QString nome, QString CPF, QDate nacimento, ConceitoCliente conceito) : Pessoa(endereco, nome, CPF, nacimento)
{
    this->conceito = conceito;
    meuID = ID;
    AutoInc();
}

Cliente::~Cliente()
{

}
