#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <iostream>
using namespace std;

int es_primo(int numero);

int main()
{
    int i,j,k;
    int centro;
    int empieza,final;
    int tam_list;
    int lista_prim[1000];
    int N,C;
    int limite;
    #ifndef ONLINE_JUDGE
        close (0); 
        open ("406.in", O_RDONLY);
        close (1); 
        open ("406.out", O_WRONLY | O_CREAT, 0600);
    #endif
    
    while(cin >> N)
    {
        if(!(cin >> C))
                return 0;
        
        tam_list=0;
        if(N>=1)
        
        {
            lista_prim[tam_list]=1;
            tam_list++;
        }
        if(N>=2)
        {    
            lista_prim[tam_list]=2;
            tam_list++;
        }    
            
        for(i=3;i<=N;i+=2)
        {
            if(es_primo(i))
            {
                lista_prim[tam_list]=i;
                tam_list++;
            }        
        }    
        
        tam_list--;
        
        centro=tam_list/2;
        
        if(tam_list%2==0) // Deberia ser impar, pero como va invertido...  Este es (C*2)-1       
        {
            empieza=centro-(C-1);
            final=centro+(C-1);
        }
        else // (C*2)
        {
            empieza=centro-(C-1);
            final=centro+1+(C-1);
        }        
        if(final>tam_list)
        {
            empieza=0;
            final=tam_list;
        }    
        
        cout << N << ' ' << C << ':';
        
               
        for(i=empieza;i<=final;i++)
        {
            cout << ' ' << lista_prim[i];
        }        
        cout << endl << endl;
            
    }
    
    return 0;
}

int es_primo(int numero){

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
