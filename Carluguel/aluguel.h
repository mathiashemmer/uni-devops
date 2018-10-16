#ifndef ALUGUEL_H
#define ALUGUEL_H

#include "contrato.h"

class Aluguel : public Contrato
{
private:
    int meuID;
    int idCliente;
public:
    static int ID;
    bool static AutoInc();
    Aluguel();
};

#endif // ALUGUEL_H
