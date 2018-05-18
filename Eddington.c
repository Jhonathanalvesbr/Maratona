#include<stdio.h>
#include<stdlib.h>

int main ()
{
	int dias = 0, km[1000], x = 0, eddington = 0, semPedal = 0, i = 0;
	float media = 0, respota[1000];
	
	while(1)
	{
		scanf("%i", &dias);
		
		if(dias == 0)
		{
			break;
		}
		
		eddington = 0;
		x = 0;
		media = 0;
		semPedal = 0;
		
		for(x; x < dias; x++)
		{
			
			scanf("%i", &km[x]);
			
			if(dias == 1 )
			{
				break;
			}
			
			if(eddington > km[x] || eddington == 0)
			{
				
				if(km[x] == 0)
				{
					semPedal++;
				}
				
				
				if(km[x] > 0)
				{
					eddington = km[x];
				}
				
			}
			
			media += km[x];
			
		}
		
		if(dias == 1)
		{
			respota[i++] = km[x];
		}
		else
		{
			respota[i++] = ((media-eddington))/(dias-semPedal);
		}
	}
	
	x = 0;
	
	for(x; x < i; x++)
	{
		if(respota[x] > -1){
			printf("%.0f\n", respota[x]);
		}
		else{
			printf("0\n");
		}
	}
	
	return 0;
}
