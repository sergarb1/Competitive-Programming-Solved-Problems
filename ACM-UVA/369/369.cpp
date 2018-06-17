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
    int N,M;
    unsigned long long int resultado,divisor[100];
    int intervalo1i;
    int intervalo1f;
    int intervalo2i;
    int intervalo2f;
    int ndiv;
    #ifndef ONLINE_JUDGE
        close (0); 
        open ("369.in", O_RDONLY);
        close (1); 
        open ("369.out", O_WRONLY | O_CREAT, 0600);
    #endif
    
    while(cin >> N)
    {
        
        cin >> M;
        if(N==0 && M==0)
                return 0;   
        
        intervalo1i=1;
        if(M>N-M)
        {
            intervalo1f=N-M;
            intervalo2i=M+1;
        }
        else
        {    
            intervalo1f=M;
            intervalo2i=N-M+1;
        }    
        intervalo2f=N;        
        
        for(i=intervalo1i;i<=intervalo1f;i++)
        {
            divisor[i]=1;
        }    
        
        resultado=1;
        
        ndiv=intervalo1f;
         
        for(i=intervalo2i;i<=intervalo2f;i++)
        {
            resultado*=i;
            if(ndiv>0)
            {
                for(j=intervalo1i;j<=intervalo1f && j<=resultado;j++)
                {
                    if(divisor[j]==1 && resultado%j==0)
                    {
                        divisor[j]=0;
                        resultado/=j;
                        ndiv--;
                    }    
                }    
            }    
        }    
        
        if(ndiv>0)
        {
                for(j=intervalo1i;j<=intervalo1f;j++)
                {
                    if(divisor[j]==1 )
                    {
                        divisor[j]=0;
                        resultado/=j;
                        ndiv--;
                    }    
                }    
            }  
                
        
        cout << N << " things taken " << M << " at a time is " << resultado << " exactly." << endl;
        
          
    }
    
    return 0;
}
