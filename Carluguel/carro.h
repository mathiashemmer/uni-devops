#ifndef CARRO_H
#define CARRO_H

#include <QString>

enum Cor {Azul, Verde, Vermelho, Cinza, Preto, Branco, Prata, Laranja, Rosa, Ciano, Marinho, Vinho};
enum StatusCarro {Alugado = 1, Disponivel, Manutencao};

class Carro
{
private:
    int kmAtual;
    int kmRev;
    unsigned int meuID;
    QString chassi;
    QString placa;
    QString modelo;
    QString observacao;
    Cor cor;
    StatusCarro disponibilidade;
public:
    //Usado como ID unico para a classe
    static unsigned int ID;

    Carro();
    Carro(int kmAtual, int kmRev, QString chassi, QString placa, QString modelo, QString obs, int cor, StatusCarro disp);
    int getKmAtual() const;
    void setKmAtual(int value);
    int getKmRev() const;
    void setKmRev(int value);
    unsigned int getMeuID() const;
    QString getChassi() const;
    void setChassi(const QString &value);
    QString getPlaca() const;
    void setPlaca(const QString &value);
    QString getModelo() const;
    void setModelo(const QString &value);
    QString getObservacao() const;
    void setObservacao(const QString &value);
    Cor getCor() const;
    void setCor(const Cor &value);
    StatusCarro getDisponibilidade() const;
    void setDisponibilidade(const StatusCarro &value);
};

#endif // CARRO_H
