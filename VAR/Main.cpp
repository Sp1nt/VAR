#include <iostream>
#include <string>
#include "Var.h"


using namespace std;


int main()
{
    setlocale(0, "");


    Var a = 15;
    Var b = "Hello";
    Var c = 7.8;
    Var d = "50";
    b = a + d;
    b.Show(); // Βϋβεδες 65

    cout << endl << endl;

    if (a == b) 
        cout << "Equal\n"; 
    else 
        cout << "Not Equal\n";

    cout << endl << endl;

    Var a1 = 10, b1 = "120", c1;
    c1 = a1 + b1;
    c1.Show(); // Βϋβεδες 130

    cout << endl << endl;

    c1 = b1 + a1;
    c1.Show(); // Βϋβεδες “12010”
    cout << endl << endl;

    Var a2 = "Microsoft", b2 = "Windows", c2;
    c2 = a2 * b2;
    c2.Show();		// Βϋβεδες “ioso”


}