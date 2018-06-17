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
  long long int i,j,k;

  #ifndef ONLINE_JUDGE 
          close (0); open ("694.in", O_RDONLY); 
          close (1); open ("694.out", O_WRONLY | O_CREAT, 0600); 
  #endif 
  long long int a,limit;
  long long int ntest=1;
  while(1)
  {
          long long int aor;
          cin >> a;
          cin >> limit;
          aor=a;
           long long int npasos=0;
           if(a==-1 && limit==-1)
                    return 0;
           while(a!=1 && a<=limit)
           {
                 npasos++;
                 if(a%2==0)
                           a/=2;
                 else
                     a=(3*a)+1;
           }      
           if(a==1)
                   npasos++;
           cout << "Case "<<ntest<<": A = "<<aor<<", limit = "<<limit<<", number of terms = "<<npasos<<endl;     
           ntest++;
  }
  return 0;
}
