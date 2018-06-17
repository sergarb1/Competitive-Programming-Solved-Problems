#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdlib.h> 
#include <iostream>

using namespace std; 
char cadena[1000];
int main() 
{ 
  int i,j,k;
  int ntest;

  #ifndef ONLINE_JUDGE 
          //close (0); open (".in", O_RDONLY); 
          //close (1); open (".out", O_WRONLY | O_CREAT, 0600); 
  #endif 
  cin >> ntest;
  while(ntest--)
  {
      cin.getline(cadena,999);
      int tam=strlen(cadena);
      if(strcmp(cadena,"1")==0 ||strcmp(cadena,"4")==0 ||strcmp(cadena,"78")==0)
      {
          cout << "+"  << endl;
      }    
      else if(tam>2 && cadena[tam-1]=='5' && cadena[tam-2]=='3')
      {
          cout << "-" << endl;
      }    
      else if(cadena[0]=='9' && cadena[tam-1]=='4')
      {
          cout << "*" << endl;
      }    
      else if(tam>2 && cadena[0]=='1' && cadena[1]=='9' && cadena[2]=='0')
      {
          cout << "?" << endl;
      }    
      
  }    
  return 0;
}
