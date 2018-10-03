#ifndef CARRO_H
#define CARRO_H

#include <string>

class Carro
{
private:
    std::string cor;
    std::string placa;
public:
    Carro();
    ~Carro();
    std::string getCor() const;
    void setCor(const std::string &value);
    std::string getPlaca() const;
    void setPlaca(const std::string &value);
};

#endif // CARRO_H
