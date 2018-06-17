#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <iostream>
using namespace std;

#define MAX_GRUPO 10
#define MAX_NAME 13


int devuelve_id(char *c);

char componentes[MAX_GRUPO][MAX_NAME];
char temp[MAX_NAME];
long long int dinero[MAX_GRUPO];
long long int tam_grupo,nper,ingreso,pos;
long long int cant;

int main()
{
    int i,j;
    
    
    #ifndef ONLINE_JUDGE
        close (0); 
        open ("119.in", O_RDONLY);
        close (1); 
        open ("119.out", O_WRONLY | O_CREAT, 0600);
    #endif
    char presentacion=0;
    
    while(cin >> tam_grupo)
    {
        if(presentacion==0)
                presentacion=1;
        else
                cout << endl;
        
        for(i=0;i<tam_grupo;i++)
        {
            dinero[i]=0;
            cin >> componentes[i];
        } 
        for(i=0;i<tam_grupo;i++)
        {
           cin >> temp;
           cin >> cant;
           cin >> nper;
           if(cant==0 || nper==0)
           {
                for(j=0;j<nper;j++)
                      cin >> temp;         
                continue;
           }    
           ingreso=cant%nper;
           pos=devuelve_id(temp);
           dinero[pos]-=(cant-ingreso);
           cant-=ingreso;
           ingreso=cant/nper;
           for(j=0;j<nper;j++)
           {
                cin >> temp;
                pos=devuelve_id(temp);
                dinero[pos]+=ingreso;
           }    
        
        
        }    
        for(i=0;i<tam_grupo;i++)
        {
            cout << componentes[i] << " " << dinero[i] << endl;
        }    
    }    
    
    
    return 0;
}

int devuelve_id(char *c)
{
    int i;
    for(i=0;i<tam_grupo;i++)
    {
        if(strcmp(c,componentes[i])==0)
                return i;
    }    
    return -1;
}    
