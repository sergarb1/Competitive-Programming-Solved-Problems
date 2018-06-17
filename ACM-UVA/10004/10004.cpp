#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_NODOS 200


void colorea(int n,int c);

int coloreable=0;

    int num_nodos,num_aristas;
    int matriz[MAX_NODOS][MAX_NODOS];
    int color[MAX_NODOS];
    
int main()
{
    
    int i,j;
    
    int a,b;
    
    while(scanf("%d",&num_nodos)==1)
    {
        if(num_nodos==0)
        {
            return 0;
        }    
        
        coloreable=0;
        scanf("%d",&num_aristas);
        
        for(i=0;i<num_nodos;i++)
        {
            color[i]=0;
            for(j=0;j<num_nodos;j++)
            {
                matriz[i][j]=0;
            }    
        }    
        
        for(i=0;i<num_aristas;i++)
        {
            scanf("%d",&a);
            scanf("%d",&b);
            matriz[a][b]=1;
            matriz[b][a]=1;
        }  
        colorea(0,1);
        
        if(coloreable==1)
        {
            printf("NOT BICOLORABLE.\n");
        }    
        else
        {
            printf("BICOLORABLE.\n");
        }    
            
          
        
        
    }    
    
    
    
    return 0;
}

void colorea(int n,int c)
{
    int i;
    color[n]=c;
    for(i=0;i<num_nodos;i++)
    {
        if(matriz[n][i]==1)
        {
            if(color[i]==0)
            {
                matriz[n][i]=0;
                matriz[i][n]=0;
                if(c==1)
                {
                    colorea(i,2);
                }
                else
                {
                    colorea(i,1);
                }     
                if(coloreable==1)
                    return;
            }    
            else if(color[i]==color[n])
            {
                coloreable=1;
                return;
            }    
            
        }        
    }    
}    
