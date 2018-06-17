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
    int i,j,k;
    int tam;
    int matriz[MAX][MAX];
    int filas[MAX];
    int columnas[MAX];
    int fallo_f,fallo_c,n_fallos_f,n_fallos_c;
    
    #ifndef ONLINE_JUDGE
        close (0); 
        open ("541.in", O_RDONLY);
        close (1); 
        open ("541.out", O_WRONLY | O_CREAT, 0600);
    #endif
    while(cin >> tam)
    {
        if(tam==0)
                return 0;
        
        int num_unos=0;
        
        for(i=0;i<tam;i++)
        {
            for(j=0;j<tam;j++)
            {
                cin >> matriz[i][j];
                if(matriz[i][j]==1)
                    num_unos++;        
            }
            if(num_unos%2==0)
                filas[i]=1;
            else
                filas[i]=0;
            
            num_unos=0;
        }   
            
        for(i=0;i<tam;i++)
        {
            for(j=0;j<tam;j++)
            {
                if(matriz[j][i]==1)
                       num_unos++;
            }
            if(num_unos%2==0)
                columnas[i]=1;
            else
                columnas[i]=0;
            
            num_unos=0;    
        }    
        
        n_fallos_f=0;
        n_fallos_c=0;
        for(i=0;i<tam;i++)
        {
            if(filas[i]==0)
            {
                fallo_f=i+1;
                n_fallos_f++;
            }    
            if(columnas[i]==0)
            {
                fallo_c=i+1;
                n_fallos_c++;
            }    
        }  
        
          if(n_fallos_f==0 && n_fallos_c==0)
          {
              cout << "OK" << endl;
          }
          else if(n_fallos_f==1 && n_fallos_c==1)
          {
              cout << "Change bit (" << fallo_f << ',' << fallo_c << ')' << endl;
          }        
          else
          {
              cout << "Corrupt" << endl;
          }    
             
    }    
    
    
    return 0;
}
