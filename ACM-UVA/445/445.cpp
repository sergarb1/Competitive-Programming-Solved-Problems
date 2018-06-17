#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <iostream>
using namespace std;

#define MAX 200

int main()
{
    char cadena[MAX+1];
    int i,j,tam;
    #ifndef ONLINE_JUDGE
        close (0); 
        open ("445.in", O_RDONLY);
        close (1); 
        open ("445.out", O_WRONLY | O_CREAT, 0600);
    #endif
    
    while(cin.getline(cadena,MAX))
    {
       tam=strlen(cadena);
       if(strcmp(cadena,"")==0)
       {
           cout << endl << endl ;
           continue;
       }    
       for(i=0;i<tam;i++)
       {
           int num_p=0;
           if(cadena[i]=='!')
           {
               cout << endl;
               continue;
           }    
           while(cadena[i]>='0' && cadena[i]<='9')
           {
               num_p+=cadena[i]-'0';
               i++;
           }   
           for(j=0;j<num_p;j++)
           {
               if(cadena[i]=='b')
               {
                   cout << ' ';
               }    
               else if((cadena[i]>='A' && cadena[i]<='Z') || (cadena[i]=='*'))
               {
                   cout << cadena[i];
               }    
           }   
                        
           
       }    
       cout << endl;
       
    }
    
    return 0;
}
