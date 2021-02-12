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
    l.insereInicio(0.05);
    l.insereFinal(0.15);
    l.insereFinal(0.10);
    l.insereFinal(0.20);
    l.insereFinal(0.14);
    l.insereFinal(0.15);
    l.insereFinal(0.21);
 



    cout << "o valor da Media é: " << l.calcMedia() << endl;
    cout << "o valor da Mediana é: " << l.calcMediana() << endl;
    cout << "o valor da Desvio padrao é: " << l.calcDesvioPadrao() << endl;
    cout << "o valor da variança é: " << l.calcVariancia() << endl;
  //  cout << "O valor de Q1 é: " << l.calcQ1() << endl;
  //  cout << setprecision(3) << "O valor de Q3 é: " << l.calcQ3() << endl;

    return 0;
}
