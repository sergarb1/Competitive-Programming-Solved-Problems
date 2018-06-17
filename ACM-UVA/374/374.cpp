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
          close (0); open ("374.in", O_RDONLY); 
          close (1); open ("374.out", O_WRONLY | O_CREAT, 0600); 
  #endif 
  long long int b,p,n,s,t,u;
  while(cin >> b)
  {
            
            
       cin >> p;
       cin >> n;
       /** Como los apuntes de Criptografia,
       Si el exponente tiene un 1,se multiplica por la base elevado (a la posicion en el exponente mod n)
       Para manterne la base de la posicion, tras cada movimiento la elevamos al cuadrado mod m)
       **/
       s=1; t=b; u=p;
	   while(u) {
		        if (u&1) 
                   s=(s*t)%n;
		u>>=1;
		t=(t*t)%n;
	  }
       
  
       cout << s << endl;
  }
  
  return 0;
}
