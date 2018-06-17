/*   @JUDGE_ID:   32131ZP   100   C   "Dynamic Programming"   */ 

#include <stdio.h>

int soluciona(int i,int j);
int ciclos(int x);

void main()
{
	int i,j,k;
	char temp;
	while(!feof(stdin))
	{

		scanf("%d",&i);
		scanf("%d",&j);
		scanf("%c",&temp);
		
		if(feof(stdin)) break;
		
		if(i>j)
		{
			k=soluciona(j,i);
		
		}
		else
		{
			k=soluciona(i,j);
		
		}	
		printf("%d %d %d\n",i,j,k);
				
	}
}

int soluciona(int i,int j)
{
	int k=0,mayor_k=0;	
	int x=0;

	for(x=i;x<=j;x++)
	{
		k=ciclos(x);
		if(k>mayor_k)
		{
			mayor_k=k;
		}
	}	
	return mayor_k;
}


int ciclos(int x)
{
	int vueltas=1;
	
	while(x!=1)
	{
		if(x%2==0)
		{
			x=x>>1;
		}
		else
		{
			x=(x*3)+1;
		}
		vueltas++;
	}
	return vueltas;
		
}
