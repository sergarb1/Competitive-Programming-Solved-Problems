#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdlib.h> 
#include <iostream>
#include <iomanip>


using namespace std; 

int sonido_letra(char a)
{
    if(a=='B' || a=='F' || a=='P' || a=='V')
    {
              return 1;
    }
    if(a=='C' || a=='S' || a=='K' || a=='G' || a=='J' || a=='Q' || a=='X' || a=='Z')
    {
              return 2;
    }
    if(a=='D' || a=='T')
    {
              return 3;
    }
    if(a=='L')
    {
              return 4;
    }
    if(a=='M' || a=='N')
    {
              return 5;
    }
    if(a=='R')
    {
              return 6;
    }
    
    
    
    return -1;
}

int main() 
{ 
  int i,j,k;

  #ifndef ONLINE_JUDGE 
          close (0); open ("739.in", O_RDONLY); 
          close (1); open ("739.out", O_WRONLY | O_CREAT, 0600); 
  #endif 
  char sonido[40];
  int marcado[7];
  int resultado[40];
  char res[5];
  int tamres,tamcad;
  
  
  cout << setw(10) << "NAME" << setw(35) << "SOUNDEX CODE"<<endl;
  //printf("%10s%35s\n","NAME","SOUNDEX CODE");
  while(cin.getline(sonido,30))
  {
      tamres=0;
      for(i=0;i<7;i++)
          marcado[i]=0;
      tamcad=strlen(sonido);
      
      int codigo,codigoant;
      for(i=0;i<tamcad;i++)
      {
          if(i==0)
          {
                  codigo=sonido_letra(sonido[i]);
          }
          else
          {
                  codigoant=codigo;
                  codigo=sonido_letra(sonido[i]);
                  if(codigoant!=codigo && codigo!=-1)
                  {
                      resultado[tamres++]=codigo;
                  }
          }
      }
      res[0]=sonido[0];
      for(i=0;i<3;i++)
      {
          if(i<tamres)
          {
              res[i+1]=resultado[i]+'0';
          }
          else
          {
              res[i+1]='0';
          }
      }
      res[i+1]=0;
  
  cout << setw(10) << sonido << setw(35) << res<<endl;    
  //printf("%10s%35s\n",sonido,res);
  }
  cout << setw(20) <<"END OF OUTPUT" << endl;
  return 0;
}
