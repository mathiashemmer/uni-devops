#ifndef MANUTENCAO_H
#define MANUTENCAO_H

#include "contrato.h"

class Manutencao : public Contrato
{
private:
    unsigned int idTerceiro;
public:
    Manutencao();
    unsigned int getIdTerceiro() const;
    void setIdTerceiro(unsigned int value);
};

#endif // MANUTENCAO_H
