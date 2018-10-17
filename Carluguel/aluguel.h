#ifndef ALUGUEL_H
#define ALUGUEL_H

#include "contrato.h"

class Aluguel : public Contrato
{
private:
    unsigned int idCliente;
public:
    Aluguel();
    unsigned int getIdCliente() const;
    void setIdCliente(unsigned int value);
};

#endif // ALUGUEL_H
