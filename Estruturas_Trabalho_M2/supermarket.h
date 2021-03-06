#ifndef SUPERMARKET_H
#define SUPERMARKET_H

#include <iostream>

#include <../lib/queue.h>
#include <../lib/educore.h>

struct Customer
{
    int timeStamp;
    int timeElapsed;
    std::string name;
};

// Gera um nome de 2 até 6 sílabas escolhidas aleatóriamente da lista abaixo
std::string GenerateName()
{
    std::string syllables[] = {"ba", "be", "bi", "bo", "bu", "ca", "ce", "ci", "co", "cu", "da", "de", "di", "do", "du",
                        "fa", "fe", "fi", "fo", "fu", "ga", "ge", "gi", "go", "gu", "ja", "je", "ji", "jo", "ju",
                        "la", "le", "li", "lo", "lu", "ma", "me", "mi", "mo", "mu", "na", "ne", "ni", "no", "nu",
                        "pa", "pe", "pi", "po", "pu", "ra", "re", "ri", "ro", "ru", "sa", "se", "si", "so", "su",
                        "ta", "te", "ti", "to", "tu", "va", "ve", "vi", "vo", "vu", "xa", "xe", "xi", "xo", "xu",
                        "za", "ze", "zi", "zo", "zu", "aa", "ae", "ai", "ao", "au", "ea", "ee", "ei", "eo", "eu",
                        "ia", "ie", "ii", "io", "iu", "oa", "oe", "oi", "oo", "ou", "ua", "ue", "ui", "uo", "uu"};
    int numOfSyllables = (rand() % 4) + 2;
    std::string name = "";
    for(int i = 0; i < numOfSyllables; i++)
    {
        name = name + syllables[rand() % 104];
    }

    name[0] = toupper(name[0]);
    return name;
}

// Cria um tipo de dado Customer e retorna os dados encapsulados
Customer CreateCustomer()
{
    Customer customer;
    customer.name = GenerateName();

    int chance = rand() % 100;
    if(chance < 20) // 20% serão atendidos em 6 segundos (de 0 até 19)
        customer.timeStamp = 6;
    else if(chance < 50) // 30% serão atendidos em 4 segundos (de 20 até 49)
        customer.timeStamp = 4;
    else // 50% serão atendidos em 1 segundo (de 50 até 100)
        customer.timeStamp = 1;

    customer.timeElapsed = 0; // Todos os clientes iniciam com 0 segundos passados

    return customer; // Retorna a estrutura de dados encapsulada para a criação de um novo cliente
}

// Imprime a situação atual do caixa (quantas pessoas estão na fila, quem é o primeiro da fila e quanto tempo falta pra ele sair)
void PrintClerkStatus(Queue<Customer> queue)
{
    if(queue.size == 0)
    {
        std::cout << "---------------------------------------" << std::endl;
        std::cout << "Caixa vazio" << std::endl;
    }
    else
    {
        std::cout << "---------------------------------------" << std::endl;
        std::cout << "Numero de clientes na fila: " << queue.size << std::endl;
        std::cout << "Cliente sendo atendido:     " << queue.head->Data.name << std::endl;
        std::cout << "Tempo restante:             " << queue.head->Data.timeStamp - queue.head->Data.timeElapsed << std::endl;
    }
}

// Imprime a situação atual de todos os caixas
void PrintClerkStatusAll(Queue<Customer> queue, int xOffSet, int currentClerk)
{
    if(queue.size <= 0 ) return;
    int i = 1;
    Node<Customer> *node = queue.head;
    if(node->next != nullptr){
        node = node->next;
        gotoxy(xOffSet, i++);
        std::cout << "Caixa: " << currentClerk;
        while(node != nullptr){
            gotoxy(xOffSet, i++);
            std::cout << node->Data.name ;
            gotoxy(xOffSet, i++);
            std::cout << node->Data.timeStamp;
            node = node->next;
        }
    }
}

// Imprime mensagem de algum evento
void PrintEvent(int n, Customer eventSender, int eventClerk)
{   
    if(n == 1)
        std::cout << "Cliente " << eventSender.name << " atendido\n";
    if(n == 0)
        std::cout << "Cliente " << eventSender.name << " entrou na fila: " << eventClerk << "\n";
}

// Insere um cliente na fila mais vazia
Customer InsertClientOnSmallerQueue(Queue<Customer> queue[], int numClerks, int custPerClerk[], int &clerk)
{
    int smallestQueue = 9999, smlQueueSize = 9999;
    Customer newCustomer = CreateCustomer();
    // Acha a menor fila atual
    for(int i = 0; i < numClerks; i++){
        if(queue[i].size < smlQueueSize){
            smallestQueue = i;
            smlQueueSize = queue[i].size;
        }
    }
    Queue_Insert(queue[smallestQueue], newCustomer);
    custPerClerk[smallestQueue]++;
    clerk = smallestQueue;
    return newCustomer;
}

#endif // SUPERMARKET_H
