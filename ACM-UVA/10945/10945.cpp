#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <iostream>
using namespace std;

int es_palindromo(char *c)
{
    int tam=strlen(c);
    int i,j;
    
    for(i=0,j=tam-1;i<j;i++,j--)
    {
        if(c[i]!=c[j])
                return 0;
    }    
    return 1;
}    

int main()
{
    char palabra[1000000];
    char temp;
    int tam_pab;
    #ifndef ONLINE_JUDGE
        close (0); 
        open ("C.in", O_RDONLY);
        close (1); 
        open ("C.out", O_WRONLY | O_CREAT, 0600);
    #endif
    tam_pab=0;
    while(cin.get(temp))
    {
        if((temp>='A' && temp <='Z') )
        {
            palabra[tam_pab++]=temp;
        }    
        else if(temp>='a' && temp <='z')
        {
            
            palabra[tam_pab++]=temp-32;
        }    
        else if(temp=='\n')
        {
            palabra[tam_pab]=0;
            if(strcmp(palabra,"DONE")==0)
            {
                return 0;
            }    
            tam_pab=0;
            if(es_palindromo(palabra))
            {
                cout << "You won't be eaten!" << endl;
            }    
            else
            {
                cout << "Uh oh.."<<endl;
            }    
        }    
    }    
    
    return 0;
}
