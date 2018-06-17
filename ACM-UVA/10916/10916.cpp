#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdlib.h> 
#include <iostream>

using namespace std; 

double log2(int n)
{
       return log(n)/log(2);
}

int main() 
{ 
  int i,j,k;

  #ifndef ONLINE_JUDGE 
          close (0); open ("10916.in", O_RDONLY); 
          close (1); open ("10916.out", O_WRONLY | O_CREAT, 0600); 
  #endif 
  int x;
  int res;
  while(cin >> x)
  {
        if(x==0)
                return 0;
        x=(x-1960)/10;
        x=4*pow(2,x);
        // Tras esto, x tiene el numero de bits de la computadora de ese año
        
        //Basandome en la explicacion matematica de ximo usando propiedades de logaritmos :
        double tmp=1,k=0;
        int res=3;
        k=x;
        tmp+=log2(res);
              
        while(tmp<=k)
        {
             res++;
             tmp+=log2(res);
        }
        cout << res-1 << endl;     
  }
  return 0;
}
