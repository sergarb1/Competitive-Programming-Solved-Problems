#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;


int es_primo(int num);

int main()
{
	int i,j,k;
	int numero,npares;
	#ifndef ONLINE_JUDGE
  	//	close (0); open ("myprog.in", O_RDONLY);
  	//	close (1); open ("myprog.out", O_WRONLY | O_CREAT, 0600);
	#endif 

	while(cin >> numero)
	{
		npares=0;
		if(numero==0)
			return 0;
		
		if(numero==4)
		{
			npares=1;
		}
		else if(es_primo(numero-2))
		{
			npares=1;
		}
		
		for(i=3;i+i<=numero;i+=2)
		{
			for(j=i;j+i<=numero;j+=2)
			{
				if(j+i==numero)
				{
					if(es_primo(j) && es_primo(i))
						npares++;
				}
			}
		}
		cout << npares << endl;
		
	}

	return 0;
}

int es_primo(int num)
{
	int i;
	if(num==2)
		return 1;
	if(num%2==0)
		return 0;
	int raiz=(int) sqrt((double)num);
	for(i=3;i<=raiz;i+=2)
	{
		if(num%i==0)
			return 0;
	}
	return 1;
}
