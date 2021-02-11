#include <iostream>
#include <math.h>
using namespace std;

int mappercent (int x1,int tam)
{
//			x			return
//		  tam+1			100
	return 100*(x1-1)/(tam);
}

void swap(double *xp, double *yp)  
{  
    double temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
  
void bubbleSort(double arr[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)      
      
    // Last i elements are already in place  
    for (j = 0; j < n-i-1; j++)  
        if (arr[j] > arr[j+1])  
            swap(&arr[j], &arr[j+1]);  
}

void entrada_vetor(double v[], int n)
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

double calcular_media(double vet[], int n)
{
  double media, soma = 0;

  for(int i = 0; i < n; i++){
    soma = soma + vet[i];
  }
  return soma/n;
}

void imprime_vetor(double vet[], int n)
{
  for(int i = 0; i < n; i++){
    cout << vet[i] << " "; 
  }
  cout << endl;
}

double calc_desv(double vet[], int n)
{
  double media=0;
  media = calcular_media(vet, n);
  double desvio=0;
  for(int i = 0; i < n; i++){
  desvio += pow((vet[i]-media),2);
  }
  desvio = sqrt(desvio/n);
  return desvio;
}

double calc_mediana(double vet[], int n)
{
  double mediana;
    if(n % 2 == 0)
    {
      mediana = (vet[(n-1)/2] + vet[(n/2)])/2;
    }
    else
    {
      mediana = vet[n/2];
    }
  cout << mediana << endl;
  
  return mediana;
}
/*
double calc_Q1(double vet[], int n, double mediana)
{
  int tam;
  double Q1;

  if(n % 2 == 0){
    tam = (n/2)+1;  
    cout <<  tam << " "; 
  }
  else 
  {
    tam = n/2;
  }
  cout <<  tam << endl;
  
  double v[tam];
  imprime_vetor(v, tam);
  for(int i = 0; i < tam; i++)
  {
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
  imprime_vetor(v, tam);
  cout << Q1 << endl;
 return Q1; 
}

double calc_Q3(double vet[], int n, double mediana){
  double Q3;
  int tam = n/2;
  double v[tam];

  for(int i = tam; i < n; i++){
    v[i] = vet[i];

    if(i == tam)
      v[i] = mediana;    
  }
  
  
  if(tam % 2 == 0)
  {
    Q3 = (v[(tam-1)/2] + v[(tam/2)])/2;    
  }
  else
  {
    Q3 = v[(tam)/2];    
  }

  cout << Q3 << endl;

 return Q3; 
}
*/

/*Q1 ANTIGO*/
/*
void calcular_quantis(double vet[], int tamanho, int porcentagem)
{
  // Q1 e Q3 nada mais é que 25% e 75%
  int posicao=tamanho*porcentagem/100;
  if(tamanho%2==0) posicao++;
  cout << posicao << endl;
  double vetaux[posicao];

  

  if(tamanho%2==0)
  {
      for(int i=0;i<posicao;i++)
      {
      vetaux[i] = vet[i];
      cout << vetaux[i] << " ";
      }
      vetaux[posicao] =(vet[posicao+1]+vet[posicao]);
      cout << endl;
    //umas coisas ai
  }
  else
  {
    //umas parada diferente
  }
  imprime_vetor(vetaux,posicao);
}
*/

/* Q1 da J */
void calcular_quantis(double vet[], int tamanho, int porcentagem)
{
	double valor;
	// 0 = 0%, MAX = 100%
  
	/*			0		100
		1 			0
            ?
		2		0		1
        0%  100%
		3		0	 1	 2
        0% 50% 100%
    4		0	 1	 2	 3
        0% 33% 66% 100%
	*/
	if(tamanho == 1){
		valor = vet[0];
		return;
	}
	// 0 = 0%, MAX = 100%
	/*	n		0							PORCENTAGEM REAL DADA POR
		1 		0								n/n-1
		2		0			1					n/n-1
		3		0	0.5		1					n/n-1
		4		0	0.33	0.66	1 			n/n-1
		5   	0	0.25	0.5		0.75	1	n/n-1
80% n

	*/ 
  	// Q1 e Q3 nada mais é que 25% e 75%
  	float posicaoReal = (tamanho)*(porcentagem/100.0);
  	int posicaoAcima = ceil(posicaoReal);
	int posicaoAbaixo = floor(posicaoReal);
	float divisaozinha = (float)(tamanho)/(tamanho-1);

	if (posicaoReal < divisaozinha){
		valor = (vet[posicaoAcima] + vet[posicaoAbaixo])/2.0;
	}
	else
	{
	
		valor = vet[(int)posicaoReal];
	}
	
	

// IMPRESSAO PARA AUXILIAR NO DEBUG
	cout << "F = " << posicaoReal << endl ;
	cout << "I+ = " << posicaoAcima << endl;
	cout << "I- = " << posicaoAbaixo << endl;
	cout << "n/n-1  = " << divisaozinha << endl;

//RESULTADO
	cout << "Resultado = " << valor << endl;
}

int main() 
{
  int n=0,menu=0,quantisespecifico=0;
  double media = 0, desvio, mediana = 0;
  double Q1 = 0, Q3 = 0;
  double *pntMedia;
  pntMedia = &media;

  
  cout << "Digite o tamanho do vetor" << endl;
  cin >> n;
 // double v[30]{5.257 , 5.680 , 6.176 , 6.260 , 6.316 , 6.340 , 6.700 , 7.742 , 7.780 , 9.300 , 9.440 ,  10.532 ,  10.767 ,  11.386 , 11.630 , 12.018 , 12.890 , 12.923 , 13.140 , 13.700 , 13.840 , 14.460 , 15.520 , 16.346 , 21.500 , 22.200 , 24.632 , 31.640 , 33.718 , 38.850};
 double v[20]{ 2 , 4, 5, 4, 6, 7, 8, 4, 9, 12, 6, 13, 14, 15, 11, 11, 12, 9, 9, 3};
 double vaux[20];
  //entrada_vetor(v,n);
  bubbleSort(v, n);

  while(menu != 7)
  {
    menu++;

    cout << "Digite o que quer fazer com esses dados" << endl;
    cout << "1 : Imprime Dados" << endl;
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
        calcular_quantis(v, n, 25);
        break;
      }
      case 6:
      {
        calcular_quantis(v, n, 75);
        break;
      }            
      case 7:
      {
        cout << "desligando" << endl;
        break;
      }
      case 8:
      {
        cout << "qual quantis quer calcular? : " << endl;
        cin >> quantisespecifico;
        calcular_quantis(v, n, quantisespecifico);
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


/* 5.257 , 5.680 , 6.176 , 6.260 , 6.316 , 6.340 , 6.700 , 7.742 , 7.780 , 9.300 , 9.440 ,  10.532 ,  10.767 ,  11.386 , 11.630 , 12.018 , 12.890 , 12.923 , 13.140 , 13.700 , 13.840 , 14.460 , 15.520 , 16.346 , 21.500 , 22.200 , 24.632 , 31.640 , 33.718 , 38.850 */

/*3,36 3,62 3,64 3,68 3,7 3,73 3,73 3,81 3,83 3,92
4,08 4,1 4,11 4,12 4,14 4,15 4,15 4,16 4,2 4,36
4,38 4,39 4,39 4,4 4,45 4,47 4,56 4,57 4,6 4,98*/

/*
 double v[20]{4 ,12 ,16 ,12 ,20 ,24, 28, 12, 32, 44, 20, 48, 52, 56, 40, 40, 44, 32, 32, 8};

*/


/*
  int tam;

  if(n % 2 == 0)
    tam = (n/2);    
  else
    tam = n/2;

  double v[tam];

  for(int i = 0; i < tam; i++)
  {
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

  cout << Q1 << endl;*/

#