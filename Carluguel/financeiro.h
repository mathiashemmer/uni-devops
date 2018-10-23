#ifndef FINANCEIRO_H
#define FINANCEIRO_H

#include <QString>
#include <QDate>

class Financeiro
{
private:
    unsigned int meuID;
    unsigned int idEnvolvido;
    QString referente;
    short tipo;
    double valor;
    QDate data;
public:
    static unsigned int ID;
    static bool AutoInc();
    Financeiro();
    ~Financeiro();
    Financeiro(unsigned int idEnvolvido, QString referente, short tipo, double valor, QDate data);
    unsigned int getIdEnvolvido() const;
    void setIdEnvolvido(unsigned int value);
    QString getReferente() const;
    void setReferente(const QString &value);
    short getTipo() const;
    void setTipo(short value);
    double getValor() const;
    void setValor(double value);
    QDate getData() const;
    void setData(const QDate &value);
    unsigned int getMeuID() const;
};

#endif // FINANCEIRO_H
