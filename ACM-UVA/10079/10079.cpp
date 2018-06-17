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
          close (0); open ("10079.in", O_RDONLY); 
          close (1); open ("10079.out", O_WRONLY | O_CREAT, 0600); 
  #endif 
  
  long long int n;
  /** Para n=0 , una region 
  para n>=1 , r(n)=r(n-1)+n
  De ahi sacamos la formula
  
  **/
  
  while(cin >> n)
  {
            if(n<0)
                   return 0;
            long long int res=1+((1+n)*n/2);
            cout << res<<endl;
  }
  return 0;
}
