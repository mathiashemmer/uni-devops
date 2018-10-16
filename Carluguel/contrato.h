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
};

#endif // CONTRATO_H
