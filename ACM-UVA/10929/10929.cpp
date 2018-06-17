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
          close (0); open ("10929.in", O_RDONLY); 
          close (1); open ("10929.out", O_WRONLY | O_CREAT, 0600); 
  #endif 
  char digitos[1010];
  while(cin.getline(digitos,1001))
  {
      int operacion=0;
      int impar=0;
      if(strcmp(digitos,"0")==0)
           return 0;
      int tam=strlen(digitos);
      
      for(i=tam-1;i>=0;i--)
      {
           
           if(impar==0)
           {
               impar=1;
               operacion-=(digitos[i]-'0');
           }
           else if(impar==1)
           {
               impar=0;
               operacion+=(digitos[i]-'0');
           }
      }
      if(operacion==0 || operacion%11==0)
      {
         cout << digitos << " is a multiple of 11."<<endl;
      }
      else
      {
          cout << digitos << " is not a multiple of 11." << endl;
      }
  }
  return 0;
}
