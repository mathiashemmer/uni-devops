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
    int getID() const;
    Aluguel();
    int getIdCliente() const;
    void setIdCliente(int value);
    int getMeuID() const;
};

#endif // ALUGUEL_H
