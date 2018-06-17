#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <iostream>
using namespace std;

    int m,n;
    int ndep;
    char matriz[100][100],tmp;
    char cogido[100][100];
    
    void coger(int x,int y)
    {
        cogido[x][y]=1;
        if(x>0 && matriz[x-1][y]=='@'&& cogido[x-1][y]==0)
        {
            coger(x-1,y);
        }    
        if(x>0  && y>0 && matriz[x-1][y-1]=='@' && cogido[x-1][y-1]==0)
        {
            coger(x-1,y-1);
        }    
        if(x>0 && y<n-1 && matriz[x-1][y+1]=='@'&& cogido[x-1][y+1]==0)
        {
            coger(x-1,y+1);
        }    
        if(y>0 && matriz[x][y-1]=='@'&& cogido[x][y-1]==0)
        {
            coger(x,y-1);
        }    
        if(y<n-1  && matriz[x][y+1]=='@'&& cogido[x][y+1]==0)
        {
            coger(x,y+1);
        }    
        
        if(x<m-1 && matriz[x+1][y]=='@'&& cogido[x+1][y]==0)
        {
            coger(x+1,y);
        }    
        if(x<m-1  && y>0 && matriz[x+1][y-1]=='@'&& cogido[x+1][y-1]==0)
        {
            coger(x+1,y-1);
        }    
        if(x<m-1 && y<n-1 && matriz[x+1][y+1]=='@'&& cogido[x+1][y+1]==0)
        {
            coger(x+1,y+1);
        }    
    }    


int main()
{
    int i,j;
    #ifndef ONLINE_JUDGE
        close (0); 
        open ("572.in", O_RDONLY);
        close (1); 
        open ("572.out", O_WRONLY | O_CREAT, 0600);
    #endif
    
    while(cin >> m >> n)
    {
        ndep=0;
        cin.get(tmp);
        if(m==0)
                return 0;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                cogido[i][j]=0;
                cin.get(matriz[i][j]);
            }    
            cin.get(tmp);
        }    
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(matriz[i][j]=='@' && cogido[i][j]==0)
                {
                    ndep++;
                    coger(i,j);
                }    
            }
        }        
        cout << ndep << endl;
        
    }    
    
    
    return 0;
}
