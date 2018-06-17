#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>

using namespace std;

#define MAX_N 101

long long int sumar_rect(int x,int y,int fil);

long long int fil[MAX_N][MAX_N][MAX_N];
long long int N;
long long int matriz[MAX_N][MAX_N];

int main()
{
    long long int i ,j,k,l;
    long long int suma_temp;
    long long int max_suma=-127;
    #ifndef ONLINE_JUDGE
        close (0); 
        open ("108.in", O_RDONLY);
        close (1); 
        open ("108.out", O_WRONLY | O_CREAT, 0600);
    #endif
    
    cin >> N;
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                cin >> matriz[i][j];
                //cout << matriz[i][j]<< endl;
            }    
        }    
        
        for(k=0;k<N;k++)
        {    
            for(i=0;i<N;i++)
            {
                  for(j=i;j<N;j++)
                  {
                     fil[k][i][j]=sumar_rect(i,j,k);
                     if(fil[k][i][j]>max_suma)
                     {
                         max_suma=fil[k][i][j];
                     }    
                  }    
             }
        }
        
        for(i=0;i<N;i++)
        {
            for(j=i;j<N;j++)
            {
                for(k=0;k<N;k++)
                {
                    suma_temp=0;
                    for(l=k;l<N;l++)
                    {
                        suma_temp+=fil[l][i][j];
                        if(suma_temp>max_suma)
                        {
                                  max_suma=suma_temp;
                        }   
                    }  
                    
                }
                  
            }    
        }    
                           
        cout << max_suma << endl;
    
    
    
    return 0;
    
    
}

long long int sumar_rect(int x,int y,int fil)
{
    int i,j;
    int res=0;
    
    for(i=x;i<=y;i++)
    {
            res+=matriz[fil][i];
            
    }    
    return res;
    
}
