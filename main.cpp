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

    intEstatistica l(tam); /// criando um objeto intEstatistica

    float vetor[30]{3.36, 3.62, 3.64, 3.68, 3.7, 3.73, 3.73, 3.81, 3.83, 3.92, 4.08, 4.1, 4.11, 4.12, 4.14, 4.15, 4.15, 4.16, 4.2, 4.36, 4.38, 4.39, 4.39, 4.4, 4.45, 4.47, 4.56, 4.57, 4.6, 4.98};

    l.insereVetor(vetor, 30);
    l.imprimeVetor();

    cout << "O valor de Q1 é: " << l.calcQ1() << endl;
    cout << setprecision(3) << "O valor de Q3 é: " << l.calcQ3() << endl;

    return 0;
}
