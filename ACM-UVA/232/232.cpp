#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdlib.h> 
#include <iostream>

using namespace std; 


char sopa[20][20];
int num[20][20];
int x,y;

void generanum()
{
	int n=1;
	int i,j,k;
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			num[i][j]=0;
		}
	}

	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			if(sopa[i][j]=='*')
				continue;
			if(i==0)
			{
				num[i][j]=n;
				n++;
				
			}
			else if(j==0)
			{
				num[i][j]=n;
				n++;
			}
			else if(i-1>=0 && sopa[i-1][j]=='*')
			{
				num[i][j]=n;
				n++;
			}
			else if(j-1>=0 && sopa[i][j-1]=='*')
			{
				num[i][j]=n;
				n++;
			}
		}
	}

}

void imprimenum()
{
	int i,j;
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			printf("%d ",num[i][j]);
		}
		printf("\n");
	}
		printf("\n");
		printf("\n");
}
void imprime(int n)
{
	int i,j,k;
	int tampab;
	int enpalabra;
	
	char palabra[20];
	int nast=0;
	if(n>1)
		printf("\n");
	printf("puzzle #%d:\n",n);
	printf("Across\n");
	int pos=0;
	for(i=0;i<x;i++)
	{
		tampab=0;
		enpalabra=0;
		pos=0;
		for(j=0;j<y;j++)
		{
			if(sopa[i][j]=='*')
			{
				nast++;
				if(enpalabra==1)
				{
					palabra[tampab]=0;
					tampab=0;
					//printf("%d %d %d %d\n\n",x,i,j,nast);
					printf("%3d.%s\n",num[i][pos],palabra);
					enpalabra=0;
					
				}
					pos=j+1;
				
			}
			else
			{
				palabra[tampab++]=sopa[i][j];
				enpalabra=1;
			}
		}
		if(enpalabra==1)
		{
			palabra[tampab]=0;
			tampab=0;
			//printf("%d %d %d %d\n\n",x,i,j,nast);
			printf("%3d.%s\n",num[i][pos],palabra);
			enpalabra=0;
		}
	}
	printf("Down\n");
	enpalabra=0;
	nast=0;
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			if(sopa[i][j]=='*')
			{
				nast++;
				continue;
			}
			if(i-1<0 || sopa[i-1][j]=='*' )
			{
				tampab=0;
				enpalabra=1;
				for(k=i;k<x;k++)
				{
					if(sopa[k][j]=='*')
					{
						enpalabra=0;	
						palabra[tampab]=0;
						//printf("%d %d %d %d\n\n",x,i,j,nast);
						printf("%3d.%s\n",num[i][j],palabra);
						break;
					}
					else
					{
						palabra[tampab++]=sopa[k][j];
					}
				}
				if(enpalabra==1)
				{
					enpalabra=0;	
					palabra[tampab]=0;
					//printf("%d %d %d %d\n\n",x,i,j,nast);
					printf("%3d.%s\n",num[i][j],palabra);
				}
			}
		}
	}
}

int main() 
{ 
  int i,j,k;

  #ifndef ONLINE_JUDGE 
          close (0); open ("232.in", O_RDONLY); 
          close (1); open ("232.out", O_WRONLY | O_CREAT, 0600); 
  #endif 
	int npuzzle=1;
	while(cin >> x)
	{
		if(x==0)
			return 0;
		cin >> y;
		char tmp;
		cin.get(tmp);
		for(i=0;i<x;i++)
		{
			cin.getline(sopa[i],15,'\n');
		}
		generanum();
		//imprimenum();
		imprime(npuzzle);
		npuzzle++;
	}

  return 0;
}
