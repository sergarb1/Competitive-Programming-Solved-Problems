#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdlib.h> 
#include <iostream>

using namespace std; 

#define MAX 8

int matriz[6][6];

int vis[6][6];

int camino[9];

void inicializa_grafo()  
{
    matriz[1][2]=1;
    matriz[1][3]=1;
    matriz[1][5]=1;

    matriz[2][1]=1;
    matriz[2][3]=1;
    matriz[2][5]=1;
    
    matriz[3][1]=1;
    matriz[3][2]=1;
    matriz[3][4]=1;
    matriz[3][5]=1;
    
    matriz[4][3]=1;
    matriz[4][5]=1;
    
    matriz[5][1]=1;
    matriz[5][2]=1;
    matriz[5][3]=1;
    matriz[5][4]=1;
    
    vis[1][2]=0;
    vis[1][3]=0;
    vis[1][5]=0;

    vis[2][1]=0;
    vis[2][3]=0;
    vis[2][5]=0;
    
    vis[3][1]=0;
    vis[3][2]=0;
    vis[3][4]=0;
    vis[3][5]=0;
    
    vis[4][3]=0;
    vis[4][5]=0;
    
    vis[5][1]=0;
    vis[5][2]=0;
    vis[5][3]=0;
    vis[5][4]=0;
    
}    

void pinta(int num,int pos)
{
    int i;
    camino[pos]=num;
    if(pos==MAX)
    {
        for(i=0;i<=MAX;i++)
        {
            cout << camino[i];
        }    
        cout << endl;
        return;
    }    
    for(i=1;i<=5;i++)
    {
        if(matriz[num][i]==1 && vis[num][i]==0)
        {
            vis[num][i]=1;
            vis[i][num]=1;
            pinta(i,pos+1);
            vis[num][i]=0;
            vis[i][num]=0;
        }
    }    
}    
int main() 
{ 
  int i,j,k;

  #ifndef ONLINE_JUDGE 
          //close (0); open (".in", O_RDONLY); 
          close (1); open ("291.out", O_WRONLY | O_CREAT, 0600); 
  #endif 
  
  inicializa_grafo();
  pinta(1,0);
  
  return 0;
}


