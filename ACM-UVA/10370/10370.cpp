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
  int ntest;
  double ngente;
  double gente[1000];
  double por_encima;
  double total,media;
  
  #ifndef ONLINE_JUDGE 
          close (0); open ("10370.in", O_RDONLY); 
          close (1); open ("10370.out", O_WRONLY | O_CREAT, 0600); 
  #endif 
  cin >> ntest;
  
  while(ntest--)
  {
      cin >> ngente;
      total=0.0;
      for(i=0;i<ngente;i++)
      {
          cin >> gente[i];
          total+=gente[i];
      }    
      media=total/ngente;
      por_encima=0;
      for(i=0;i<ngente;i++)
      {
          if(gente[i]>media)
               por_encima++;
      }  
      total=(por_encima*100)/ngente;
      printf("%.3lf%%",total);
  
      printf("\n");
      
  }    
  return 0;
}
