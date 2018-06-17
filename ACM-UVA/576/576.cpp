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
          close (0); open ("576.in", O_RDONLY); 
          close (1); open ("576.out", O_WRONLY | O_CREAT, 0600); 
  #endif 
  char cadena[201];
  int tam;
  int silabas=0;
  int en_silaba=0;
  while(cin.getline(cadena,200))
  {
      tam=strlen(cadena);
      if(strcmp(cadena,"e/o/i")==0)
            return 0;
      silabas=0;
      for(i=0;cadena[i]!='/';i++)
      {
          if(cadena[i]=='a' ||cadena[i]=='e' ||cadena[i]=='i' ||cadena[i]=='o' ||cadena[i]=='u'||cadena[i]=='y')
          {
              while(1)
              {
                  if(cadena[i]=='a' ||cadena[i]=='e' ||cadena[i]=='i' ||cadena[i]=='o' ||cadena[i]=='u'||cadena[i]=='y')
                            i++;
                  else
                            break;
              }    
              silabas++;
              if(cadena[i]=='/')
                        break;
          }    
      }    
      if(silabas!=5)
      {
          cout << "1" << endl;
          continue;
      }
      i++;
      silabas=0;
      for(;cadena[i]!='/';i++)
      {
          if(cadena[i]=='a' ||cadena[i]=='e' ||cadena[i]=='i' ||cadena[i]=='o' ||cadena[i]=='u'||cadena[i]=='y')
          {
              while(1)
              {
                  if(cadena[i]=='a' ||cadena[i]=='e' ||cadena[i]=='i' ||cadena[i]=='o' ||cadena[i]=='u'||cadena[i]=='y')
                            i++;
                  else
                            break;
              }    
              silabas++;
              if(cadena[i]=='/')
                        break;
          }    
      }    
      
      if(silabas!=7)
      {
          cout << "2" << endl;
          continue;
      }
      
      i++;
      silabas=0;
      for(;i<tam;i++)
      {
          if(cadena[i]=='a' ||cadena[i]=='e' ||cadena[i]=='i' ||cadena[i]=='o' ||cadena[i]=='u'||cadena[i]=='y')
          {
              while(1)
              {
                  if(cadena[i]=='a' ||cadena[i]=='e' ||cadena[i]=='i' ||cadena[i]=='o' ||cadena[i]=='u'||cadena[i]=='y')
                            i++;
                  else
                            break;
              }    
              silabas++;
              if(cadena[i]=='/')
                        break;
          }    
      }    
      
      if(silabas!=5)
      {
          cout << "3" << endl;
      }
      else
      {
          cout << "Y" << endl;
      }    
              
  }    
  
  return 0;
}
