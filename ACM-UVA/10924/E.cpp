#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <iostream>
using namespace std;

int es_primo(long long int numero);

int main()
{
    char cadena[22];
    
    while(cin >> cadena)
    {
        int tam=strlen(cadena);
        long long int suma=0;
        for(int i=0;i<tam;i++)
        {
            if(cadena[i]>='a' && cadena[i]<='z')
            {
                suma+=(cadena[i]-'a'+1);
            }    
            else if(cadena[i]>='A' && cadena[i]<='Z')
            {
                suma+=(cadena[i]-'A'+27); 
            }    
        }   
        if(es_primo(suma))
        {
            cout << "It is a prime word." << endl;
        }    
        else
        {
            cout << "It is not a prime word." << endl;
        }    
    }    
    
    
    return 0;
}


int es_primo(long long int numero){

	int i=0;

	if(numero == 2)
		return 1;

	if(numero%2 == 0)
		return 0;

	for(i=3; i*i<= numero;i+=2)
    	{
		if(numero%i == 0)
	    		return 0;
    	}
	return 1;

}
