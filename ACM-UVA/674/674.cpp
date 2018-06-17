#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdlib.h> 
#include <iostream>

using namespace std; 

  unsigned long long int nway[100000];
int main() 
{ 
  int i,j,k;
  int n,v,c;
  int coin[5] = { 1,5,10,25,50 };
  
  #ifndef ONLINE_JUDGE 
          close (0); open ("674.in", O_RDONLY); 
          close (1); open ("674.out", O_WRONLY | O_CREAT, 0600); 
  #endif 
       n=7489; 
       v = 5;
       nway[0] = 1;
       for (i=0; i<v; i++) {
            c = coin[i];
            for (j=c; j<=n; j++)
                nway[j] += nway[j-c];
       }
       
  while(cin>>n)
  {
       cout << nway[n]<< endl;
  }
  return 0;
}
