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
  char ds[33];
  char us[33];
  char tmp;
  int i,j,k;

  int up_shift=0;
  int potencia,res;
  #ifndef ONLINE_JUDGE 
          close (0); open ("740.in", O_RDONLY); 
          close (1); open ("740.out", O_WRONLY | O_CREAT, 0600); 
  #endif 

  fgets(ds,33,stdin);
  cin.get(tmp);
  //cout << ds<<endl;
  fgets(us,33,stdin);
  cin.get(tmp);
  //cout << us<<endl;
  res=0;
  potencia=4;
  while(cin.get(tmp))
  {
      if(tmp=='\n')
      {
              up_shift=0;
            cout << endl;
            continue;
      }    
      res+=(tmp-'0')*(int)pow(2.0,(double)potencia);
      potencia--;
      if(potencia==-1)
      {
          if(res==31)
          {
              up_shift=1;
          }    
          else if(res==27)
          {
              up_shift=0;
          }    
          else if(up_shift==1)
          {
              cout << us[res];
          }
          else
          {
              cout << ds[res];
          }        
          potencia=4;
          res=0;
      }    
  }    
  
  
  return 0;
}
