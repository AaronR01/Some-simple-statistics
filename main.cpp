#include <iostream>
#include <math.h>
using namespace std;


void entrada_vetor(float v[], int n){
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
;

float calcdesv( float vet[], int n)
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




int main() 
{
  int n=0,menu=0;
  float media = 0, desvio;
  float *pntMedia;
  pntMedia = &media;

  
  cout << "Digite o tamanho do vetor" << endl;
  cin >> n;
  float v[n];

  // Estrutura para ler os valores do vetor:

  entrada_vetor(v,n);

while(menu!=5){



  cout << "Digite o que quer fazer com esses dados" << endl;
  cout << "1 : Imprime Dados" << endl;
  cout << "2 : calcular media movel" << endl;
  cout << "3 : calcular desvio padrão" << endl;
  cout << "4 : calcular Q1 e Q3" << endl;
  cout << "5 : Desligar Programa" << endl << endl ;

  
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
      desvio = calcdesv(v, n);
      cout << "desvio padrão é " << desvio << endl;
    }
    case 4:
    {
      break;
    }
    case 5:{
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