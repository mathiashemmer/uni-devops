#ifndef MANUTEN_H
#define MANUTEN_H

#include "contrato.h"

class Manuten : public Contrato
{
private:
    unsigned int idTerceiro;
public:
    Manuten();
    ~Manuten();
    Manuten(unsigned int idCarro, double valor, QDate inicio, QDate fim, unsigned int idTerceiro);
    unsigned int getIdTerceiro() const;
    void setIdTerceiro(unsigned int value);
};

#endif // MANUTEN_H
