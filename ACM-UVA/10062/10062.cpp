#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <iostream>
using namespace std;
#define MAX 1001

int main()
{
    int i,j;
    char cadena[MAX];
    
    #ifndef ONLINE_JUDGE
        close (0); 
        open ("10062.in", O_RDONLY);
        close (1); 
        open ("10062.out", O_WRONLY | O_CREAT, 0600);
    #endif
    
    while(cin.getline(cadena,MAX))
    {
        int nfrec=0;
        int tabla[256];
        int tam=strlen(cadena);
        
        for(i=0;i<256;i++)
                tabla[i]=0;
        for(i=0;i<tam;i++)
        {
            if(cadena[i]!='\n' && cadena[i]!='\r')
            {
                if(tabla[cadena[i]]==0)
                    nfrec++;
                tabla[cadena[i]]++;
            }    
        }    
        
        for(i=1;i<MAX && nfrec>0;i++)
        {
            for(j=128;j>=32;j--)
            {
                if(tabla[j]==i)
                {
                    cout << j << " " << i << endl;
                    nfrec--;
                }    
            }    
        }    
        cout <<endl;
        
    }    
    
    return 0;
}
