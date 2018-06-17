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
Te pide sumatorio i^3, pero si te fijas por induccion,
equivale a sumatorio de i, elevado al cuadrado el resultado.
Sumatorio de i equivale a ((1+i)/2) *i
**/
int main() 
{ 
  int i,j,k;

  #ifndef ONLINE_JUDGE 
          close (0); open ("10302.in", O_RDONLY); 
          close (1); open ("10302.out", O_WRONLY | O_CREAT, 0600); 
  #endif 
  long long int n;
  while(cin >> n)
  {
            long long int res=((1+n)*n)/2;
            res*=res;
            cout << res << endl;
  }
  return 0;
}
