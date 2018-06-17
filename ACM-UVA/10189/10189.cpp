#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <iostream>
using namespace std;

#define MAX 100

int main()
{
    int matriz[MAX][MAX];
    int i,j,k;
    int M,N;
    int n_test=1;
    char temp;
    
    #ifndef ONLINE_JUDGE
        close (0); 
        open ("10189.in", O_RDONLY);
        close (1); 
        open ("10189.out", O_WRONLY | O_CREAT, 0600);
    #endif
    while(1)
    {
        cin >> M;
        cin >> N;
        
        if(M==0 && N==0)
                return 0;
        if(n_test>1)
            cout << endl;
                
        for(i=0;i<M;i++)
        {
            for(j=0;j<N;j++)
            {
                cin >> temp;
                if(temp=='*')
                    matriz[i][j]=-1;
                else
                    matriz[i][j]=0;
            }
        }        
        
        for(i=0;i<M;i++)
        {
            for(j=0;j<N;j++)
            {
                if(matriz[i][j]==-1)
                {
                    if(i>0)
                    {
                        if(matriz[i-1][j]!=-1)
                        {
                            matriz[i-1][j]++;
                        }    
                        if(j>0)
                        {
                            if(matriz[i-1][j-1]!=-1)
                            {
                                matriz[i-1][j-1]++;
                            }    
                        }    
                        if(j<N-1)
                        {
                            if(matriz[i-1][j+1]!=-1)
                            {
                                matriz[i-1][j+1]++;
                            }  
                        }    
                    }
                    if(i<M-1)
                    {
                        if(matriz[i+1][j]!=-1)
                        {
                            matriz[i+1][j]++;
                        }    
                        if(j>0)
                        {
                            if(matriz[i+1][j-1]!=-1)
                            {
                                matriz[i+1][j-1]++;
                            }    
                        }    
                        if(j<N-1)
                        {
                            if(matriz[i+1][j+1]!=-1)
                            {
                                matriz[i+1][j+1]++;
                            }  
                        }    
                    }    
                    if(j>0)
                    {
                        if(matriz[i][j-1]!=-1)
                        {
                                matriz[i][j-1]++;
                        }    
                    }    
                    
                    if(j<N-1)
                    {
                        if(matriz[i][j+1]!=-1)
                        {
                                matriz[i][j+1]++;
                        }    
                    }    
                    
                }    
            }
        }        
        
        cout << "Field #" << n_test << ":" << endl;
        n_test++;
            
        for(i=0;i<M;i++)
        {
            for(j=0;j<N;j++)
            {
                if(matriz[i][j]==-1)
                    cout << '*';
                else
                    cout << matriz[i][j];
            }
            cout << endl;    
        }    
    }    
    
    return 0;
}
