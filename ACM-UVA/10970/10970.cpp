#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdlib.h> 
#include <iostream>

using namespace std; 

int main() 
{ 
  int i,j,k;
  int N,M;
  #ifndef ONLINE_JUDGE 
          //close (0); open ("10970.in", O_RDONLY); 
          //close (1); open ("10970.out", O_WRONLY | O_CREAT, 0600); 
  #endif 
  long long int res;
  while(cin >> N >> M)
  {
      res=0;
      res+=N-1;
      res+=N*(M-1);
      cout << res << endl;
  }    
  return 0;
}
