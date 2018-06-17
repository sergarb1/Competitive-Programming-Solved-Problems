#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdlib.h> 
#include <iostream>

using namespace std; 

int resuelve(int k,int m)
{
    
    int vivos[29];      
    int nmalos=0;
    int pos=0;
    int pasos;
    for(int i=k+1;i<=k*2;i++)
    {
            vivos[i]=0;
    }
    while(nmalos<k)
    {
             pasos=m;
             while(pasos>0)
             {
                 pos++;
                 if(pos>k*2)
                     pos=1; 
                  
                 if(vivos[pos]!=-1)
                 {   pasos--;
                 }
             }    
             
             if(pos<=k)
                 return 0;  
             vivos[pos]=-1;
             nmalos++;
    }
    return 1;
}

/** Josephus **/
int main() 
{ 
  int i,j,k;

  #ifndef ONLINE_JUDGE 
          close (0); open ("305.in", O_RDONLY); 
          close (1); open ("305.out", O_WRONLY | O_CREAT, 0600); 
  #endif 
  while(cin >> k)
  {
      if(k==0)
              return 0;
      int solucion=0;
      for(i=k+1;!solucion;i++)
      {
           solucion=resuelve(k,i);
      }
      cout << i-1 << endl;
  }
  return 0;
}
