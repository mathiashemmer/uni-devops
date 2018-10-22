#ifndef ALUGUEL_H
#define ALUGUEL_H

#include "contrato.h"

class Aluguel : public Contrato
{
private:
    unsigned int idCliente;
public:
    Aluguel();
    ~Aluguel();
    Aluguel(unsigned int idCarro, QDate inicio, QDate fim, unsigned int idCliente, short tipo);
    double getValor() const;
    void setValor(double value, int mod);
    unsigned int getIdCliente() const;
    void setIdCliente(unsigned int value);
};

#endif // ALUGUEL_H
