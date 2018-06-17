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

  //#ifndef ONLINE_JUDGE 
  //        close (0); open ("10693.in", O_RDONLY); 
  //        close (1); open ("10693.out", O_WRONLY | O_CREAT, 0600); 
  //#endif 
  
  double L,f;
  while(cin >> L)
  {
            cin >> f;
            if(L==0.0 && f==0.0)
                    return 0;
            double v=sqrt(L*f*2.0);
            double volume=(v*3600)/(2*L);
            printf("%0.8lf %0.8lf\n",v,volume);
  }
  return 0;
}
