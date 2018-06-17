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
          close (0); open ("10050.in", O_RDONLY); 
          close (1); open ("10050.out", O_WRONLY | O_CREAT, 0600); 
  #endif 
  
  int ntest;
  cin >> ntest;
  
  while(ntest--)
  {
        int res=0;
        int dia=0;
        int N;
        int nparty;
        int p[150];
        int c[150];
        
        cin >> N;
        cin >> nparty;
        for(i=0;i<nparty;i++)
        {
             cin >> p[i];
             c[i]=0;
        }
        for(i=0;i<N;i++)
        {
             dia%=7;
             
             int hay_hartal=0;
             for(j=0;j<nparty;j++)
             {
                c[j]++;
                if(c[j]==p[j])
                {
                   c[j]=0;
                   hay_hartal=1;
                }
             }
             
             if(hay_hartal==1 && dia!=5 && dia!=6)
             {
                 res++;
             }
             dia++;
        }
        cout << res << endl;
  }
  return 0;
}
