#include <iostream>
#include <../lib/queue.h>
#include <../lib/educore.h>
#include <supermarket.h>
#include <time.h>
#include <locale.h>
#include <auxlib.h>

using namespace std;

void PrintSimulationStatus(Queue<Customer> clerk[], int numClerks){
    gotoxy(1,1);
    for(int i = 0; i < numClerks; i++){
        PrintClerkStatus(clerk[i]);
    }
    for(int i = 0; i < 5*numClerks; i++){
        gotoxy(40, i+1);
        cout << "|";
    }
    for(int i = 0; i < numClerks; i++){
        PrintClerkStatusAll(clerk[i], 42+(i*12), i + 1);
    }
    for(int i = 0; i < 5*numClerks; i++){
        gotoxy(42 + numClerks * 12, i+1);
        cout << "|";
    }
}

int main()
{
    // Inicializações, configurações e variáveis auxiliares
    srand(time(nullptr));
    int numClerks = 0, numStartingCustomers = 0, execTime = 0, customersperTimeUnit = 0;
    int timeElapsed = 0, numEvents = 0;

    SetConsoleSize(200, 30);

    setTitle("Mercado Tupi");

    // Leitura dos dados da simulação
    numClerks = get_int(1, "Digite o numero de caixas ativos: ");
    clearScreen();
    numStartingCustomers = get_int(0, "Digite o numero de pessoas em cada fila: ");
    clearScreen();
    execTime = get_int(1, "Digite o tempo de execucao da simulacao: ");
    clearScreen();
    customersperTimeUnit = get_int(0, "Digite quantas pessoas entram por unidade de tempo: ");
    clearScreen();
    // Fim da leitura
    std::cin.clear();

    Queue<Customer> clerk[numClerks]; // Vetor de filas (caixas)
    int customerPerClerk[numClerks];
    for(int i = 0; i < numClerks; i++) customerPerClerk[i] = 0;

    for(int i = 0; i < numClerks; i++) // Inicializando e inserindo os elementos iniciais em cada caixa
    {
        Queue_Start(clerk[i]);
        for(int j = 0; j < numStartingCustomers; j++)
        {
            Queue_Insert(clerk[i], CreateCustomer());
            customerPerClerk[i]++;
        }
    }

    // A partir daqui, a simulação será iniciada
    //PrintClerkStatusAll(clerk, numClerks);
    PrintSimulationStatus(clerk, numClerks);
    cin.ignore();
    Customer newCustumer;
    while(timeElapsed < execTime){   
        numEvents = 1;
        cin.ignore();
        timeElapsed++;
        clearScreen();
        //-----------------------------------------------------------------------------
        // Efetua os calculos de tempo e entrada/saida de clientes
        for(int i = 0; i < numClerks; i++){
            if(clerk[i].head != nullptr){
                clerk[i].head->Data.timeElapsed++;
                if(clerk[i].head->Data.timeElapsed == clerk[i].head->Data.timeStamp){
                    Queue_Pop(clerk[i], newCustumer);
                    gotoxy(44 + numClerks * 12, numEvents);
                    PrintEvent(1, newCustumer, -1);
                    numEvents++;
                }
            }
        }//-----------------------------------------------------------------------------

        //------------------------------------------------------------------------
        // Insere o número de clientes que o usuário escolheu
        for(int i = 0; i < customersperTimeUnit; i++){
            // Chama função de colocar alguém no caixa com menos clientes
            int eventClerk = -1;
            newCustumer = InsertClientOnSmallerQueue(clerk, numClerks, customerPerClerk, eventClerk);
            gotoxy(44 + numClerks * 12, numEvents);
            PrintEvent(0, newCustumer, eventClerk);
            numEvents++;
        }//-----------------------------------------------------------------------

        //--------------------------------------
        // Imprime o status atual da simulação
        PrintSimulationStatus(clerk, numClerks);
        //--------------------------------------
        gotoxy(1, 45);
        cout << timeElapsed;
    }
    clearScreen();
    cout << "Media de clientes por caixa:" << endl;
    for(int i = 0; i < numClerks; i++){
        cout << "Caixa " << i << ": " << customerPerClerk[i] << endl;
    }
}
