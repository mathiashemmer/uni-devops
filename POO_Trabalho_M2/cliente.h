#ifndef CLIENTE_H
#define CLIENTE_H

#include <QString>
#include <pessoa.h>

class Cliente : public Pessoa
{
private:
    int myID;
    QString cnh;
public:
    static int id;
    Cliente();
    ~Cliente();
    int getID() const;
    QString getCnh() const;
    void setCnh(const QString &value);
};

#endif // CLIENTE_H
