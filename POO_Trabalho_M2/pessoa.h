#ifndef PESSOA_H
#define PESSOA_H

#include <QString>


class Pessoa
{
private:
    int myID;
    QString nome;
    QString rg;
    QString cpf;
    QString nascimento;
    //Endereco endereco;
public:
    static int id;
    Pessoa();
    ~Pessoa();
};

#endif // PESSOA_H
