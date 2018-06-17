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
          close (0); open ("10286.in", O_RDONLY); 
          close (1); open ("10286.out", O_WRONLY | O_CREAT, 0600); 
  #endif 
  
  double f;
  
  while(cin >> f)
  {
            double res;
           //double res=sin(108)/sin(63)*f;
            res=1.0673956817111818692592637626711 *f;
            printf("%.10lf\n",res);
  }
  return 0;
}
