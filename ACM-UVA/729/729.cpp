#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <iostream>
using namespace std;
#define MAX 16

char cadena[MAX+1];
    int N,H;

void pon_unos(int pos,int nunos)
{
    int i,j;
    cadena[pos]='1';
    if(nunos==H)
    {
        for(i=0;i<N;i++)
        {
            cout << cadena[i] ;
        }    
        cout << endl;
    }
    else
    {
        for(i=N-1;i>=pos+1;i--)
        {
            pon_unos(i,nunos+1);
        }    
    }
    
    cadena[pos]='0';
}    

int main()
{
    int i,j;
    #ifndef ONLINE_JUDGE
        close (0); 
        open ("729.in", O_RDONLY);
        close (1); 
        open ("729.out", O_WRONLY | O_CREAT, 0600);
    #endif
    int ntest;
    cin >> ntest;
    
    while(ntest--)
    {
        cin >> N >> H;
        cadena[N]=0;
        for(i=0;i<N;i++)
                cadena[i]='0';
        
        for(i=N-1;i>=0;i--)
        {
            pon_unos(i,1);
        }    
        cout << endl;
    }    
    
    return 0;
}
