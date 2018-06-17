#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdlib.h> 
#include <iostream>

using namespace std; 

int maximo(int a,int b)
{
    if(a>b)
           return a;
    return b;
}




int lis(int s1[],int tam)
{
  int i,j;
  int max=0;
  int mejores[21];
  for(i=0;i<tam;i++)
  {
      mejores[i]=1;
  }
  for(i=tam-1;i>=0;i--)
  {                    
      for(j=i+1;j<tam;j++)
      {
          if ( s1[j] > s1[i] )
          {
            mejores[i] = maximo( mejores[i] , mejores[j]+1 );
          }
      }
  }
  
  
  for(i=0;i<tam;i++)
  {
     if(mejores[i]>max)
     {
          max=mejores[i];
     }
  }

  return max;
}


int main() 
{ 
  int i,j,k;

  #ifndef ONLINE_JUDGE 
          close (0); open ("111.in", O_RDONLY); 
          close (1); open ("111.out", O_WRONLY | O_CREAT, 0600); 
  #endif 
  int correcto[21];
  int respuesta[21];
  int n;
  cin >> n;
  
          int tmp;
  for(i=0;i<n;i++)
  {
                cin >> tmp;
                correcto[tmp-1]=i;
  }
  
  while(1)
  {
          int tmp;
          for(i=0;i<n;i++)
          {
                cin >> tmp;
                respuesta[tmp-1]=i;
          }
          
          if(cin.eof())
           {
                    return 0;
           }
          int envio[21];
          for(i=0;i<n;i++)
          {
                  for(j=0;j<n;j++)
                  {
                      if(respuesta[i]==correcto[j])
                      {
                          envio[i]=j;
                          break;
                      }
                  }
          }
          int res=lis(envio,n);
          cout << res << endl;
          
          if(cin.eof())
           {
                    return 0;
           }
          
           
  }
  return 0;
}
