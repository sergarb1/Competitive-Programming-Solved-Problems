#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdlib.h> 
#include <iostream>

using namespace std; 



#define MAXN 8
int dizq[(MAXN*2)+1];
int dder[(MAXN*2)+1];


int tab,nalf;
long long int npos=0;

void pon(int r,int c,int nalfil)
{
    int i,j;
    if(nalfil==nalf)
    {
        npos++;
        return;
    }    
    
    for(i=r;i<=tab;i++)
    {
        if(i==r)
                j=c+1;
        else
                j=1;
        for(;j<=tab;j++)
        {
            if(dizq[i-j+MAXN]==0  && dder[i+j]==0)
            {
                
                dizq[i-j+MAXN]=1;
                dder[i+j]=1;
                pon(i,j,nalfil+1);
                dizq[i-j+MAXN]=0;
                dder[i+j]=0;
            }    
        }    
    }    
}    

int main() 
{ 
  int i,j,k;

  #ifndef ONLINE_JUDGE 
          //close (0); open ("861.in", O_RDONLY); 
          //close (1); open ("861.out", O_WRONLY | O_CREAT, 0600); 
  #endif 
  
  while(cin >> tab >> nalf)
  {
      npos=0;
      if(tab==0 && nalf==0)
            return 0;
            
      for(i=0;i<(MAXN*2)+1;i++)
      {
          dizq[i]=0;
          dder[i]=0;
          
      }    
      for(i=1;i<=tab;i++)
      {
          for(j=1;j<=tab;j++)
          {
                    dizq[i-j+MAXN]=1;
                    dder[i+j]=1;
                    pon(i,j,1);
                    dizq[i-j+MAXN]=0;
                    dder[i+j]=0;
                    
          }    
      }    
      cout << npos << endl;
  }    
  
  return 0;
}
