#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include <iostream>
using namespace std;


#define INFINITO  1.0/0.0

#define MAXV 101
#define MAXDEGREE 100

typedef struct{
    int vertice;
    double weight;
}edge;
    
typedef struct {
    edge edges[MAXV+1][MAXDEGREE];
    int degree[MAXV+1];
    int nvertices;
    int nedges;
} graph;

void initialize_graph(graph *g)
{
    int i;
    g->nvertices=0;
    g->nedges=0;
    for(i=0;i<=MAXV;i++)
    {
        g->degree[i]=0;
    }    
}        

void insert_edge(graph *g,int a,int b,double peso, int directed)
{
    g->edges[a][g->degree[a]].vertice=b;
    g->edges[a][g->degree[a]].weight=peso;
    g->degree[a]++;
    if(directed==0)
    {
        insert_edge(g,b,a,peso,1);
    }
    else
    {
        g->nedges++;
    }        
}    

int main()
{
    int i,j,k;
    int ntest;
    struct v
    {
        double x;
        double y;
    }vertices[100];    
    
    cin >> ntest;
    graph g;
    int parent[100];
    double peso[100],pes;
    int padre=0,actual,proximo;
    double menor,mayor;
    
    
    while(ntest--)
    {
        initialize_graph(&g);
        cin >> g.nvertices;
        padre=0;
        for(i=0;i<g.nvertices;i++)
        {
            cin >> vertices[i].x >> vertices[i].y;
            for(j=i-1;j>=0;j--)
            {
                pes=sqrt(pow(vertices[i].x-vertices[j].x,2.0)+pow(vertices[i].y-vertices[j].y,2.0));
                insert_edge(&g,i,j,pes,0);
            } 
            parent[i]=-2;
            peso[i]=0;   
        }
        
        parent[0]=-1;
        for(j=0;j<g.nvertices-1;j++)
        {   
            menor=INFINITO;
             
            for(k=0;k<g.nvertices;k++)
            {
                padre=k;
                if(parent[padre]==-2)
                        continue;
                for(i=0;i<g.degree[padre];i++)
                {
                    if(parent[g.edges[padre][i].vertice]==-2 && g.edges[padre][i].weight<menor)
                    {
                            actual=padre;
                            proximo=i;
                            menor= g.edges[padre][i].weight;
                    }    
                }
            }              
            padre=actual;
            parent[g.edges[padre][proximo].vertice]=padre;
            peso[g.edges[padre][proximo].vertice]= g.edges[padre][proximo].weight;
        }
        mayor=0.0;
        for(i=0;i<g.nvertices;i++)
        { 
           mayor+=peso[i];  
        }
            
        printf("%.2lf\n",mayor);   
        if(ntest>0)
                printf("\n");
    }    
    return 0;
}
