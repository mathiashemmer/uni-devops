#include "cliente.h"

QString Cliente::getCnh() const
{
    return cnh;
}

void Cliente::setCnh(const QString &value)
{
    cnh = value;
}

int Cliente::getID() const
{
    return this->myID;
}

Cliente::Cliente()
{

}

Cliente::~Cliente()
{

}
