#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <iostream>
using namespace std;

int main()
{
    int i,j,k;
    int num;
    int tam;
    long long int res;
    char cadena[1000];
    
    #ifndef ONLINE_JUDGE
        close (0); 
        open ("575.in", O_RDONLY);
        close (1); 
        open ("575.out", O_WRONLY | O_CREAT, 0600);
    #endif
    
    while(cin >> cadena)
    {
        res=0;
        if(cadena[0]=='0')
            return 0;
            
        tam=strlen(cadena);
        for(i=0;i<tam;i++)
        {
            res+=(cadena[i]-'0')*((int)pow((double)2,(double)(tam-i))-1);
        }    
        cout << res << endl;
    }    
    
    
    return 0;
}
