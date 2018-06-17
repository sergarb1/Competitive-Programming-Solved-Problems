#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <iostream>

using namespace std;
	int f1,f2,c1,c2;
	int tablero[8][8];
		
	char columna1,columna2,fila1,fila2,tmp;

void imp_tab()
{
    int i,j;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
                cout << tablero[i][j] << " ";
        cout << endl;
    }
}    

void salta(int x,int y,int nmov)
{
	tablero[x][y]=nmov;
	if(x>0 && y>1 && tablero[x-1][y-2]>nmov+1)
	{
		salta(x-1,y-2,nmov+1);
		
	}
	if(x<7 && y>1 && tablero[x+1][y-2]>nmov+1)
	{
		salta(x+1,y-2,nmov+1);
		
	}
	if(x>0 && y<6 && tablero[x-1][y+2]>nmov+1)
	{
		salta(x-1,y+2,nmov+1);
		
	}
	if(x<7 && y<6 && tablero[x+1][y+2]>nmov+1)
	{
		salta(x+1,y+2,nmov+1);
		
	}

	if(x>0 && y>1 && tablero[x-1][y-2]>nmov+1)
	{
		salta(x-1,y-2,nmov+1);
		
	}
	if(x>1 && y>0 && tablero[x-2][y-1]>nmov+1)
	{
		salta(x-2,y-1,nmov+1);
		
	}
	if(x>1 && y<7 && tablero[x-2][y+1]>nmov+1)
	{
		salta(x-2,y+1,nmov+1);
		
	}
	if(x<6 && y>0 && tablero[x+2][y-1]>nmov+1)
	{
		salta(x+2,y-1,nmov+1);
		
	}
	if(x<6 && y<7 && tablero[x+2][y+1]>nmov+1)
	{
		salta(x+2,y+1,nmov+1);
		
	}
}

int main()
{
	int i,j,k;
	#ifndef ONLINE_JUDGE
  		//close (0); open ("439.in", O_RDONLY);
  		//close (1); open ("439.out", O_WRONLY | O_CREAT, 0600);
	#endif 
	while(cin.get(columna1))
	{
		cin.get(fila1);
		cin.get(tmp);
		c1=columna1-'a';
		f1=fila1-'1';	
		cin.get(columna2);
		cin.get(fila2);
		cin.get(tmp);
		c2=columna2-'a';
		f2=fila2-'1';
		for(i=0;i<8;i++)
		{
			for(j=0;j<8;j++)
			{
				tablero[i][j]=300000;
			}
		}	
		//cout << c1<<f1 << " " <<c2 <<f2<<endl;
		salta(f1,c1,0);
		//cout << f2 << " " << c2 << endl;
		//imp_tab();
        cout << "To get from "<<columna1 <<fila1<< " to "<<columna2 << fila2 <<" takes "<< tablero[f2][c2] <<" knight moves." << endl;
		
	}

	return 0;
}

