#include <iostream>
#include <../EstruturaDeDados/queue.h>
#include <../EstruturaDeDados/educore.h>

void Macaca(){
    int a = 1;
}

using namespace std;

struct Pessoa{
    int tempoBase;
    int tempoPassado;
};

/* void PreenchePessoas
 * Preeche as pessoas do sistema, segundo a proporção:
 * 50% exige 1un tempo para atendimento
 * 30% exige 4un tempo para atendimento
 * 20% exige 2un tempo para atendimento
 * Randomizando no final no final a ordem dos registros
 * para inserir na lista de pessoas a serem colocadas nos caixas
 */
void PreenchePessoas(Queue<Pessoa> &listaOriginal, int total){
    int rNum;
    Pessoa pessoas[total];
    for(int i = 0; i < total; i++){
        if(i < (20*total/100)){
            pessoas[i].tempoBase = 6;
            pessoas[i].tempoPassado = 6;
        }else if(i < (50*total/100)){
            pessoas[i].tempoBase = 4;
            pessoas[i].tempoPassado = 4;
        }else{
            pessoas[i].tempoBase = 1;
            pessoas[i].tempoPassado = 1;
        }
        cout << "Pessoa atual[" << i << "]: " <<pessoas[i].tempoBase << endl;
    }
    for(int i = 0; i < total; i++){
        Pessoa tmpPP;
        rNum = rand() % total;
        tmpPP = pessoas[i];
        pessoas[i] = pessoas[rNum];
        pessoas[rNum] = tmpPP;
        Queue_Insert(listaOriginal, pessoas[i]);
    }

    cout << "Pessoas adicionadas e randomizadas" << endl;
    system("pause");
}

/*void PreenchePessoasNosCaixas
 * Preenche as pessoas nos caixas, solicitando ao usuário a quantidade
 * de pessoas a serem inseridas inicialmente nos caixas
 */
void PreenchePessoasNosCaixas(int ppNasFilas[], int qtdTotalPessoas, int qtdCaixas){
    bool overload = false;
    int ppNetWorth = qtdTotalPessoas;
    for(int i = 0; i < qtdCaixas; i++){
        cout << "Quantas pessoas o caixa " << i << " possui inicialmente? " << endl;
        cout << "Existem " << ppNetWorth << " para serem usadas" << endl;
        do{
            overload = false;
            cin >> ppNasFilas[i];
            if(ppNetWorth - ppNasFilas[i] < 0){
                overload = true;
                cout << "Voce excedeu o limite de pessoas, insira outro valor :";
            }
        }while(overload);
        ppNetWorth -= ppNasFilas[i];
        cout << endl;
    }
}

/*void PreencheCaixas
 * Preenche cada caixa com n numero de clientes, definidos anteriormente
 * pelo usuario
 */
void PreencheCaixas(Queue<Pessoa> caixa[], Queue<Pessoa> &filaOriginal, int qtdPPCaixa[], int qtdCaixas){
    for(int i = 0; i < qtdCaixas; i++){
        for(int j = 0; j < qtdPPCaixa[i]; j++){
            Pessoa p;
            Queue_Pop(filaOriginal, p);
            Queue_Insert(caixa[i], p);
        }
    }
}

int main(){
    int qtdCaixas, qtdClientes, ppPorUn, unPorCiclo;
    /*
     * qtdCaixas     -> Quantidade de caixas/filas disponiveis
     * qtdClientes   -> Numero total de clientes no sistema
     * ppPorUn       -> Quantidade de pessoas que entram nas filas por unidade de tempo
     * unPorEnter    -> Unindade de tempo percorrida por ciclo do sistema
     */
    cout << "Informe a quantidade de caixas: " << endl;
    cout << "Informe a quantidade total de clientes: " << endl;
    cout << "Informe a quantidade de pessoas que entram:" << endl;
    cout << "Informe a quantidade de tempo percorrido por enter: " << endl;
    gotoxy(32, 0);
    cin >> qtdCaixas;
    gotoxy(40, 1);
    cin >> qtdClientes;
    gotoxy(44, 2);
    cin >> ppPorUn;
    gotoxy(52, 3);
    cin >> unPorCiclo;

    Queue<Pessoa> filaOriginal;
    Queue_Start(filaOriginal);
    PreenchePessoas(filaOriginal, qtdClientes);

    system("cls");
    int ppNasFilas[qtdCaixas];
    PreenchePessoasNosCaixas(ppNasFilas, qtdClientes, qtdCaixas);

    Queue<Pessoa> filaCaixas[qtdCaixas];
    for(int i = 0; i < qtdCaixas; i++){
        Queue_Start(filaCaixas[i]);
    }
    PreencheCaixas(filaCaixas, filaOriginal, ppNasFilas, qtdCaixas);


}
