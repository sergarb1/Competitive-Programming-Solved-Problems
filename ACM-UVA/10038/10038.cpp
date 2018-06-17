#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <iostream>
using namespace std;

#define MAX 3000

int main()
{
    int i,j,k;
    int n;
    int a,b,res;
    int es_jolly;
    int tabla[MAX+1];
    
    #ifndef ONLINE_JUDGE
        close (0); 
        open ("10038.in", O_RDONLY);
        close (1); 
        open ("10038.out", O_WRONLY | O_CREAT, 0600);
    #endif
    
    while(cin >> n)
    {
        cin >> a;
        for(i=1;i<n;i++)
            tabla[i]=0;
        
        
       
        for(i=1;i<n;i++)
        {
            cin >> b;
            
            res=b-a;
            if(res<0)
                res*=-1;
                
            if(res>=1 && res<n)
            {
                 tabla[res]=1;    
            }    
            a=b;
        }    
        
        es_jolly=1;
        
        
        for(i=1;i<n;i++)
        {
            if(tabla[i]==0)
            {
                es_jolly=0;
                break;
            }    
        }    
        
        if(es_jolly)
            cout << "Jolly" << endl;
        else
            cout << "Not jolly" << endl;
            
    }    
    return 0;
}
