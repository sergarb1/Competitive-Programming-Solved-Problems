#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdlib.h> 
#include <iostream>

using namespace std; 
char caracteres[1000002];
int cambios[1000002];
int main() 
{ 
  int i,j,k;

  #ifndef ONLINE_JUDGE 
          close (0); open ("10324.in", O_RDONLY); 
          close (1); open ("10324.out", O_WRONLY | O_CREAT, 0600); 
  #endif 
  int ncasos,npruebas;
  ncasos=0;
  while(cin.getline(caracteres,1000000))
  {
      int tam=strlen(caracteres);
      cambios[0]=0;
      for(i=1;i<tam;i++)
      {
          if(caracteres[i]!=caracteres[i-1])
          {
             cambios[i]=cambios[i-1]+1;
          }
          else
          {
             cambios[i]=cambios[i-1];
          }
      }
      ncasos++;
      cout << "Case "<<ncasos<<":"<< endl;
      cin >> npruebas;
      for(i=0;i<npruebas;i++)
      {
              int x,y,aux;
              cin >> x;
              cin >> y;
              if(x>y)
              {
                     aux=y;
                     y=x;
                     x=aux;
              }
              char dig=caracteres[x+1];
              
              if(cambios[x]==cambios[y])
              {
                   cout << "Yes" << endl;
              }
              else
              {
                  
                   cout << "No" << endl;
              }
      }
      char tmp;
      cin.get(tmp);
  }
  
  return 0;
}
