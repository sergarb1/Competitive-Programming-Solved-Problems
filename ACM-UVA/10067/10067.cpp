#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <iostream>

using namespace std;

#define INFINITO (10*10*10*10)+1

int npro;
struct con
{
	int a;
	int b;
	int c;
	int d;
}ini,fin;

int grafo[10][10][10][10];
int vis[10][10][10][10];
int pa[2],pb[2],pc[2],pd[2];



void resuelve(int a,int b,int c,int d,int pas)
{
	vis[a][b][c][d]=pas;


	if(a==9)
	{
		if(pa[0]<6 && pas+1<vis[fin.a][fin.b][fin.c][fin.d] && grafo[0][b][c][d]!=-1 && vis[0][b][c][d]>pas+1)
		{
			pa[0]++;
			resuelve(0,b,c,d,pas+1);
			
			pa[0]--;
		}			
	}
	else
	{

		if(pa[0]<6 && pas+1<vis[fin.a][fin.b][fin.c][fin.d] && grafo[a+1][b][c][d]!=-1 && vis[a+1][b][c][d]>pas+1)
		{
			pa[0]++;
			resuelve(a+1,b,c,d,pas+1);
			
			pa[0]--;
		}			
	}

	if(a==0)
	{
		if(pa[1]<6 && pas+1<vis[fin.a][fin.b][fin.c][fin.d] && grafo[9][b][c][d]!=-1 && vis[9][b][c][d]>pas+1)
		{
			pa[1]++;
			resuelve(9,b,c,d,pas+1);

			pa[1]--;
		}			
	}
	else
	{

		if(pa[1]<6 && pas+1<vis[fin.a][fin.b][fin.c][fin.d] && grafo[a-1][b][c][d]!=-1 && vis[a-1][b][c][d]>pas+1)
		{

			pa[1]++;
			resuelve(a-1,b,c,d,pas+1);
			pa[1]--;
		}			
	}


	if(b==9)
	{
		if(pb[0]<6 && pas+1<vis[fin.a][fin.b][fin.c][fin.d] && grafo[a][0][c][d]!=-1 && vis[a][0][c][d]>pas+1)
		{
			
			pb[0]++;
			resuelve(a,0,c,d,pas+1);
			pb[0]--;
		}			
	}
	else
	{
		
		if(pb[0]<6 && pas+1<vis[fin.a][fin.b][fin.c][fin.d] && grafo[a][b+1][c][d]!=-1 && vis[a][b+1][c][d]>pas+1)
		{
			pb[0]++;
			resuelve(a,b+1,c,d,pas+1);
			pb[0]--;
		}			
	}
	

	if(b==0)
	{
		if(pb[1]<6 && pas+1<vis[fin.a][fin.b][fin.c][fin.d] && grafo[a][9][c][d]!=-1 && vis[a][9][c][d]>pas+1)
		{
			pb[1]++;
			resuelve(a,9,c,d,pas+1);
			pb[1]--;
		}			
	}
	else
	{

		if(pb[1]<6 && pas+1<vis[fin.a][fin.b][fin.c][fin.d] && grafo[a][b-1][c][d]!=-1 && vis[a][b-1][c][d]>pas+1)
		{
			pb[1]++;
			resuelve(a,b-1,c,d,pas+1);
			pb[1]--;
		}			
	}

	
	if(c==9)
	{
		if(pc[0]<6 && pas+1<vis[fin.a][fin.b][fin.c][fin.d] && grafo[a][b][0][d]!=-1 && vis[a][b][0][d]>pas+1)
		{
			pc[0]++;
			resuelve(a,b,0,d,pas+1);
			pc[0]--;
		}			
	}
	else
	{

		if(pc[0]<6 && pas+1<vis[fin.a][fin.b][fin.c][fin.d] && grafo[a][b][c+1][d]!=-1 && vis[a][b][c+1][d]>pas+1)
		{
			pc[0]++;
			resuelve(a,b,c+1,d,pas+1);
			pc[0]--;
		}			
	}

	if(c==0)
	{
		if(pc[1]<6 &&  pas+1<vis[fin.a][fin.b][fin.c][fin.d] && grafo[a][b][9][d]!=-1 && vis[a][b][9][d]>pas+1)
		{
			pc[1]++;
			resuelve(a,b,9,d,pas+1);
			pc[1]--;
		}			
	}
	else
	{

		if(pc[1]<6 && pas+1<vis[fin.a][fin.b][fin.c][fin.d] && grafo[a][b][c-1][d]!=-1 && vis[a][b][c-1][d]>pas+1)
		{
			pc[1]++;
			resuelve(a,b,c-1,d,pas+1);
			pc[1]--;
		}			
	}

	if(d==9)
	{
		if(pd[0]<6 &&  pas+1<vis[fin.a][fin.b][fin.c][fin.d] && grafo[a][b][c][0]!=-1 && vis[a][b][c][0]>pas+1)
		{
			pd[0]++;
			resuelve(a,b,c,0,pas+1);
			pd[0]--;
		}			
	}
	else
	{

		if(pd[0]<6 && pas+1<vis[fin.a][fin.b][fin.c][fin.d] && grafo[a][b][c][d+1]!=-1 && vis[a][b][c][d+1]>pas+1)
		{
			pd[0]++;
			resuelve(a,b,c,d+1,pas+1);
			pd[0]--;
		}			
	}

	if(d==0)
	{
		if(pd[1]<6 && pas+1<vis[fin.a][fin.b][fin.c][fin.d] && grafo[a][b][c][9]!=-1 && vis[a][b][c][9]>pas+1)
		{
			pd[1]++;
			resuelve(a,b,c,9,pas+1);
			pd[1]--;
		}			
	}
	else
	{

		if(pd[1]<6 && pas+1<vis[fin.a][fin.b][fin.c][fin.d] && grafo[a][b][c][d-1]!=-1 && vis[a][b][c][d-1]>pas+1)
		{
			pd[1]++;
			resuelve(a,b,c,d-1,pas+1);
			pd[1]--;
		}			
	}

}


int main()
{
	int i,j,k,l;



	int ntest;

	cin >> ntest;

	while(ntest--)
	{
		struct con temp;

		cin >> ini.a>> ini.b>> ini.c>> ini.d;
		cin >> fin.a>> fin.b>> fin.c>> fin.d;
		cin >> npro;
		for(i=0;i<=9;i++)
			for(j=0;j<=9;j++)
				for(k=0;k<=9;k++)
					for(l=0;l<=9;l++)
					{
						grafo[i][j][k][l]=0;
						vis[i][j][k][l]=INFINITO;
					}

		pa[0]=0;
		pa[1]=0;
		pb[0]=0;
		pb[1]=0;
		pc[0]=0;
		pc[1]=0;
		pd[0]=0;
		pd[1]=0;
		for(i=0;i<npro;i++)
		{
			cin >> temp.a>> temp.b>> temp.c>> temp.d;
			grafo[temp.a][temp.b][temp.c][temp.d]=-1;
		}
		
		if(ini.a==fin.a && ini.b==fin.b && ini.c==fin.c && ini.d==fin.d)
		{
			cout << "0" << endl;
			continue;
		}
		if(grafo[ini.a][ini.b][ini.c][ini.d]==-1 || grafo[fin.a][fin.b][fin.c][fin.d]==-1) 
		{
			cout << "-1" << endl;
			continue;
		}
		resuelve(ini.a,ini.b,ini.c,ini.d,0);
		if(vis[fin.a][fin.b][fin.c][fin.d]==INFINITO)
		{
			cout << "-1" << endl;
		}
		else
		{
			cout << vis[fin.a][fin.b][fin.c][fin.d]<< endl;
		}
	}

	return 0;
}
