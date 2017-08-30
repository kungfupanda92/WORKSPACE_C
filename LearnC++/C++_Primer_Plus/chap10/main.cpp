#include <iostream>
#include "stock.h"
using namespace std;

int main(void)
{
    cout << "Using contructor to create new objecta\n";
    Stock stock1("NanoSmart", 12, 20.0);
    stock1.show();
    Stock stock2 = Stock("Boffo objects", 2, 2.0);
    stock2.show();

    cout << "Assignint stock1 to stock2: \n";
    stock2 = stock1;
    stock1.show();
    stock2.show();

    cout << "Using a contructor to reset an object\n";
    stock1 = Stock("Nifty Foods", 10, 50.0);
    cout << "Revising stock1: \n";
    stock1.show();
    cout << "Done\n";

    return 0;
}

