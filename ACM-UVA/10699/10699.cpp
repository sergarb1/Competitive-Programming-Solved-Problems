#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdlib.h> 
#include <iostream>

using namespace std; 
#define MAX 1000001
char primos[MAX+1];



int main() 
{ 
  long long int i,j,k;

  #ifndef ONLINE_JUDGE 
          close (0); open ("10699.in", O_RDONLY); 
          close (1); open ("10699.out", O_WRONLY | O_CREAT, 0600); 
  #endif 
  
  
  // CRIBA previa para obtener los primos
  for (int i = 2; i <= MAX; i++)
	 primos[i] = 1;
  for (int i = 2; i <= MAX/2; i++)
	if (primos[i])
		for (int j = 2*i; j <= MAX; j += i)
			primos[j] = 0;
  
  long long int n;
  
  while(cin >> n)
  {
            long long int ntmp=n;
            long long int res=0;
            if(n==0)
                    return 0;
            
            if(primos[ntmp]==1)
            {
                               
                   cout << n <<" : 1" << endl;
                   continue;
            }
            while(ntmp>1)
            {
                         for(i=ntmp-1;i>=1;i--)
                         {
                             if(ntmp%i==0)
                             {
                                          if(primos[i]==1)
                                          {
                                               res++;
                                               do
                                               {
                                                    ntmp=ntmp/i;
                                               }while(ntmp%i==0);
                                               if(primos[ntmp]==1)
                                               {
                                                      if(ntmp>1)
                                                          res++;
                                                      ntmp=1;
                                                      break;
                                               }
                                               i=ntmp;          
                                          }
                             }
                         }
            }
            
            cout << n <<" : "<<res << endl;
  }
  return 0;
}
