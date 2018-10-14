#ifndef CARRO_H
#define CARRO_H

#include <QString>

class Carro
{
private:
    int myID;
    int quilometragem;
    bool disponivel;
    QString cor;
    QString placa;
public:
    static int id;
    Carro();
    ~Carro();
    int getID() const;
    QString getCor() const;
    void setCor(const QString &value);
    QString getPlaca() const;
    void setPlaca(const QString &value);
    int getQuilometragem() const;
    void setQuilometragem(int value);
    bool getDisponivel() const;
    void setDisponivel(bool value);
};

#endif // CARRO_H
