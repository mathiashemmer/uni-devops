#include <iostream>
#include <../lib/queue.h>
#include <../lib/educore.h>
#include <supermarket.h>

using namespace std;

int main()
{
    // Inicializações, configurações e variáveis auxiliares
    srand(time(NULL));
    int numClerks = 0, numStartingCustomers = 0, execTime = 0, timeUnitsPerCustomer = 0;
    int timeElapsed = 0;

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
    cin >> timeUnitsPerCustomer;
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
    //PrintClerkStatusAll(clerk, numClerks);

    while(timeElapsed < execTime)
    {
        cin.ignore();
        timeElapsed++;
        if(timeElapsed >= timeUnitsPerCustomer && timeElapsed % timeUnitsPerCustomer == 0)
        {
            /* chama função de colocar alguém no caixa com menos clientes */;
            PrintEvent(0);
        }
        for(int i = 0; i < numClerks; i++)
        {
            clerk[i].head->Data.timeElapsed++;
            if(clerk[i].head->Data.timeElapsed == clerk[i].head->Data.timeStamp)
            {
                Queue_Pop(clerk[i]);
                PrintEvent(1);
            }
        }
    }
}
