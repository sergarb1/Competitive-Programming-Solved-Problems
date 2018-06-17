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
  char s[1000002],t[1000002];
  
  #ifndef ONLINE_JUDGE 
          close (0); open ("10340.in", O_RDONLY); 
          close (1); open ("10340.out", O_WRONLY | O_CREAT, 0600); 
  #endif 
  while(cin.getline(s,1000000,' '))
  {
      int tams,tamt,poss,post;
      poss=0;
      post=0;
      cin.getline(t,1000000,'\n');
      tams=strlen(s);
      tamt=strlen(t);
      for(i=0;i<tamt;i++)
      {
          if(s[poss]==t[i])
          {
             poss++;
          }
      }
      if(poss==tams)
      {
          cout << "Yes" << endl;
      }
      else
      {    
          cout << "No" << endl;
      }
  }
  return 0;
}
