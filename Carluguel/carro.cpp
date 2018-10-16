#include "carro.h"

unsigned int Carro::ID = 0;

int Carro::getKmAtual() const
{
    return kmAtual;
}

void Carro::setKmAtual(int value)
{
    kmAtual = value;
}

unsigned int Carro::getMeuID() const
{
    return meuID;
}

QString Carro::getChassi() const
{
    return chassi;
}

void Carro::setChassi(const QString &value)
{
    chassi = value;
}

QString Carro::getPlaca() const
{
    return placa;
}

void Carro::setPlaca(const QString &value)
{
    placa = value;
}

QString Carro::getModelo() const
{
    return modelo;
}

void Carro::setModelo(const QString &value)
{
    modelo = value;
}

QString Carro::getObservacao() const
{
    return observacao;
}

void Carro::setObservacao(const QString &value)
{
    observacao = value;
}

Cor Carro::getCor() const
{
    return cor;
}

void Carro::setCor(const Cor &value)
{
    cor = value;
}

int Carro::getKmRev() const
{
    return kmRev;
}

void Carro::setKmRev(int value)
{
    kmRev = value;
}

StatusCarro Carro::getDisponibilidade() const
{
    return disponibilidade;
}

void Carro::setDisponibilidade(const StatusCarro &value)
{
    disponibilidade = value;
}

bool Carro::AutoInc()
{
    ID++;
    return true;
}

Carro::Carro()
{
    
}

Carro::Carro(int kmAtual, int kmRev, QString chassi, QString placa, QString modelo, QString obs, int cor, StatusCarro disp)
{
    setChassi(chassi);
    Cor thiscor = static_cast<Cor>(cor);
    setCor(thiscor);
    setDisponibilidade(disp);
    setKmAtual(kmAtual);
    setKmRev(kmRev);
    setModelo(modelo);
    setObservacao(obs);
    setPlaca(placa);

    this->meuID = Carro::ID;
    AutoInc();
}
