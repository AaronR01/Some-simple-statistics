#include <stdio.h>
#include <iostream>
#include <math.h>

#include "IntEstatistica.h"

using namespace std;

intEstatistica::intEstatistica(int max)
{
    size = 0;
    maxsize = max;

    vet = new int[maxsize];
}

intEstatistica::~intEstatistica()
{
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

void intEstatistica::set(int k, int val)
{
    if (k >= 0 && k < size)
        vet[k] = val;
    else
        cout << "ERRO: Indice invalido!" << endl;
}

void intEstatistica::insereInicio(int val)
{
    if (size == 0)
    { //lista vazia. Sera o unico no da lista
        vet[size] = val;
        size += 1;
    }
    else
        insereK(0, val);
}

void intEstatistica::insereFinal(int val)
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
    size += 1;
}

void intEstatistica::insereK(int k, int val)
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
        Q1 = (v[(tam - 1) / 2] + v[(tam / 2)]) / 2;
    else
        Q1 = v[(tam) / 2];

    return Q1;
}

float intEstatistica::calcQ3()
{
    
}

void intEstatistica::realoca(int novoTam)
{
    if (novoTam >= size)
    {
        // alocar um novo vetor com o novo tamanho
        int *novoVet = new int[novoTam];

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
