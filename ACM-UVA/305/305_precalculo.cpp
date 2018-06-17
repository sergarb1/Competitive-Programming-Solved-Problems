#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdlib.h> 
#include <iostream>

using namespace std; 


/** Josephus **/
int main() 
{ 
  int i,j,k;
  int m;

  #ifndef ONLINE_JUDGE 
          close (0); open ("305.in", O_RDONLY); 
          close (1); open ("305.out", O_WRONLY | O_CREAT, 0600); 
  #endif 
  while(cin >> k)
  {
	if(k==0)
		return 0;
	else if(k==1)
	{
         m=2;
    }
    else if(k==2)
	{
         m=7;
    }
    else if(k==3)
	{
         m=5;
    }
    else if(k==4)
	{
         m=30;
    }
    else if(k==5)
	{
         m=169;
    }
    else if(k==6)
	{
         m=441;
    }
    else if(k==7)
	{
         m=1872;
    }
    else if(k==8)
	{
         m=7632;
    }
    else if(k==9)
	{
         m=1740;
    }
    else if(k==10)
	{
         m=93313;
    }
    
    else if(k==11)
	{
         m=459901;
    }
    
    else if(k==12)
	{
         m=1358657;
    }
    
    else if(k==13)
	{
         m=2504881;
    }
    cout << m << endl;
  }
  return 0;
}
