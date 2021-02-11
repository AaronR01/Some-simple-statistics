#include <stdio.h>
#include <iostream>
#include <iomanip> 
#include <math.h>

#include "IntEstatistica.h"

using namespace std;

int main()
{
    int tam;

    cout << "Determine o tamanho máximo da lista: ";
    cin >> tam;
    cout << endl;

    intEstatistica l(tam);      /// criando um objeto intEstatistica

    l.insereInicio(3.36);
    l.insereFinal(3.62);
    l.insereFinal(3.64);
    l.insereFinal(3.68);
    l.insereFinal(3.7);
    l.insereFinal(3.73);
    l.insereFinal(3.73);
    l.insereFinal(3.81);
    l.insereFinal(3.83);
    l.insereFinal(3.92);
    l.insereFinal(4.08);
    l.insereFinal(4.1);
    l.insereFinal(4.11);
    l.insereFinal(4.12);
    l.insereFinal(4.14);
    l.insereFinal(4.15);
    l.insereFinal(4.15);
    l.insereFinal(4.16);
    l.insereFinal(4.2);
    l.insereFinal(4.36);
    l.insereFinal(4.38);
    l.insereFinal(4.39);
    l.insereFinal(4.39);
    l.insereFinal(4.4);
    l.insereFinal(4.45);
    l.insereFinal(4.47);
    l.insereFinal(4.56);
    l.insereFinal(4.57);
    l.insereFinal(4.6);
    l.insereFinal(4.98);


    cout << "O valor de Q1 é: " << l.calcQ1() << endl;
    cout << setprecision(3) << "O valor de Q3 é: " << l.calcQ3() << endl;

    return 0;
}   
