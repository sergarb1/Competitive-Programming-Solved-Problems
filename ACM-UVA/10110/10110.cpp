#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <math.h>
#include <fcntl.h>

#include <iostream>
using namespace std;

int main()
{
    double numero,raiz;
    /*#ifndef ONLINE_JUDGE
        close (0); 
        open (".in", O_RDONLY);
        close (1); 
        open (".out", O_WRONLY | O_CREAT, 0600);
    #endif
    */
    while(cin >> numero)
    {
        if(numero==0.0)
                return 0;
        raiz=sqrt(numero);
        if((raiz-(long long int)raiz)==0)
                cout << "yes" << endl;
        else
                cout << "no" << endl;
    }    
    return 0;
}
