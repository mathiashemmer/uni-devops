#ifndef CARRO_H
#define CARRO_H

#include <string>

class Carro
{
private:
    int myID;
    std::string cor;
    std::string placa;
public:
    static int id;
    Carro();
    ~Carro();
    int getID() const;
    std::string getCor() const;
    void setCor(const std::string &value);
    std::string getPlaca() const;
    void setPlaca(const std::string &value);
};

#endif // CARRO_H
