#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <cctype>

using namespace std;

int main()
{
  #ifndef ONLINE_JUDGE
          close (0); open ("494.in", O_RDONLY);
          close (1); open ("494.out", O_WRONLY | O_CREAT, 0600);
  #endif

  int cont;
  char caracter;
  bool anterior;

  cont=0;
  anterior=false;
  do
  {
       caracter=cin.get();
       if(isalpha(caracter))
       {
           while(isalpha(caracter))
           {
             caracter=cin.get();
           }
           cont++;
       }
       
       if(caracter=='\n' || caracter==EOF)
       {
            cout<<cont<<endl;
            cont=0;
            anterior=false;
       }
       
  }while(caracter!=EOF);

  return 0;
}
