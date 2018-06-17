#include <iostream>
#include <stdio.h>

using namespace std;

#define INFINITO -1

int mini(int a,int b)
{
    if(a<b)
           return a;
    return b;
}
int maxi(int a,int b)
{
    if(a>b)
           return a;
    return b;
}

int N,R;



int grafo[121][121];

void inicializar_grafo()
{
     int i,j;
     for(i=0;i<=N;i++)
        for(j=0;j<=N;j++)
            grafo[i][j]=INFINITO;
 }
 
 int obtenermaxmin(int x,int y)
 {
     int i,j,k;
     for(k=1;k<=N;k++)
     {
       for(i=1;i<=N;i++)
       {
          for(j=1;j<=N;j++)
          {
                 grafo[i][j]=maxi(mini(grafo[i][k],grafo[k][j]),grafo[i][j]) ;
               
          } 
       }
     }
     return grafo[x][y];
 }

int main()
{   
    int i,j,k;  
    int x,y,z; 
    int ntest=0; 
    while(1)
    {
       ntest++;
       cin >> N;
       cin >> R;
       inicializar_grafo();
       if(N==0 && R==0)
       {
            return 0;
       }
       for(i=0;i<R;i++)
       {
           cin >> x;
           cin >> y;
           cin >> z;
           grafo[x][y]=z-1;
           grafo[y][x]=z-1;
       }
       cin >> x;
       cin >> y;
       cin >> z;
       z;
       int nviajes=0;
       int pasmax=obtenermaxmin(x,y);
       //printf("PAs max %d %d\n",pasmax,z);
       if(z>pasmax)
       {
                   nviajes=z/pasmax;
                   if(z%pasmax>0)
                       nviajes++;
       }
       else
       {
           nviajes=1;
       }
       printf("Scenario #%d\n",ntest);
       printf("Minimum Number of Trips = %d\n\n",nviajes);
       
    }           
    return 0;
}
