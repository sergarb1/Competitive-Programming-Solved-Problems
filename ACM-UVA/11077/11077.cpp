#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdlib.h> 
#include <iostream>

using namespace std; 
 /** 
  1 2 3 4
0 1 1 1 1
1 1 2 0 0
2 0 0 0 0
3 0 0 0 0
**/

int main() 
{ 
  int i,j,k;

  #ifndef ONLINE_JUDGE 
          close (0); open ("D.in", O_RDONLY); 
          close (1); open ("D.out", O_WRONLY | O_CREAT, 0600); 
  #endif 
  int a,b;
  unsigned long long int sol[22][21];
  
   for(i=0;i<=21;i++)
  {
      for(j=0;j<=20;j++)
      {
                        sol[i][j]=0;
      }
  }
  for(i=0;i<=21;i++)
  {
      sol[i][0]=1;
  }
  for(i=1;i<=21;i++)
  {
      for(j=1;j<=i;j++)
      {
                        sol[i][j]=(i-1)*sol[i-1][j-1]+sol[i-1][j];
      }
  }
  
  while(cin >> a >> b)
  {
            if(a==0 && b==0)
            {
                    return 0;
            }
            
            
            cout << sol[a][b] << endl;
            
  }
  return 0;
}
