#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <iostream>
using namespace std;

int main()
{
    int i,j,k;
    long long int tabla[256];
    int final_fichero=0;
    
    #ifndef ONLINE_JUDGE
        close (0); 
        open ("499.in", O_RDONLY);
        close (1); 
        open ("499.out", O_WRONLY | O_CREAT, 0600);
    #endif
    while(final_fichero==0)
    {
        char c;
        long long int max_fr=0;
        
        for(i='A';i<='z';i++)
        {
            tabla[i]=0;
        }    
        final_fichero=1;
        while(cin.get(c))
        {
            if(c=='\n')
            {
                final_fichero=0;
                break;
            }    
            if((c>='A' && c<='Z') || (c>='a' && c<='z'))
            {
                tabla[c]++;
                if(tabla[c]>max_fr)
                {
                    max_fr=tabla[c];
                }    
            }    
        }    
        if(max_fr==0)
        {
            cout << endl;
            continue;
        }    
        
        for(i='A';i<='Z';i++)
        {
            if(tabla[i]==max_fr)
            {
                cout << (char)i;
            }    
        }  
        for(i='a';i<='z';i++)
        {
            if(tabla[i]==max_fr)
            {
                cout << (char)i;
            }    
        }  
        
        cout << " " << max_fr << endl;
        
    }    
    
    
    return 0;
}
