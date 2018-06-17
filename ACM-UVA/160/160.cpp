#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <iostream>
using namespace std;

#define MAX 100


int esprimo(int numero){

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

  
int main()
{
    int nprimos=0;
    int primos[MAX];
    int tabla[MAX];
    int i,j,k;
    int N;
    #ifndef ONLINE_JUDGE
        close (0); 
        open ("160.in", O_RDONLY);
        close (1); 
        open ("160.out", O_WRONLY | O_CREAT, 0600);
    #endif
    
    for(i=2;i<MAX;i++)
    {
        if(esprimo(i))
        {
            primos[nprimos]=i;
            nprimos++;
        }    
    }    
    
    while(cin >> N)
    {
        int nres=0;
        if(N==0)
                return 0;
        for(i=0;i<nprimos;i++)
                tabla[i]=0;
                
        for(i=2;i<=N;i++)
        {
            int aux=i;
            for(j=0;j<nprimos;j++)
            {
                if(aux%primos[j]==0)
                {
                    aux/=primos[j];
                    if(tabla[j]==0)
                    {
                        nres++;
                    }    
                    tabla[j]++;
                    j=-1;                   
                }    
            }    
        }    
        cout << "\t" << N <<"! =";
        for(i=0;nres>0;i++)
        {
            cout <<"\t" << tabla[i];
            if(tabla[i]>0)
            {
                nres--;
            }    
            if((i+1)%15==0)
                        cout <<"\t"<< endl;
        }    
        cout << endl;
    }    
    
    return 0;
}
