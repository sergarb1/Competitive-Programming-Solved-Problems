#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <iostream>

using namespace std;

#define INFINITO 2147483647

int m,n;
int matriz[10][100],vis[10][100],ant[10][100];
int camino[100],vcamino[100];
int main()
{
	int i,j,k;

	


	while(cin >> m >> n)
	{
		for(i=0;i<m;i++)
		{	
			for(j=0;j<n;j++)
			{
			    if(j<n-1)
    			    vis[i][j]=INFINITO;
			    else
                    vis[i][j]=0;
				cin >> matriz[i][j];
			}
		}
		for(i=n-1;i>0;i--)
		{
			
			if(vis[0][i-1]==INFINITO || vis[0][i-1]>vis[0][i]+matriz[0][i])
			{
				vis[0][i-1]=vis[0][i]+matriz[0][i];
				ant[0][i-1]=0;
			}
			if(vis[1][i-1]==INFINITO || vis[1][i-1]>vis[0][i]+matriz[0][i])
			{
				vis[1][i-1]=vis[0][i]+matriz[0][i];
				ant[1][i-1]=0;
			}
            if(vis[m-1][i-1]==INFINITO || vis[m-1][i-1]>vis[0][i]+matriz[0][i])
			{
				vis[m-1][i-1]=vis[0][i]+matriz[0][i];
				ant[m-1][i-1]=0;
			}				
			for(j=1;j<m-1;j++)
			{
				if(vis[j-1][i-1]==INFINITO || vis[j-1][i-1]>vis[j][i]+matriz[j][i])
				{
                	vis[j-1][i-1]=vis[j][i]+matriz[j][i];
                	ant[j-1][i-1]=j;
                }   	
				if(vis[j][i-1]==INFINITO || vis[j][i-1]>vis[j][i]+matriz[j][i])
				{
                	vis[j][i-1]=vis[j][i]+matriz[j][i];
                   	ant[j][i-1]=j;
                }   	
				if(vis[j+1][i-1]==INFINITO || vis[j+1][i-1]>vis[j][i]+matriz[j][i])
				{
                	vis[j+1][i-1]=vis[j][i]+matriz[j][i];
                	ant[j+1][i-1]=j;
   	            }   	
			}
			
			if(vis[0][i-1]==INFINITO || vis[0][i-1]>vis[m-1][i]+matriz[m-1][i])
			{
             	vis[0][i-1]=vis[m-1][i]+matriz[m-1][i];
             	ant[0][i-1]=m-1;
            }
            if(vis[m-2][i-1]==INFINITO || vis[m-2][i-1]>vis[m-1][i]+matriz[m-1][i])
			{
             	vis[m-2][i-1]=vis[m-1][i]+matriz[m-1][i];
             	ant[m-2][i-1]=m-1;
            }
            if(vis[m-1][i-1]==INFINITO || vis[m-1][i-1]>vis[m-1][i]+matriz[m-1][i])
			{
             	vis[m-1][i-1]=vis[m-1][i]+matriz[m-1][i];
             	ant[m-1][i-1]=m-1;
  	        }   	
			   	
			   	
			
		}

		for(j=0;j<m;j++)
		{
			vis[j][0]+=matriz[j][0];
		}
	/*	for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
				cout << vis[i][j] << " ";
			cout << endl;
		}	
        for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
				cout << ant[i][j] << " ";
			cout << endl;
		}*/
		vcamino[0]=vis[0][0];
		camino[0]=0;
		for(i=1;i<m;i++)
		{
			if(vcamino[0]>vis[i][0])
			{
				vcamino[0]=vis[i][0];
				camino[0]=i;
			}		
		}
		for(i=1;i<n;i++)
		{
		    camino[i]=ant[camino[i-1]][i-1];
		}  
		cout << camino[0]+1;
		for(i=1;i<n;i++)
		{
			cout << " " << camino[i]+1;
		}
		cout << endl << vcamino[0] << endl;
		
		



	}
	return 0;
}
