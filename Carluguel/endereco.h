#ifndef ENDERECO_H
#define ENDERECO_H

#include <QString>

class Endereco
{
private:
    int numero;
    int CEP;
    QString rua;
    QString bairro;
    QString cidade;
public:
    Endereco();
    int getNumero() const;
    void setNumero(int value);
    int getCEP() const;
    void setCEP(int value);
    QString getRua() const;
    void setRua(const QString &value);
    QString getBairro() const;
    void setBairro(const QString &value);
    QString getCidade() const;
    void setCidade(const QString &value);
};

#endif // ENDERECO_H
