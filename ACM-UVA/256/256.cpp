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
          close (0); open ("256.in", O_RDONLY); 
          close (1); open ("256.out", O_WRONLY | O_CREAT, 0600); 
  #endif 
  /** Problema resuelto con precalculo, el programa para precalcular es hacer lo que pide simplemente pocas casos de entrada y mucho tiempo de cpu. **/
  
  
  
  int n;
  while(cin >> n)
  {
         if(n==2)
         {
                 cout << "00" << endl;
                 cout << "01" << endl;
                 cout << "81" << endl;
         }
         else if(n==4)
         { 
             cout << "0000" << endl;
             cout << "0001" << endl;
             cout << "2025" << endl;
             cout << "3025" << endl;
             cout << "9801" << endl;
         }
         else if(n==6)
         {
              
               cout << "000000" << endl;
               cout << "000001" << endl;
               cout << "088209" << endl;
               cout << "494209" << endl;
               cout << "998001" << endl;
         }
         else if(n==8)
         {
              
                 cout << "00000000" << endl;
                 cout << "00000001" << endl;
                 cout << "04941729" << endl;
                 cout << "07441984" << endl;
                 cout << "24502500" << endl;
                 cout << "25502500" << endl;
                 cout << "52881984" << endl;
                 cout << "60481729" << endl;
                 cout << "99980001" << endl;
         }   
  }
  return 0;
}
