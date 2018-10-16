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
    int getID() const;
    Manutencao();
    int getIdTerceiro() const;
    void setIdTerceiro(int value);
};

#endif // MANUTENCAO_H
