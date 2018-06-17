#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdlib.h> 
#include <iostream>

using namespace std; 
char tabla[1000000];


int generar(int n)
{
    int i;
    char numero[12];
    int num=n,tam;
    sprintf(numero,"%d",n);
    tam=strlen(numero);
    for(i=0;i<tam;i++)
    {
        num+=numero[i]-'0';
    }    
    return num;      
}    


int main() 
{ 
  int i,j,k;
  int temp;
  #ifndef ONLINE_JUDGE 
          //close (0); open (".in", O_RDONLY); 
          close (1); open ("640.out", O_WRONLY | O_CREAT, 0600); 
  #endif 
  
  for(i=0;i<1000000;i++)
  {
      int temp=generar(i);
      if(temp<=1000000)
            tabla[temp]=1;
  }    
  for(i=0;i<=1000000;i++)
  {
      if(tabla[i]!=1)
      {
          cout << i << endl;
      }    
  }
  return 0;
}
