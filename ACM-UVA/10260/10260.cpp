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
          close (0); open ("10260.in", O_RDONLY); 
          close (1); open ("10260.out", O_WRONLY | O_CREAT, 0600); 
  #endif 
  char cadena[300];
  char cad[50];
   for(i='A';i<='Z';i++)
   {
       cadena[i]=0;
   }     
   cadena['B']=1;
   cadena['F']=1;
   cadena['P']=1;
   cadena['V']=1;
   
   cadena['C']=2;
   cadena['G']=2;
   cadena['J']=2;
   cadena['K']=2;
   cadena['Q']=2;
   cadena['S']=2;
   cadena['X']=2;
   cadena['Z']=2;
   
   cadena['D']=3;
   cadena['T']=3;
   
   cadena['L']=4;
   
   
   cadena['M']=5;
   cadena['N']=5;
   
   
   cadena['R']=6;
   
   
  
  while(cin.getline(cad,30,'\n'))
  {
      int tam=strlen(cad);
      int num_ant=0;
      for(i=0;i<tam;i++)
      {
          if(cadena[cad[i]]!=0 && cadena[cad[i]]!=num_ant)
          {
              num_ant=(int)cadena[cad[i]];
              cout << (int)cadena[cad[i]];
          }   
          else if(cadena[cad[i]]==0)
          {
              num_ant=0;
          }
   
      }    
      cout << endl;
  }
  
  return 0;
}
