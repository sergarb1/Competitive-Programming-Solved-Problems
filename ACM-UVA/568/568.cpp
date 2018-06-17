

#include <stdio.h>
#include <iostream>
using namespace std;
int N;
int numero=1;

int main()
{
    int i,j;
    char cadena[100];
	int tam;
	
	while(cin >> N)
	{
	    numero=1;
	    for(i=1;i<=N;i++)
	    {
	         numero*=i;
	         while(numero%10==0)
	         {
	              numero/=10;
             }    
	          numero%=100000;
	     }    
	     numero%=10;
	     sprintf(cadena,"%d",N);
	     tam=strlen(cadena);
	     for(i=tam;i<5;i++)
	           cout << " ";
         cout  << N <<" -> "<< numero << endl;
    }    
    return 0;
}
