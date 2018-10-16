#ifndef CONTRATO_H
#define CONTRATO_H

#include <QVector>
#include <QDate>

class Contrato
{
private:
    QVector<unsigned int> idCarros;
    double valor;
    QDate inicio;
    QDate retorno;
public:
    Contrato();
    int getID() const;
    QVector<unsigned int> getIdCarros() const;
    void setIdCarros(const QVector<unsigned int> &value);
    double getValor() const;
    void setValor(double value);
    QDate getInicio() const;
    void setInicio(const QDate &value);
    QDate getRetorno() const;
    void setRetorno(const QDate &value);
};

#endif // CONTRATO_H
