#include <iostream>
#include <../lib/queue.h>
#include <../lib/educore.h>
#include <supermarket.h>
#include <time.h>
#include <locale.h>

using namespace std;

void PrintSimulationStatus(Queue<Customer> clerk[], int numClerks){
    gotoxy(0,0);
    for(int i = 0; i < numClerks; i++){
        PrintClerkStatus(clerk[i]);
    }
    for(int i = 0; i < 5*numClerks; i++){
        gotoxy(40, i);
        cout << "|";
    }
    for(int i = 0; i < numClerks; i++){
        PrintClerkStatusAll(clerk[i], 42+(i*12), i + 1);
    }
    for(int i = 0; i < 5*numClerks; i++){
        gotoxy(42 + numClerks * 12, i);
        cout << "|";
    }
}

int main()
{
    // Inicializações, configurações e variáveis auxiliares
    srand(time(nullptr));
    int numClerks = 0, numStartingCustomers = 0, execTime = 0, timeUnitsPerCustomer = 0;
    int timeElapsed = 0, numEvents = 0;

    //setlocale(LC_ALL,"");

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

    SetConsoleSize(200, 30);

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
    Customer tmp;
    PrintSimulationStatus(clerk, numClerks);
    cin.ignore();
    while(timeElapsed < execTime)
    {   
        numEvents = 0;

        //Espera enter para continuar a simulação
        cin.ignore();
        timeElapsed++;
        clearScreen();
        //---------------------------------------

        // Efetua os calculos de tempo e entrada/saida de clientes
        for(int i = 0; i < numClerks; i++)
        {
            if(clerk[i].head != nullptr){
                clerk[i].head->Data.timeElapsed++;
                if(clerk[i].head->Data.timeElapsed == clerk[i].head->Data.timeStamp)
                {
                    Queue_Pop(clerk[i], tmp);
                    gotoxy(44 + numClerks * 12, numEvents);
                    PrintEvent(1, tmp);
                    numEvents++;
                }
            }
        }

        for(int i = 0; i < timeUnitsPerCustomer; i++)
        {
            /* chama função de colocar alguém no caixa com menos clientes */;
            tmp = InsertClientOnSmallerQueue(clerk, numClerks);
            gotoxy(44 + numClerks * 12, numEvents);
            PrintEvent(0, tmp);
            numEvents++;
        }
        //---------------------------------------------------------

        // Imprime o status atual da simulação
        PrintSimulationStatus(clerk, numClerks);
        //--------------------------------------
    }
}
