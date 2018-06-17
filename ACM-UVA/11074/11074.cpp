#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdlib.h> 
#include <iostream>

using namespace std; 

void dibuja_linea(int T,int ancho)
{
     int i,j;
     for(i=0;i<T;i++)
     {
        for(j=0;j<ancho;j++)
        {
            cout << "*";
        }
        cout << endl;
     }
}

void dibuja_grid(int S,int T,int N)
{
     int i,j,k;
     
     for(i=0;i<S;i++)
     {
        for(j=0;j<N;j++)
        {
            for(k=0;k<T;k++)
            {
               cout << "*";
            }
            for(k=0;k<S;k++)
            {
               cout << ".";
            }
        }
        for(k=0;k<T;k++)
        {
            cout << "*";
        }
        cout << endl;
     }
}

int main() 
{ 
  int i,j,k;

  #ifndef ONLINE_JUDGE 
          close (0); open ("A.in", O_RDONLY); 
          close (1); open ("A.out", O_WRONLY | O_CREAT, 0600); 
  #endif 
  int S,T,N;
  int ancho;
  int ncaso=1;
  int primero=0;
  while(1)
  {
          cin >> S;
          cin >> T;
          cin >> N;
          if(primero==0)
          {
              primero=1;
          }
          else
          {
              cout << endl;
          }
          if(S==0 && T==0 && N==0)
              return 0;
          cout << "Case "<<ncaso++<<":"<<endl;
          ancho=S*N+((T)*(N+1));
          
          for(i=0;i<N;i++)
          {
              dibuja_linea(T,ancho);
              dibuja_grid(S,T,N);
          }
          dibuja_linea(T,ancho);
          
  }
  return 0;
}
