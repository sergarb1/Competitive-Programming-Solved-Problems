#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdlib.h> 
#include <iostream>
#include <stack>

using namespace std; 

#define MAXV 40
#define MAXGRADO 40
typedef struct{
        int arcos[MAXV+1][MAXGRADO+1];
        int grado[MAXV+1];
        int nvertices;
        int narcos;
}grafo;


  struct c
  {
         int com[12];
         int posorg;
  } cajas[32];

int maxv=0,maxp=0;
int res[MAXV+1];
int vis[MAXV+1];
int gru[MAXV+1];
int pad[MAXV+1];

  grafo gra;
int dim;

void dfs()
{
     int i,j;
     int start;
     stack<int> q;
     for(i=0;i<gra.nvertices;i++)
     {
         pad[i]=-1;
         vis[i]=0;
         gru[i]=-1;
     }     
     for(start=0;start<gra.nvertices;start++)
     {
         if(vis[start]!=0)
              continue;
         pad[start]=-1;
         q.push(start);
         vis[start]=1;
         while(!q.empty())
         {
              int v=q.top();
              q.pop();
              for(i=0;i<gra.grado[v];i++)
              {
                  if(vis[v]+1>vis[gra.arcos[v][i]] && gra.arcos[v][i]>v)
                  {
                      vis[gra.arcos[v][i]]=vis[v]+1;
                      pad[gra.arcos[v][i]]=v;
                      q.push(gra.arcos[v][i]);
                  }
              }
         }
     }
     
}


int compara(const void *a,const void *b)
{
    int x=*((int *)a);
    int y=*((int *)b);
    return x-y;
}

int compara_cajas(const void *a,const void *b)
{
    struct c* x=(struct c *)a;
    struct c* y=(struct c *)b;
    for(int i=0;i<dim;i++)
    {
            if(x->com[i]!=y->com[i])
                          return x->com[i]-y->com[i];
    }
    return 0;
}
/**
v1 cabe dentro de v2
**/
int cabe(struct c v1,struct c v2,int dim)
{
    for(int i=0;i<dim;i++)
    {
          if(v2.com[i]<=v1.com[i])
          {
               return 0;
          }
    }
    return 1;
} 

int main() 
{ 
  int i,j;
  
  #ifndef ONLINE_JUDGE 
          close (0); open ("103.in", O_RDONLY); 
          close (1); open ("103.out", O_WRONLY | O_CREAT, 0600); 
  #endif 
  int n,k;
  while(cin >> n >> k)
  {
            gra.nvertices=0;
            
            dim=k;
            for(i=0;i<n;i++)
            {
                for(j=0;j<k;j++)
                {
                    cin >> cajas[i].com[j];
                }
                qsort(cajas[i].com,k,sizeof(cajas[0].com[0]),compara);
                cajas[i].posorg=i;
                gra.grado[i]=0;
                gra.nvertices++;
                
                
            }
            qsort(cajas,n,sizeof(cajas[0]),compara_cajas);
            
            
            for(i=0;i<n;i++)
            {
                for(j=0;j<i;j++)
                {
                   if(cabe(cajas[j],cajas[i],k))
                   {
                       gra.arcos[j][gra.grado[j]]=i;
                       gra.grado[j]++;
                       gra.narcos++;
                       
                   }
                   if(cabe(cajas[i],cajas[j],k))
                   {
                       gra.arcos[i][gra.grado[i]]=j;
                       gra.grado[i]++;
                       gra.narcos++;
                   }
                }
            }
            /**
            for(i=0;i<n;i++)
            {
                for(j=0;j<k;j++)
                {
                                cout << cajas[i][j] << " " ;
                }
                cout << endl;
            }  
            **/
            
            dfs();
            
            //while(1);
            int maxv=0;
            int maxp=0;
            for(i=0 ;i<gra.nvertices;i++)
            {
                 if(vis[i]>maxv)
                 {
                      maxv=vis[i];
                      maxp=i;
                 }
            }
            int recorrido=maxv-1;
            res[recorrido--]=maxp;
            int ini=pad[maxp];
            while(ini>=0)
            {
               res[recorrido--]=ini;
               ini=pad[ini];
            }
            
            cout << maxv << endl;
            
            for(int i=0;i<maxv-1;i++)
            {
                    cout << cajas[res[i]].posorg+1 << " ";
            }
            
            cout << cajas[res[maxv-1]].posorg+1  <<endl;
  }
  
  
  
  
  return 0;
}
