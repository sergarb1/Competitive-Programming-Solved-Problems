#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <iostream>
using namespace std;

#define MAX 20

int main()
{
    
    int i,j;
    int n_test,n_gran;
    double metros;
    double animales;
    double premios;
    double suma;
    
    #ifndef ONLINE_JUDGE
        close (0); 
        open ("10300.in", O_RDONLY);
        close (1); 
        open ("10300.out", O_WRONLY | O_CREAT, 0600);
    #endif
    
    cin >> n_test;
    
    for(i=0;i<n_test;i++)
    {
        suma=0;
        cin >> n_gran;
        for(j=0;j<n_gran;j++)
        {
             cin >> metros;
             cin >> animales;
             cin >> premios;
             suma+=((metros/animales)*premios)*animales; 
             
        }    
        cout << suma << endl;
    }    
    
    return 0;
}
