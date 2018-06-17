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

  #ifndef ONLINE_JUDGE 
          close (0); open ("11044.in", O_RDONLY); 
          close (1); open ("11044.out", O_WRONLY | O_CREAT, 0600); 
  #endif 
  int n;
  cin >> n;
  
  for(i=0;i<n;i++)
  {
      int x,y;
      cin >> x;
      cin >> y;
      x=x/3;
      y=y/3;
      cout << x*y << endl;
  }
  
  return 0;
}
