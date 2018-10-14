#ifndef PESSOA_H
#define PESSOA_H

#include <QString>

class Pessoa
{
private:
    QString nome;
    QString cpf;
    QString rg;
    QString nascimento;
    //Endereco endereco;
public:
    Pessoa();
    ~Pessoa();
    QString getNome() const;
    void setNome(const QString &value);
    QString getCpf() const;
    void setCpf(const QString &value);
    QString getRg() const;
    void setRg(const QString &value);
    QString getNascimento() const;
    void setNascimento(const QString &value);
};

#endif // PESSOA_H
