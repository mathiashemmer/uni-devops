#ifndef PESSOA_H
#define PESSOA_H
#include <endereco.h>
#include <QString>
#include <QDateTime>

class Pessoa
{
protected:
    Endereco endereco;
    QString nome;
    QString sobrenome;
    QString CPF;
    QDate dataNacimento;

public:
    Pessoa();
    Pessoa(Endereco endereco, QString nome, QString sobrenome, QString CPF, QDate nacimento);
    Endereco getEndereco() const;
    void setEndereco(const Endereco &value);
    QString getNome() const;
    void setNome(const QString &value);
    QString getSobrenome() const;
    void setSobrenome(const QString &value);
    QDate getDataNacimento() const;
    void setDataNacimento(const QDate &value);
    QString getCPF() const;
    void setCPF(const QString &value);
};

#endif // PESSOA_H
