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
    
    int numero,temp,temp_ant,linea;
    int n1,n2;
    #ifndef ONLINE_JUDGE
        close (0); 
        open ("264.in", O_RDONLY);
        close (1); 
        open ("264.out", O_WRONLY | O_CREAT, 0600);
    #endif
    
    while(cin >> numero)
    {
            temp=0;
            linea=1;
         
                
            while((temp+linea)<numero)
            {
                temp+=linea;
                linea++;
            }   
            if(linea%2==0)
            {
                
                n1=1;
                n2=linea;
            
                for(i=1;i<numero-temp;i++)
                {
                    n1++;
                    n2--;
                }  
            }
            else
            {
                
                n1=linea;
                n2=1;
            
                for(i=1;i<numero-temp;i++)
                {
                    n1--;
                    n2++;
                }
            }          
            
            cout << "TERM " << numero << " IS " << n1 << "/" << n2 << endl;
    }    
    
    
    return 0;
}
