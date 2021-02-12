#include <stdio.h>
#include <iostream>
#include <math.h>

#include "IntEstatistica.h"

using namespace std;

intEstatistica::intEstatistica(int max)
{
    cout << "Criando objeto intEstatistica" << endl;
    size = 0;
    maxsize = max;

    vet = new float[maxsize];
    /// vet[maxsize]{3.36, 3.62, 3.64, 3.68, 3.7, 3.73, 3.73, 3.81, 3.83, 3.92, 4.08, 4.1, 4.11, 4.12, 4.14, 4.15, 4.15, 4.16, 4.2, 4.36, 4.38, 4.39, 4.39, 4.4, 4.45, 4.47, 4.56, 4.57, 4.6, 4.98};
}

intEstatistica::~intEstatistica()
{
    cout << "Detruindo objeto intEstatistica" << endl;
    delete[] vet;
}

int intEstatistica::getSize()
{
    return size;
}

int intEstatistica::get(int k)
{
    if (k >= 0 && k < size)
        return vet[k];
    else
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
}

void intEstatistica::set(int k, float val)
{
    if (k >= 0 && k < size)
        vet[k] = val;
    else
        cout << "ERRO: Indice invalido!" << endl;
}

void intEstatistica::insereInicio(float val)
{
    if (size == 0)
    { //lista vazia. Sera o unico no da lista
        vet[size] = val;
        size += 1;
    }
    else
        insereK(0, val);
}

void intEstatistica::insereFinal(float val)
{
    if (size == maxsize)
    {
        cout << "ERRO: Vetor Cheio!" << endl;
        exit(1);
    }

    vet[size] = val;
    size += 1;
}

void intEstatistica::removeInicio()
{
    removeK(0);
}

void intEstatistica::removeFinal()
{
    if (size == 0)
    {
        cout << "ERRO: Lista Vazia!" << endl;
        exit(1);
    }
    size -= 1;
}

void intEstatistica::insereK(int k, float val)
{
    if (size == maxsize)
    {
        cout << "ERRO: Vetor Cheio!" << endl;
        exit(1);
    }

    if (k >= 0 && k < size)
    {
        for (int i = size - 1; i >= k; i--)
            vet[i + 1] = vet[i];
        vet[k] = val;
        size += 1;
    }
    else
        cout << "ERRO: Indice invalido!" << endl;
}

void intEstatistica::removeK(int k)
{
    if (k >= 0 && k < size)
    {
        for (int i = k; i < size - 1; i++)
            vet[i] = vet[i + 1];

        size += 1;
    }
    else
        cout << "ERRO: Indice invalido!" << endl;
}

void intEstatistica::insereVetor(float vetor[], int tam)
{
    for(int i = 0; i <= tam; i++)
    {
        insereFinal(vet[i]); 
    }
}

float intEstatistica::calcMedia()
{
    float soma = 0;

    for (int i = 0; i < size; i++)
    {
        soma += vet[i];
    }

    return soma / size;
}

float intEstatistica::calcDesvioPadrao()
{
    float media = 0;
    media = calcMedia();

    float desvio = 0;

    for (int i = 0; i < size; i++)
        desvio += pow((vet[i] - media), 2);

    desvio = sqrt(desvio / size);

    return desvio;
}

float intEstatistica::calcVariancia()
{
    float variancia = 0;
    variancia = pow(calcDesvioPadrao(), 2);

    return variancia;
}

float intEstatistica::calcMediana()
{
    float mediana = 0;

    if (size % 2 == 0)
    {
        mediana = (vet[(size - 1) / 2] + vet[(size / 2)]) / 2;
    }
    else
        mediana = vet[size / 2];

    return mediana;
}

float intEstatistica::calcQ1()
{
    int tam;
    float mediana;
    float Q1;

    mediana = calcMediana();

    if (size % 2 == 0)
        tam = (size / 2) + 1;
    else
        tam = size / 2;

    float *v;
    v[tam];

    for (int i = 0; i < tam; i++)
    {
        v[i] = vet[i];

        if (i == tam)
            v[i] = mediana;
    }

    if (tam % 2 == 0)
        Q1 = (v[(tam / 2) - 1] + v[(tam / 2)]) / 2;
    else
        Q1 = v[(tam) / 2];

    return Q1;
}

float intEstatistica::calcQ3()
{
    int tam;
    float mediana;
    float Q3;

    mediana = calcMediana();

    if (size % 2 == 0)
        tam = (size / 2) + 1;
    else
        tam = size / 2;

    float *v;
    v[tam];

    int aux;
    aux = tam;

    for (int i = 0; i < tam; i++ && aux++)
    {
        v[i] = vet[aux];

        if (i == 0)
            v[i] = mediana;
    }

    if (tam % 2 == 0)
        Q3 = (v[(tam / 2) - 1] + v[(tam / 2)]) / 2;
    else
        Q3 = v[(tam) / 2];

    return Q3;
}

void intEstatistica::realoca(int novoTam)
{
    if (novoTam >= size)
    {
        // alocar um novo vetor com o novo tamanho
        float *novoVet = new float[novoTam];

        // copiar todos os elementos do vetor antigo para o novo
        for (int i = 0; i < size; i++)
            novoVet[i] = vet[i];

        // deletar o vetor antigo
        delete[] vet;

        // atualizar as variaveis da classe
        vet = novoVet;
        maxsize = novoTam;
    }
    else
        cout << "ERRO: Novo tamanho invalido!" << endl;
}

void intEstatistica::imprimeVetor()
{
    for (int i = 0; i < size; i++)
    {
        cout << vet[i] << " ";
    }
    cout << endl;
}

void intEstatistica::limpar()
{
    size = 0;
}

void intEstatistica::ordenar()
{
    int aux;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (vet[i] < vet[j])
            {
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
}
