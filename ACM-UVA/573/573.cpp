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
          close (0); open ("573.in", O_RDONLY); 
          close (1); open ("573.out", O_WRONLY | O_CREAT, 0600); 
  #endif 
	double H,U,D,F;
	while(cin >> H)
	{
		double disact=0.0;
		int dia=0;
		if(H==0.0)
			return 0;	
		cin >> U >> D >> F;
		// Calculo de la fatiga
		F=(F*U)/100;
		int encontrado=0;
		int primero=0;
		while(encontrado==0)
		{
			dia++;
			
			primero=1;
			disact+=U;
			//cout << "Subo " << U <<" con fatiga "<<F<<" y me quedo en "<<disact<< endl;
			if(disact>H)
			{
				encontrado=1;
				continue;
			}
			
			disact-=D;
			
			if(disact<0.0)
			{
				encontrado=2;
				continue;
			}
			
			//cout << "Bajo " << D <<" y me quedo en "<<disact<< endl;
			U-=F;
			if(U<0.0)
				U=0.0;
			
		}	
		if(encontrado==1)
		{
			cout << "success on day "<<dia<< endl;
		}
		else
		{
			cout << "failure on day "<<dia<< endl;

				
		}
	}
	
  return 0;
}
