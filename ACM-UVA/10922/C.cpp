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
    int i,j;
    char numero[2000],num_org[2000];
    
    while(cin >> numero)
    {
        
        long long int suma=0;
        int recursion=0;
        
        //cout << numero;
        strcpy(num_org,numero);
        if(numero[0]=='0')
            return 0;
        do
        {
            int tam=strlen(numero);
            suma=0;
            for(i=0;i<tam;i++)
            {
                suma+=numero[i]-'0';
            }    
            if(suma>9)
            {
               sprintf(numero,"%lld",suma);
            }    
            recursion++;
        }while(suma>9);    
        if(suma==9)
        {
            cout  <<num_org<< " is a multiple of 9 and has 9-degree "<< recursion <<".";
        }
        else
        {
            cout <<num_org<< " is not a multiple of 9.";
        }
        cout << endl;
                
    }    
    
    return 0;
}
