#include <iostream>
#include <../lib/queue.h>
#include <../lib/educore.h>
#include <supermarket.h>

using namespace std;

int main()
{
    srand(time(NULL));
    Customer customer = CreateCustomer();

    Customer customer2 = CreateCustomer();

    cout << customer.name << endl;
    cout << customer2.name << endl;
}
