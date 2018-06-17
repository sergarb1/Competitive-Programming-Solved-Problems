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
    #ifndef ONLINE_JUDGE
       // close (0); 
       // open (".in", O_RDONLY);
       // close (1); 
       // open (".out", O_WRONLY | O_CREAT, 0600);
    #endif
    long long int ntest,palo,hormigas,minimo,maximo,hor;
    
    cin >> ntest;
    
    while(ntest--)
    {
        cin >> palo >> hormigas;
        minimo=0;maximo=0;
        while(hormigas--)
        {
            cin >> hor;
            if((palo-hor)<hor)
            {
                if(minimo<(palo-hor))
                        minimo=palo-hor;
                if(maximo<hor)        
                        maximo=hor;
            }    
            else
            {
                if(minimo<hor)
                        minimo=hor;
                if(maximo<palo-hor)        
                        maximo=palo-hor;
            }
        
        }
        cout << minimo << " " << maximo << endl;    
    }   
     
    
    return 0;
}
