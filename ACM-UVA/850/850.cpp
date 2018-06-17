#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{

	char tabla[1000];
	char cadena_romper[100]="the quick brown fox jumps over the lazy dog";
	
	char cadena[120][100];
	char res[100];
	int ncasos;
	int i;
	cin >> ncasos;
	cin.getline(cadena[0],90,'\n');
	cin.getline(cadena[0],90,'\n');

	for(int j=0;j<ncasos;j++)
	{
		if(j!=0)
			cout << endl;
		int k=0;
		int hay_sol=0;
		while(cin.getline(cadena[k],90,'\n'))
		{
			if(strcmp(cadena[k],"")==0)
				break;
			if(strlen(cadena[k])==43 && !hay_sol)
			{
				hay_sol=1;
				for(i=97;i<=122;i++)
				{
					tabla[i]=0;
				}
				for(i=0;i<43 && hay_sol;i++)
				{
					if(tabla[cadena[k][i]]==0 || tabla[cadena[k][i]]==cadena_romper[i])
					{
						tabla[cadena[k][i]]=cadena_romper[i];
					}
					else
						hay_sol=0;
				}
			}
			k++;
		}
		if(!hay_sol)
		{	
			cout << "No solution." << endl;
		}
		else
		{
			for(int m=0;m<k;m++)
			{
				int tam=strlen(cadena[m]);
				for(int n=0;n<tam;n++)
				{
					cout << tabla[cadena[m][n]];
				}
				cout << endl;
			}
		}
	}	
	return 0;
}
