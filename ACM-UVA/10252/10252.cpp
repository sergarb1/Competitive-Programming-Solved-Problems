#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdlib.h> 
#include <iostream>

using namespace std; 

int ordenar(const void *a,const void *b)
{
	char *x=(char*)a;
	char *y=(char*)b;
	return x[0]-y[0];
}

int main() 
{ 
  int i,j,k;

  #ifndef ONLINE_JUDGE 
  //        close (0); open ("10252.in", O_RDONLY); 
  // 102        close (1); open ("10252.out", O_WRONLY | O_CREAT, 0600); 
  #endif 

	char cad1[10000],cad2[10000],coincidencia[1000];

	while(cin.getline(cad1,9998,'\n'))
	{
		cin.getline(cad2,9998,'\n');
		int tam1=strlen(cad1);
		int tam2=strlen(cad2);

		//cout << "Cad1 : " << cad1 << endl;
		//cout << "Cad2 : " << cad2 << endl;
		qsort(cad1,tam1,sizeof(cad1[0]),ordenar);
		qsort(cad2,tam2,sizeof(cad2[0]),ordenar);
		int puncoi=0;
		int p1=0,p2=0;
		//cout << "Cad1 : " << cad1 << endl;
		//cout << "Cad2 : " << cad2 << endl;
		while(p1<tam1 && p2<tam2)
		{
			if(cad1[p1]==cad2[p2])
			{
				coincidencia[puncoi++]=cad1[p1];
				p1++;
				p2++;
			}
			else if(cad1[p1]<cad2[p2])
			{
				p1++;
			}
			else if(cad1[p1]>cad2[p2])
			{
				p2++;
			}
		}
		coincidencia[puncoi]=0;
		cout << coincidencia << endl;
	}
  return 0;
}
