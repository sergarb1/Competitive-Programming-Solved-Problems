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
    
    int numeros[256];
    int i,j;
    char cadena[31];
    numeros['A']=2;
    numeros['B']=2;
    numeros['C']=2;
    numeros['D']=3;
    numeros['E']=3;
    numeros['F']=3;
    numeros['G']=4;
    numeros['H']=4;
    numeros['I']=4;
    numeros['J']=5;
    numeros['K']=5;
    numeros['L']=5;
    numeros['M']=6;
    numeros['N']=6;
    numeros['O']=6;
    numeros['P']=7;
    numeros['Q']=7;
    numeros['R']=7;
    numeros['S']=7;
    numeros['T']=8;
    numeros['U']=8;
    numeros['V']=8;
    numeros['W']=9;
    numeros['X']=9;
    numeros['Y']=9;
    numeros['Z']=9;
    while(cin >> cadena)
    {
        int tam=strlen(cadena);
        
        for(i=0;i<tam;i++)
        {
            if(cadena[i]>='A' && cadena[i]<='Z')
            {
                cout << numeros[cadena[i]];
            }    
            else
            {
                cout << cadena[i];
            }    
        }    
        cout << endl;
    }    
    return 0;
}
