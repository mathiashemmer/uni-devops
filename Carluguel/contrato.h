#ifndef CONTRATO_H
#define CONTRATO_H

#include <QDate>

class Contrato
{
private:
    unsigned int meuID;
    unsigned int idCarro;
    double valor;
    QDate inicio;
    QDate fim;
public:
    Contrato();
    unsigned int getMeuID() const;
    unsigned int getIdCarro() const;
    void setIdCarro(unsigned int value);
    double getValor() const;
    void setValor(double value);
    QDate getInicio() const;
    void setInicio(const QDate &value);
    QDate getFim() const;
    void setFim(const QDate &value);
};

#endif // CONTRATO_H
