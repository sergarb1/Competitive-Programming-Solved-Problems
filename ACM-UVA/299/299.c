#include <stdio.h>

	
	int numero_casos;
	int longitud;
	int tren[50];
	int intercambios;
	
	void burbuja();

int main()
{

	int i,j,k;
	
	scanf("%d",&numero_casos);

	for(i=0;i<numero_casos;i++)
	{
		intercambios=0;
		scanf("%d",&longitud);
		
		for(j=0;j<longitud;j++)
		{
			scanf("%d",&tren[j]);
		}
		burbuja();
		printf("Optimal train swapping takes %d swaps.\n",intercambios);
	}
	return 0;
	
}

void burbuja()
{
	int i=0,j=0;
	int aux;
	
	/*for(i=1;i<longitud;i++)
	{
		for(j=0;j<longitud-1;j++)
		{
			if(tren[j]>tren[j+1])
			{
				aux=tren[j];
				tren[j]=tren[j+1];
				tren[j+1]=aux;
				intercambios++;
			}
		}
	}*/
	
	for(i=longitud-1;i>=1;i--)
	{
		for(j=longitud-2;j>=0;j--)
		{
			if(tren[j]>tren[j+1])
			{
				aux=tren[j];
				tren[j]=tren[j+1];
				tren[j+1]=aux;
				intercambios++;
			}
		}
	}
	

	
	
}
