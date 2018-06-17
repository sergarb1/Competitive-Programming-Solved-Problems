#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdlib.h> 
#include <iostream>

using namespace std; 

char sopa[100][100];
int m,n;

int npab;

char pal[100];
int xpal,ypal;

void mayusculas(char *c)
{
     int tam=strlen(c);
     
     for(int i=0;i<tam;i++)
     {
             if(c[i]>=97)
                         c[i]-=32;
     }
}

int esta_pal(char *c,int y,int x)
{
    int tampal=strlen(c);
    int res=0;
    int i,j;
    
    if(c[0]!=sopa[y][x])
    {
        return 0;
    }
    
    /** Izquierda **/
    
    if(x-tampal+1>=0 && res==0)
    {
       res=1;
       for(i=x-1;i>=x-tampal+1 && res==1;i--)
       {
           if(pal[x-i]!=sopa[y][i])
               res=0;
       } 
    }
    /** Derecha **/
    
    if(x+tampal-1<n && res==0)
    {
       res=1;
       for(i=x+1;i<x+tampal && res==1;i++)
       {
           if(pal[i-x]!=sopa[y][i])
               res=0;
       } 
    }
    
    
    /** Arriba **/
    
    if(y-tampal+1>=0 && res==0)
    {
       res=1;
       for(i=y-1;i>=y-tampal+1 && res==1;i--)
       {
           if(pal[y-i]!=sopa[i][x])
               res=0;
       } 
    }
    /** Abajo **/
    
    if(y+tampal-1<m && res==0)
    {
       res=1;
       for(i=y+1;i<y+tampal && res==1;i++)
       {
           if(pal[i-y]!=sopa[i][x])
               res=0;
       } 
    }
    
    
    /** Abajo izquierda **/
    
    if(y+tampal-1<m  && x-tampal+1>=0 && res==0)
    {
       res=1;
       for(i=y+1,j=x-1;i<y+tampal && j>=x-tampal+1 && res==1;i++,j--)
       {
           if(pal[i-y]!=sopa[i][j])
               res=0;
       } 
    }
    
    
    /** Abajo derecha **/
    
    if(y+tampal-1<m && x+tampal-1<n  && res==0)
    {
       res=1;
       for(i=y+1,j=x+1;i<y+tampal  && j<x+tampal && res==1;i++,j++)
       {
           if(pal[i-y]!=sopa[i][j])
               res=0;
       } 
    }
    
        
    /** Arriba izquierda **/
    
    if(y-tampal+1>=0 && x-tampal+1>=0  && res==0)
    {
       res=1;
       for(i=y-1,j=x-1;i>=y-tampal+1 && j>=x-tampal+1 && res==1;i--,j--)
       {
           if(pal[y-i]!=sopa[i][j])
               res=0;
       } 
    }
    
    
    /** Arriba derecha **/
    
    if(y-tampal+1>=0 && x+tampal-1<n  && res==0)
    {
       res=1;
       for(i=y-1,j=x+1;i>=y-tampal+1 && j<x+tampal && res==1;i--,j++)
       {
           if(pal[y-i]!=sopa[i][j])
               res=0;
       } 
    }
    return res;
    
}

int main() 
{ 
  int i,j,k,l;

  int ntest;
  
  cin >> ntest;
  
  for(i=0;i<ntest;i++)
  {
          cin >> m >> n;
          char tmp;
          cin.get(tmp);
          for(j=0;j<m;j++)
          {
               cin.getline(sopa[j],70,'\n');
               mayusculas(sopa[j]);
          }
          cin >> npab;
          cin.get(tmp);
          for(j=0;j<npab;j++)
          {
               
               int encontrado=0;
               cin.getline(pal,70,'\n');
               mayusculas(pal);
               for(k=0;k<m && !encontrado;k++)
               {
                    for(l=0;l<n && !encontrado;l++)
                    {
                                if(esta_pal(pal,k,l))
                                {
                                   xpal=l;
                                   ypal=k;
                                   encontrado=1;
                                }
                    }
               }
               cout << ypal+1 << " " << xpal+1 << endl;
          }
          
          if(i<ntest-1)
                       cout << endl;
  }
  
  return 0;
}
