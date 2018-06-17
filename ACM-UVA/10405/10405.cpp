#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdlib.h> 
#include <iostream>



/*

Traza de ejemplo

abcf
ncab


abcf
21100n
21100c
20000a
11000b
00000
*/

using namespace std; 

  char s1[1001];
  char s2[1001];
  
int maximo(int a,int b)
{
    if(a>b)
           return a;
    return b;
}

int maxcomsub()
{
    int tam1,tam2;
    short int vt[1001][1001];
    tam1=strlen(s1);
    tam2=strlen(s2);
    for(int i=0;i<tam1;i++)
    {
       for(int j=0;j<tam2;j++)
       {
           vt[i][j]=0;
       }
    }
    
    for(int i=tam1;i>=0;i--)
    {
        for(int j=tam2;j>=0;j--)
        {
             if(s1[i]==0 || s2[j]==0)
             {
                         vt[i][j]=0;
             }
             else if(s1[i]==s2[j])
             {
                  vt[i][j]=1+vt[i+1][j+1];
             }
             else
             {
                  vt[i][j]=maximo(vt[i+1][j],vt[i][j+1]);
             }
        }
    }
    
    return vt[0][0];
    
}

int main() 
{ 
  int i,j,k;

  #ifndef ONLINE_JUDGE 
          close (0); open ("10405.in", O_RDONLY); 
          close (1); open ("10405.out", O_WRONLY | O_CREAT, 0600); 
  #endif 
  
  
  while(cin.getline(s1,1000))
  {
      cin.getline(s2,1000);
      int res;
      res=maxcomsub();
      cout << res << endl;
  }
  return 0;
}
