#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdlib.h> 
#include <iostream>

using namespace std; 

int es_primo(unsigned long long int n)
{
	unsigned long long int i,j,k;
	unsigned long long int limite=(unsigned long long int)sqrt((double)n);
	if(n%2==0)
		return 0;
	for(i=3;i<=limite;i+=2)
	{
		if(n%i==0)
		{
			return 0;
		}
	}
	return 1;
}
int es_primo_estadistico(unsigned long long int n)
{
	double potencia;
	for(double i=2;i<n;i++)
	{
		potencia=pow(i,(double)n);
		//cout << potencia << endl;
		if(((unsigned long long int)floor(potencia))%n==0)
			return 1;
	}
	return 0;
	
}


int main() 
{ 
  int i,j,k;
  
  unsigned long long int n;
  #ifndef ONLINE_JUDGE 
          close (0); open ("10006.in", O_RDONLY); 
          close (1); open ("10006.out", O_WRONLY | O_CREAT, 0600); 
  #endif 

  while(cin >> n)
  {
     if(n==0)
	return 0;
     if(es_primo_estadistico(n))
     {
         if(es_primo(n))
         {
		cout << n <<" is normal."<< endl;
         }
	 else
         {
		cout << "The number "<<n<<" is a Carmichael number."<< endl;
         }
     }
     else
     {
		cout << n <<" is normal."<< endl;
     }
  }
  return 0;
}
