#include <iostream>
#include <../lib/queue.h>
#include <../lib/educore.h>
#include <supermarket.h>

using namespace std;

int main()
{
    // Inicializações, configurações e variáveis auxiliares
    srand(time(NULL));
    int numClerks = 0, numStartingCustomers = 0, execTime = 0, customersPerUnit = 0;

    // Leitura dos dados da simulação
    cout << "Digite o número de caixas ativos: ";
    cin >> numClerks;
    clearScreen();
    cout << "Digite o número de pessoas em cada fila: ";
    cin >> numStartingCustomers;
    clearScreen();
    cout << "Digite o tempo total da simulação: ";
    cin >> execTime;
    clearScreen();
    cout << "Digite quantas pessoas entram por unidade de tempo: ";
    cin >> customersPerUnit;
    clearScreen();
    // Fim da leitura


    Queue<Customer> clerk[numClerks]; // Vetor de filas (caixas)

    for(int i = 0; i < numClerks; i++) // Inicializando e inserindo os elementos iniciais em cada caixa
    {
        Queue_Start(clerk[i]);
        for(int j = 0; j < numStartingCustomers; j++)
        {
            Queue_Insert(clerk[i], CreateCustomer());
        }
    }

    // A partir daqui, a simulação será iniciada
    clearScreen();
    PrintClerkStatusAll(clerk, numClerks);
    std::cout << "---------------------------------------" << std::endl;
}
