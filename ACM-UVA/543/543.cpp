#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

#include <iostream>
using namespace std;

#define MAXPRIM 1000001

int lista_primos[MAXPRIM];




int main()
{
	int i,j,k;
	int numero;
	int encontrado;
	
	#ifndef ONLINE_JUDGE

        close (0); 

        open ("543.in", O_RDONLY);

        close (1); 

        open ("543.out", O_WRONLY | O_CREAT, 0600);

    	#endif
	lista_primos[0]=1;
	lista_primos[1]=1;
	
	for(i=2;i<MAXPRIM/2;i++)
	{
		if(lista_primos[i]==0)
		{
			for(j=i*2;j<MAXPRIM;j+=i)
			{
			    lista_primos[j]=1;
			}    
		}
	}
	while(cin >> numero)
	{
		encontrado=0;
		if(numero==0)
			return 0;
		if(lista_primos[numero-2]==0)
        {
		        
                cout << numero << " = " <<2 << " + "<<numero-2<<endl;
            	encontrado=1;	
       	}    	
		for(i=3;i<numero && encontrado==0;i+=2)
		{
		    if(lista_primos[i]==0 && lista_primos[numero-i]==0)
		    {
		        
                cout << numero << " = " <<i << " + "<<numero-i<<endl;
            	encontrado=1;	
         	}  		 
			
		}
		if(encontrado==0)
		{
			cout << "Goldbach's conjecture is wrong." << endl;
		}
		
	}
	
	
	return 0;
}

