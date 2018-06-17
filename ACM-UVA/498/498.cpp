#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <iostream>
#include <ctype.h>
#include <math.h>

using namespace std;


char linea[3001];
long long int numeros[3000];

int main()
{
	int i,j,k;
	#ifndef ONLINE_JUDGE
  		close (0); open ("498.in", O_RDONLY);
  		//close (1); open ("498.out", O_WRONLY | O_CREAT, 0600);
	#endif 
	long long int res=0;
	while(!feof(stdin))
	{
		char *str;
		gets(linea);
		str=linea;
		int nexp;
		nexp=0;
		while(sscanf(str,"%lld",&numeros[nexp])==1)
		{
			while(isdigit(str[0]) || str[0]=='-')
				str++;
			nexp++;
			while(str[0]==' ')
				str++;
		}
		if(feof(stdin))
			break;
		gets(linea);

		str=linea;
		long long int val=0;
		int primer_caso=1;
		while(sscanf(str,"%lld",&val)==1)
		{

			while(isdigit(str[0]) || str[0]=='-')
				str++;
			res=0;
	
			for(i=0;i<nexp;i++)
			{
				//cout << numeros[i] << " " << i << endl;
				res+=((long long int)pow((double)val,(double)nexp-1-i)*numeros[i]);
				//cout << "exponente " << nexp-1-i << " res :  " << res << endl;
			}
			if(primer_caso)
			{
				cout << res;
				primer_caso=0;
			}
			else
				cout << " " <<res;
			while(str[0]==' ')
				str++;
		}
		cout << endl;
	
	}

	return 0;
}
