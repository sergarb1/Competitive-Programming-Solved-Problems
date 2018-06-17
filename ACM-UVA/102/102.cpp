#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

#include <iostream>
using namespace std;

#define INFINITO 2147483647


int cont[3][3];

char contenedores[4]={'B','C','G',0};

char resultado[4];
char res_temp[4];

int nmov=INFINITO;

int min_mov(int a,int b, int c);



int main()
{
	int i,j,k;
	int movtemp;
	
	#ifndef ONLINE_JUDGE

        close (0); 

        open ("102.in", O_RDONLY);

        close (1); 

        open ("102.out", O_WRONLY | O_CREAT, 0600);

    	#endif
	
	while(1)
	{
		nmov=INFINITO;
		
			
		for(i=0;i<3;i++) /* Te dan BGC y COGEMOS BCG*/
		{
			scanf("%d",&cont[i][0]);
			scanf("%d",&cont[i][2]);
			if(feof(stdin))
				return 0;
		
			scanf("%d",&cont[i][1]);
		}
	
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				if(j!=i)
				{
					for(k=0;k<3;k++)
					{
						if(k!=j && k!=i)
						{
							movtemp=min_mov(i,j,k);
							//printf("%c%c%c %d\n",contenedores[i],contenedores[j],contenedores[k],movtemp);
							if(movtemp<nmov)
							{
								nmov=movtemp;
								resultado[0]=contenedores[i];
								resultado[1]=contenedores[j];
								resultado[2]=contenedores[k];
								resultado[3]=0;
							}
						}
					}
				}
			}
			
		}
		if(nmov==INFINITO)
		{
			nmov=0;
			resultado[0]='B';
			resultado[1]='C';
			resultado[2]='G';
			resultado[3]=0;
		}
		printf("%s %d\n",resultado,nmov);
		
	}
	return 0;
}


int min_mov(int a,int b, int c)
{
	int movimientos=0;
	
	movimientos+=cont[1][a]+cont[2][a];
	movimientos+=cont[0][b]+cont[2][b];
	movimientos+=cont[0][c]+cont[1][c];
	
	return movimientos;
}
