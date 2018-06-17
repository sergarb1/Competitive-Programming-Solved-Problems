#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdlib.h> 
#include <iostream>

using namespace std; 

int comparar(const void *a,const void *b)
{
    int x=*((int *)a);
    int y=*((int *)b);
    return x-y;
}

int main() 
{ 
  int i,j,k;

  #ifndef ONLINE_JUDGE 
          close (0); open ("11057.in", O_RDONLY); 
          close (1); open ("11057.out", O_WRONLY | O_CREAT, 0600); 
  #endif 
  int n,dinero;
  int precios[12000];
  int sol1,sol2;
  int primero=0;
  while(cin >> n)
  {
            for(i=0;i<n;i++)
            {
                cin >> precios[i];
            }
            qsort(precios,n,sizeof(precios[0]),comparar);
            cin >> dinero; 
            
            i=0;j=n-1;
            
            while(i<j)
            {
                 if(precios[i]+precios[j]==dinero)
                 {
                    sol1=precios[i];
                    sol2=precios[j];
                    i++;
                    j--;
                 }
                 else if(precios[i]+precios[j]<dinero)
                 {
                      i++;
                 }
                 else
                 {
                      j--;
                 }
            }
            if(primero==1)
            {
                cout << endl;
            }
            cout << "Peter should buy books whose prices are "<< sol1 <<" and "<< sol2 <<"."<<endl;
            primero=1;
  }
  return 0;
}
