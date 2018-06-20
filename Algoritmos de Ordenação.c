#include<stdio.h>
#include<stdlib.h>

void bubble_sort(int vetor[], int quantidade);
void insertion_sort(int* vetor, int tamanho);
void selection_sort(int vetor[], int tamanho);
void imprimir(int vetor[]);
void quick_sort(int *vetor, int inicio, int fim);
void quick_Sort(int vetor[], int inicio, int fim);
int repita = 0;

int main()
{
	printf("Lista: ");
	
	int L[10] = {7, 1, 5, 3, 6, 9, 2, 8, 10, 4};
		
	imprimir(L);

	//selection_sort(L, 10);
	//bubble_sort(L, 10);
	//insertion_sort(L, 10);
	//quick_Sort(L, 0, 10);
	
	
	return 0;
}

void quick_Sort(int vetor[], int inicio, int fim)
{
	puts("\nQuick Sort:\n");
	imprimir(vetor);
	puts("");
	quick_sort(vetor,0,10);
	printf("\nRepetiu a lista %i vezes para ordenar.\n\n", repita);
}

void quick_sort(int *vetor, int inicio, int fim)
{
	int i, n, pivo, aux;
 
   	i = inicio;
   	n = fim-1;
   	
   	pivo = vetor[(inicio + fim) / 2]; //Meio
   	
	do
   	{
    	while(pivo > vetor[i])
    	{
    		i++;
		}
		
      	while(pivo < vetor[n])
      	{
      		n--;
		}

      	if(n >= i)
      	{
	        aux = vetor[i];
	        vetor[i] = vetor[n];
	        vetor[n] = aux;
	        i++;
	        n--;
      	}
      	
      	repita++;
      	imprimir(vetor);
   }
   while(n >= i);

   	if(inicio < n)
   	{
   		quick_sort(vetor, inicio, n);
   	}
   	if(i < fim)
   	{
   		quick_sort(vetor, i, fim);
   	}   
}

void selection_sort(int vetor[], int tamanho)
{
    puts("\nSelection Sort:\n");
	imprimir(vetor);
	puts("");
	
	int i, n, posicaoValorMinimo, aux, repita = 0;
 
    for(i = 0; i < tamanho-1; i++)
    {
        posicaoValorMinimo = i;
        
        for(n = i+1; n < tamanho; n++)
        {
        	repita++;
        	if (vetor[posicaoValorMinimo] > vetor[n])
        	{
        		posicaoValorMinimo = n;
        	}
 		}
    	
		if(i != posicaoValorMinimo) 
		{
       		aux = vetor[i];
       		vetor[i] = vetor[posicaoValorMinimo];
       		vetor[posicaoValorMinimo] = aux;
       }
       imprimir(vetor);
    }
    printf("\nRepetiu a lista %i vezes para ordenar.\n\n", repita);
}

void insertion_sort(int vetor[], int tamanho) 
{
	puts("\nInsertion Sort:\n");
	imprimir(vetor);
	puts("");
	
	int i, n, valorAtual, aux;
	int repita = 0;
	
  	for(i = 1; i < tamanho; i++) 
  	{
    	valorAtual = vetor[i];
    	
    	n = i - 1;
    	
		while(n >= 0 && vetor[n] > valorAtual)
		{
			repita++;
			vetor[n+1] = vetor[n];
			n--;
		}
    	
    	vetor[n+1] = valorAtual;
    	
    	imprimir(vetor);
	}
	printf("\nRepetiu a lista %i vezes para ordenar.\n\n", repita);
}

void bubble_sort( int vetor[], int quantidade )
{
	printf("\nBubble Sort: \n\n");
	imprimir(vetor);
	puts("");
	
	int n;
	int aux;
	int flag = 0;
	int i = quantidade-1;
	int repita = 0;
	
	do{
		flag = 0;
		for(n = 0; n < i; n++)
		{
			if(vetor[n] > vetor[n+1])
			{
				flag = 1;
				aux = vetor[n];
				vetor[n] = vetor[n+1];
				vetor[n+1]=aux;
			}
			repita++;
		}
		imprimir(vetor);
		i--;	 
	}
	while(flag != 0);
	
	printf("\nRepetiu a lista %i vezes para ordenar.\n\n", repita);
}

void imprimir(int vetor[])
{
	for(int i = 0; i < 9; i++)
	{
		printf("%i - ", vetor[i]);
	}
	printf("%i\n", vetor[9]);
}

