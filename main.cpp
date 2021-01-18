#include <iostream>
#include <math.h>
using namespace std;


// Estrutura para ler os valores do vetor:
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

void calcular_media(float *ponteiro, float vetor[], int n)
{
  float media, soma = 0;

  for(int i = 0; i < n; i++){
    soma = soma + vetor[i];
  }
  *ponteiro = soma/n;
}

void imprime_vetor(float vetor[], int n)
{
  for(int i = 0; i < n; i++){
    cout << vetor[i] << " "; 
  }
  cout << endl;
}


float calcdesv(int media, float vet[], int n)
{
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
  float media,desvio;
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
  if (menu==1)
    {
      imprime_vetor(v, n);
    }

    if (menu==2)
    {
      calcular_media(pntMedia, v, n);
     cout << "media igual a " << media << endl;   
    }

    if (menu == 3)
    {
      calcular_media(pntMedia, v, n);
      desvio = calcdesv(media, v, n);
        cout << "desvio padrão é " << desvio << endl;
    }

    if (menu == 5)
    {
      cout << "desligando" << endl;
    }
cout << endl;
}
}
/*
switch(menu)
{

    case 1:
    {
      calcular_media(pntMedia, v, n);
    }

    case 2:
    {
    calcular_media(pntMedia, v, n);
    desvio = calcdesv(media, v, n);
    }
    case 3:
    {
      
    }
    case 4:
    {
      imprime_vetor(v, n);
    }
    case 5:{
      cout << "desligando" << endl;
    }
    
    default:
    {
      cout << "valor invalido Digite novamente" <<  endl;
    }
}

if (menu==1)
{
imprime_vetor(v, n);
}

else if (menu==2)
{
calcular_media(pntMedia, v, n);
}

else if (menu == 3)
{
calcular_media(pntMedia, v, n);
desvio = calcdesv(media, v, n);
}

else if (menu == 5)
{
cout << "desligando" << endl;
}*/