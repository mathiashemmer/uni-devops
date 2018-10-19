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
    short tipo;
public:
    static unsigned int ID;
    static bool AutoInc();
    Contrato();
    virtual ~Contrato();
    Contrato(unsigned int idCarro, double valor, QDate inicio, QDate fim, short tipo);
    unsigned int getMeuID() const;
    unsigned int getIdCarro() const;
    void setIdCarro(unsigned int value);
    double getValor() const;
    void setValor(double value);
    QDate getInicio() const;
    void setInicio(const QDate &value);
    QDate getFim() const;
    void setFim(const QDate &value);
    void setTipo(const short &value);
    short getTipo() const;
};

#endif // CONTRATO_H
