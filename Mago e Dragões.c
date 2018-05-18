#include<stdio.h>
#include<stdlib.h>

void quick_sort(int *a, int left, int right) {
	int i, j, x, y;
	
	i = left;
	j = right;
	x = a[(left + right) / 2];
	
	while(i <= j) {
		while(a[i] < x && i < right) {
			i++;
		}
		while(a[j] > x && j > left) {
			j--;
		}
		if(i <= j) {
			y = a[i];
			a[i] = a[j];
			a[j] = y;
			i++;
			j--;
		}
	}
	
	if(j > left) {
		quick_sort(a, left, j);
	}
	if(i < right) {
		quick_sort(a, i, right);
	}
}


int main ()
{
	int feitico = 0, magia = 0; //Feiticos que o mago conhece, Quantidade de Magia que ira usar
	int hit = 0, y = 0, i = 0, x = 0; //Contadores
	int poder = 0; //Possivel escolha de poder para matar o dragao
	int flag = 0; //Bandeira verdadeiro ou falso
	int *Magias = (int*) malloc(10000000*sizeof(int));
	
	while(1)
	{
	
		scanf("%i %i", &feitico, &magia);
		
		if(feitico == 0 && magia == 0)
		{
			break;
		}
		
		x = 0;
		
		for(i = 0; i < feitico; i++)
		{
			scanf("%i", &Magias[i]); //So adiciona ao vetor se não existir a magia

		}
		
		quick_sort(Magias, 0, i);
		
		
		hit = 0;
			for(x = i-magia; x < i; x++) 
			{
				if(Magias[hit]+Magias[x] > 0)
				{
					printf("%i", Magias[x]); //Printa Resposta Positivo;
					if(x == feitico)
					{
						break;
					}
					printf(" ");
				}
				else
				{
					printf("%i", Magias[hit++]); //Printa Resposta NEGATIVO;
					if(x == feitico)
					{
						break;
					}
					printf(" ");
				}
			}
			puts("");
		}
		
	return 0;
}
