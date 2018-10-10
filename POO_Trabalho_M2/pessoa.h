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
    int getMyID() const;
    void setMyID(int value);
    QString getNome() const;
    void setNome(const QString &value);
    QString getRg() const;
    void setRg(const QString &value);
    QString getCpf() const;
    void setCpf(const QString &value);
    QString getNascimento() const;
    void setNascimento(const QString &value);
};

#endif // PESSOA_H
