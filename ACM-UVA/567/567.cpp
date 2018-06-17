#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdlib.h> 
#include <iostream>
#include <queue>

using namespace std; 
#define MAXV 20
#define MAXDEGREE 20


typedef struct
{
	int edges[MAXV+1][MAXDEGREE];
	int degree[MAXV+1];
	int nvertices;
	int nedges;
}graph;



int main() 
{ 
  int i,j,k;

  #ifndef ONLINE_JUDGE 
          close (0); open ("567.in", O_RDONLY); 
          close (1); open ("567.out", O_WRONLY | O_CREAT, 0600); 
  #endif 

	int m;
	int ncasos=1;
	int ntest;
	while(cin >> m)
	{
		
		graph g;
		g.nvertices=19;
		for(j=0;j<=MAXV;j++)
		{
			g.degree[j]=0;
		}

		for(j=0;j<m;j++)
		{
			int tmp;
			cin >> tmp;
			g.edges[0][g.degree[0]]=tmp-1;
			g.degree[0]++;
			g.edges[tmp-1][g.degree[tmp-1]]=0;
			g.degree[tmp-1]++;
		}		
		for(i=1;i<19;i++)
		{
			cin >> m;
			for(j=0;j<m;j++)
			{
				int tmp;
				cin >> tmp;
				g.edges[i][g.degree[i]]=tmp-1;
				g.degree[i]++;
				g.edges[tmp-1][g.degree[tmp-1]]=i;
				g.degree[tmp-1]++;
			}	
		}

		cin >> ntest;
		if(ncasos>1)
			cout << endl;
		cout << "Test Set #"<<ncasos++<<endl;
		for(k=0;k<ntest;k++)
		{

			int t1,t2;
			cin >> t1 >> t2;
	
			
			int vis[MAXV+1];
			int par[MAXV+1];
			queue<int> q;
			int encontrado=0;
			q.push(t1-1);
			for(m=0;m<=MAXV;m++)
				vis[m]=0;
			par[t1-1]=-1;
			vis[t1-1]=1;
			while(!q.empty() && !encontrado)
			{
				int tmp=q.front();

				//cout << "saco "<<tmp << endl;
				q.pop();
				for(i=0;i<g.degree[tmp] && !encontrado;i++)
				{
					if(vis[g.edges[tmp][i]]==0)
					{
						
						//cout << "voy de "<<tmp<< " a "<<g.edges[tmp][i]<< endl;
						q.push(g.edges[tmp][i]);
						vis[g.edges[tmp][i]]=vis[tmp]+1;
						par[g.edges[tmp][i]]=tmp;
						if(g.edges[tmp][i]==t2-1)
							encontrado=vis[g.edges[tmp][i]];
					}
				}
				
			}
			cout << t1 << " to "<<t2<<": "<<encontrado-1<< endl;
			
		}
	}


  return 0;
}
