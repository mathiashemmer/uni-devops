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

bool Cliente::AutoInc()
{
    ID++;
    return true;
}

Cliente::Cliente(Endereco endereco, QString nome, QString CPF, QDate nacimento, ConceitoCliente conceito)
{
    Pessoa(endereco, nome, CPF, nacimento);
    this->conceito = conceito;
    meuID = ID;
    AutoInc();
}

Cliente::~Cliente()
{

}
