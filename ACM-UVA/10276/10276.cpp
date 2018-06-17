#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdlib.h> 
#include <iostream>

using namespace std; 

  int n,npalos;
  int palos[100];
  
int main() 
{ 
  int i,j,k;
  cin >> n;
  
  for(i=0;i<n;i++)
  {
       int nbolas=1;
       cin >> npalos;
       for(j=0;j<npalos;j++)
       {
           palos[j]=0;
       }
       for(k=0;k<npalos;k++)
       {
           if(palos[k]==0)
           {
                palos[k]=nbolas;
                nbolas++;
                
                k=-1;
           }
           else 
           {
                double res,res1;
                res=sqrt(palos[k]+nbolas);
                res1=floor(res);
                if(res==res1)
                {
                   palos[k]=nbolas;
                   nbolas++;
                   k=-1;
                    
                }
           }
       }
       cout << nbolas-1<< endl;
       
       
       
  }
  return 0;
}
