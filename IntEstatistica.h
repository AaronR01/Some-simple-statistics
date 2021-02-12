#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

class intEstatistica
{
    private:
    int maxsize;              /// tamanho máximo do vetor
    int size;                 /// quantidade de elementos no vetor
    float *vet;               /// vetor


    public:
    intEstatistica(int max);  /// construtor
    ~intEstatistica();        /// destrutor

    
    int get(int k);                        /// retorna o valor no índice k
    void set(int k, float val);            /// altera o valor no índice k
    void insereInicio(float val);          /// insere elemento no início da lista
    void insereFinal(float val);           /// insere elemento no final da lista
    void removeInicio();                   /// remove elemento no inicio da lista
    void removeFinal();                    /// remove elemento no final da lista
    void insereK(int k, float val);        /// insere um valor no índice k da lista
    void removeK(int k);                   /// remove um valor no índice k da lista
    void insereVetor(float vet[], int tam); /// insere um vetor no


    float calcMedia();         /// retorna a media de todos os elementos da lista
    float calcDesvioPadrao();  /// retorna o desvio padrão dos elementos da lista
    float calcVariancia();     /// retorna a variância dos elementos da lista
    float calcMediana();       /// retorna a mediana dos elementos da lista
    float calcQ1();            /// retorna o primeiro quartil da lista
    float calcQ3();            /// retorna o terceiro quartil da lista


    void realoca (int novoTam);   /// realoca a lista em um novo vetor
    void imprimeVetor();          /// imprime o vetor da lista
    void limpar();                /// limpa a lista
    void ordenar();               /// ordena os elementos da lista
    int getSize();                /// retorna o número de elementos do vetor
};
