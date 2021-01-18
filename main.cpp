#include <iostream>
#include <math.h>
using namespace std;

void swap(float *xp, float *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
  
void bubbleSort(float arr[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)      
      
    // Last i elements are already in place  
    for (j = 0; j < n-i-1; j++)  
        if (arr[j] > arr[j+1])  
            swap(&arr[j], &arr[j+1]);  
}

void entrada_vetor(float v[], int n)
{
  for(int i = 0; i < n; i++)
  {
    if (i != n-1)
    cout << "Digite o valor " << i+1 << ": ";
    else{
    cout << "Digite o ultimo valor: "; 

    }
    cin  >> v[i];
  }
  cout << endl;
}

float calcular_media(float vetor[], int n)
{
  float media, soma = 0;

  for(int i = 0; i < n; i++){
    soma = soma + vetor[i];
  }
  return soma/n;
}

void imprime_vetor(float vetor[], int n)
{
  for(int i = 0; i < n; i++){
    cout << vetor[i] << " "; 
  }
  cout << endl;
}

float calc_desv( float vet[], int n)
{
  float media=0;
  media = calcular_media(vet, n);
  float desvio=0;
  for(int i = 0; i < n; i++){
  desvio += pow((vet[i]-media),2);
  }
  desvio = sqrt(desvio/n);
  return desvio;
}

float calc_mediana(float vet[], int n)
{
  float mediana;
    if(n % 2 == 0)
    {
      mediana = (vet[(n-1)/2] + vet[(n/2)])/2;
    }
    else
    {
      mediana = vet[(n)/2];
    }
  cout << mediana << endl;
  
  return mediana;
}

float calc_Q1(float vet[], int n, float mediana){
  float Q1;
  int tam = n/2;
  float v[tam];

  for(int i = 0; i < tam; i++){
    v[i] = vet[i];

    if(i == tam)
      v[i] = mediana;
    
  }
  
  
  if(tam % 2 == 0)
  {
      Q1 = (v[(tam-1)/2] + v[(tam/2)])/2;    
  }
  else
  {
      Q1 = v[(tam)/2];    
  }
  imprime_vetor(v,tam);
  cout << Q1 << endl;
  cout << mediana << endl;
 return Q1; 
}

float calc_Q3(float vet[], int n){
  float Q3;

 return Q3; 
}




int main() 
{
  int n=0,menu=0;
  float media = 0, desvio, mediana = 0;
  float Q1 = 0, Q3 = 0;
  float *pntMedia;
  pntMedia = &media;

  
  cout << "Digite o tamanho do vetor" << endl;
  cin >> n;
  float v[n];


  entrada_vetor(v,n);
  bubbleSort(v, n);

  while(menu != 7)
  {


    cout << "Digite o que quer fazer com esses dados" << endl;
    cout << "1 : Imprime Dados" << endl;
    cout << "2 : Calcular media movel" << endl;
    cout << "3 : Calcular desvio padrão" << endl;
    cout << "4 : Calcular Mediana" << endl;
    cout << "5 : Calcular Q1" << endl;
    cout << "6 : Calcular Q3" << endl;    
    cout << "7 : Desligar Programa" << endl << endl ;

  
    cin >> menu;
    cout << endl;
  
    switch(menu)
    {
      case 1:
      {
        imprime_vetor(v, n);
        break;
      }
      case 2:
      {
         media = calcular_media(v, n);
         cout << "media igual a " << media << endl; 
        break;
      }
      case 3:
      {
        desvio = calc_desv(v, n);
        cout << "desvio padrão é " << desvio << endl;
      }
      case 4:
      {
        mediana = calc_mediana(v,n);
        break;
      }
      case 5:
      {
        Q1 = calc_Q1(v, n);
        break;
      }
      case 6:
      {
        Q3 = calc_Q3(v, n);
        break;
      }            
      case 7:
      {
        cout << "desligando" << endl;
        break;
      }
      default:
      {
        cout << "valor invalido Digite novamente" <<  endl;
        break;
      }
    }
    cout << endl;
  }
}