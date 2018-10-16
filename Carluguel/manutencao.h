#ifndef MANUTENCAO_H
#define MANUTENCAO_H


class Manutencao : public Contrato
{
private:
    int meuID;
    int idTerceiro;
public:
    static int ID;
    bool static AutoInc();
    Manutencao();
};

#endif // MANUTENCAO_H
