#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <iostream>
using namespace std;

    int N,depen,ntar;
    int matriz[101][101];
    int res[101];
    int visitado[100];

void obten_dependencias(int n);

    
int main()
{
    int i,j;
    int r_mayor,r_id;
    
    while(cin >> N)
    {
        if(N==0)
           return 0;
           
        
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                matriz[i][j]=0;
            }    
            res[i]=0;
        }    
        
        
        for(i=0;i<N;i++)
        {
            cin >> ntar;
            for(j=0;j<ntar;j++)
            {
                cin >> depen;
                matriz[i][depen-1]=1;
            }    
        }    
        
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
                    visitado[j]=0;
    
            if(res[i]==0)
            {
                obten_dependencias(i);
            }   
            for(j=0;j<N;j++) 
            {
                if(visitado[j]==1)
                    res[i]++;
            }    
        }    
        
        
        r_mayor=-1;
        r_id=0;
        for(i=0;i<N;i++)
        {
            //cout << "dependencias [" << i+1 << "] " << res[i] << endl;
            if(res[i]>r_mayor)
            {
                r_mayor=res[i];
                r_id=i;
            }    
        }  
        cout << r_id+1 << endl;  
    }    
    
    return 0;
}

void obten_dependencias(int n)
{
    int i=0;
    
    
    
    for(i=0;i<N;i++)
    {
        if(matriz[n][i]==1 && visitado[i]==0)
        {
               visitado[i]=1;  
               obten_dependencias(i);
        }    
    }    
    
}    
