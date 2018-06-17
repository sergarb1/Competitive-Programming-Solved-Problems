#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct cad
{
	char c[60];
	int pos;
	int valor;
}cadena[120];

int ordenar(const void *a,const void *b)
{
	struct cad x=(*(struct cad *)a);
	struct cad y=(*(struct cad *)b);
	if(x.valor!=y.valor)
		return x.valor-y.valor;
	else
		return x.pos-y.pos;
	
}

int main()
{

#ifndef ONLINE_JUDGE
  close (0); open ("612.in", O_RDONLY);
  close (1); open ("612.out", O_WRONLY | O_CREAT, 0600);
#endif 
	int i,j,k,l;
	int ntest;
	cin >> ntest;
	int n,m;
	// Caracter final de linea
	cin.getline(cadena[0].c,55);
	for(i=0;i<ntest;i++)
	{
		//linea en blanco
		cin.getline(cadena[0].c,55);
		cin >> n >> m;
		
		// Caracter final de linea
		cin.getline(cadena[0].c,55);

		for(j=0;j<m;j++)
		{
			cin.getline(cadena[j].c,55);
			cadena[j].pos=j;
			cadena[j].valor=0;
			for(k=0;k<n;k++)
			{
				for(l=k+1;l<n;l++)
				{
					if(cadena[j].c[l]<cadena[j].c[k])
						cadena[j].valor++;
				}
			}
		}
		qsort(cadena,m,sizeof(cadena[0]),ordenar);
		for(j=0;j<m;j++)
		{
			cout << cadena[j].c << endl;
		}
	}

	return 0;
}
