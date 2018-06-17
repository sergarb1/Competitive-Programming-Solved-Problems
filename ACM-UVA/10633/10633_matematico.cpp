#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#include <iostream>
using namespace std;


int main()
{
    unsigned long long numero,num_temp;
    unsigned long long i;
    
    
    #ifndef ONLINE_JUDGE
        close (0); 
        open ("10633.in", O_RDONLY);
        close (1); 
        open ("10633.out", O_WRONLY | O_CREAT, 0600);
    #endif
    char buffer[1000];
    while(cin >> numero)
    {
      if(numero==0)
         break;
      num_temp = (numero*10)/9;
      if(numero%9==0)
         cout <<num_temp-1 << " " <<num_temp<<endl;
      else
         cout <<num_temp<<endl;
   
    }    
    return 0;
}
