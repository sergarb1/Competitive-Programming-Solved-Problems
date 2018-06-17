#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <iostream>
using namespace std;

#define MAXN 25

void apilar(int pila,int valor);
int desapilar(int pila);
  int N;
    int temp;
    int pila[MAXN][MAXN];
    int pila_temp[MAXN];
    int tam_temp;
    
    int pos[MAXN],tam[MAXN];
    
int main()
{
    
  
    int i,j,k;
    
    char orden[100];
    char prep[100];
    
    int a,b;
    char ordenes[3][100]={"move","pile","quit"};
    char prepos[2][100]={"onto","over"};
    
    #ifndef ONLINE_JUDGE
        close (0); 
        open ("101.in", O_RDONLY);
        close (1); 
        open ("101.out", O_WRONLY | O_CREAT, 0600);
    #endif
    
    scanf("%d",&N);
    
    for(i=0;i<N;i++)
    {
        pila[i][0]=i;
        pos[i]=i;
        tam[i]=1;
    }    
    
    while(1)
    {
        scanf("%s",orden);
        if(strcmp(orden,ordenes[2])==0)
        {
            break;
        }    
        scanf("%d",&a);
        scanf("%s",prep);
        scanf("%d",&b);
        
        if(a==b || pos[a]==pos[b]) // Movimientos ilegales no tenidos en cuenta
                continue;
        // Falta entederlo pa hacerlo xD
        
        if(strcmp(orden,ordenes[0])==0)
        {
            if(strcmp(prep,prepos[0])==0)
            {
               for(i=tam[pos[b]]-1;pila[pos[b]][i]!=b;i--)
               {
                   temp=desapilar(pos[b]);
                   apilar(temp,temp);
               } 
               for(i=tam[pos[a]]-1;pila[pos[a]][i]!=a;i--)
               {
                   temp=desapilar(pos[a]);
                   apilar(temp,temp);
               } 
               temp=desapilar(pos[a]);
               apilar(pos[b],temp);   
                
            }   
            else if( strcmp(prep,prepos[1])==0)
            {
               for(i=tam[pos[a]]-1;pila[pos[a]][i]!=a;i--)
               {
                   temp=desapilar(pos[a]);
                   apilar(temp,temp);
               } 
               
               temp=desapilar(pos[a]);
               apilar(pos[b],temp);
                
            }     
        }   
        else if(strcmp(orden,ordenes[1])==0)
        {
            if(strcmp(prep,prepos[0])==0)
            {
               tam_temp=0;
               for(i=tam[pos[b]]-1;pila[pos[b]][i]!=b;i--)
               {
                   temp=desapilar(pos[b]);
                   apilar(temp,temp);
               }
               for(i=tam[pos[a]]-1;pila[pos[a]][i]!=a;i--)
               {
                   pila_temp[tam_temp]=desapilar(pos[a]);
                   tam_temp++;
               }
               
               pila_temp[tam_temp]=desapilar(pos[a]);
               tam_temp++;
                
               for(i=tam_temp-1;i>=0;i--)
               {
                   apilar(pos[b],pila_temp[i]);
               }    
                
                
            }   
            else if( strcmp(prep,prepos[1])==0)
            {
               tam_temp=0;
               
               for(i=tam[pos[a]]-1;pila[pos[a]][i]!=a;i--)
               {
                   pila_temp[tam_temp]=desapilar(pos[a]);
                   tam_temp++;
               } 
               pila_temp[tam_temp]=desapilar(pos[a]);
               tam_temp++;
               
               for(i=tam_temp-1;i>=0;i--)
               {
                   apilar(pos[b],pila_temp[i]);
               } 
            }   
        }
          
        
    }    
    
    for(i=0;i<N;i++)
    {
        printf("%d:",i);
        for(j=0;j<tam[i];j++)
        {
            printf(" %d",pila[i][j]);
        }    
        printf("\n");
    }    
    
    return 0;
}

void apilar(int pil,int valor)
{
    pos[valor]=pil;
    pila[pil][tam[pil]]=valor;
    tam[pil]++;
}    


int desapilar(int pil)
{
    int res=pila[pil][tam[pil]-1];
    tam[pil]--;
    return res;
}    
