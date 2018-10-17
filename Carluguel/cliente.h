#ifndef CLIENTE_H
#define CLIENTE_H
#include <pessoa.h>

enum ConceitoCliente{Ruim, Mediano, Bom, Otimo};

class Cliente : public Pessoa
{
private:
    unsigned int meuID;
    ConceitoCliente conceito;
public:
    static unsigned int ID;
    static bool AutoInc();

    Cliente();
    Cliente(Endereco endereco, QString nome, QString CPF, QDate nacimento, ConceitoCliente conceito);
    ~Cliente();
    ConceitoCliente getConceito() const;
    void setConceito(const ConceitoCliente &value);
    unsigned int getMeuID() const;
};

#endif // CLIENTE_H
