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

  int N;
  int num;
  int ones;
while(cin >> num)
{ 
    N=1;
    ones=1;
    k=1;
    while(k!=0)
    {
        N=k;
        if (N < num)
           N=N*10+1;
        ones++;
        k = N%num; 
    }
    cout << ones << endl;
  }
  return 0;
}
