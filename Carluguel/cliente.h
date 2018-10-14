#ifndef CLIENTE_H
#define CLIENTE_H
#include <pessoa.h>


class Cliente : public Pessoa
{
private:
    int meuID;

public:
    static int ID;
    Cliente();
};

#endif // CLIENTE_H
