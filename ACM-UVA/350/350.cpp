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

  int enciclo[10000];
  int i,j,k;
  long long int Z, I, M, L,LINI;
  #ifndef ONLINE_JUDGE 
          close (0); open ("350.in", O_RDONLY); 
          close (1); open ("350.out", O_WRONLY | O_CREAT, 0600); 
  #endif 
	long long int ncaso=0;
	long long int inc=0;
	while(cin >> Z >> I >> M >> L)
	{
		for(i=0;i<10000;i++)	
		{
			enciclo[i]=0;
		}
		if(Z==0 && I==0 && M==0 && L==0)
		{
			return 0;
		}
		inc=0;
		//cout << Z  << " "<<  I <<  " "<< M << " "<< L<<endl;
		L=L%M;
		Z=Z%M;
    		LINI=L;
		do
		{
			L=(((Z*L)%M)+I)%M;
			if(enciclo[L]==1)
			{
				break;
			}
			inc++;
			enciclo[L]=1;
		//	cout << L << endl;
		}while(1);
		ncaso++;
		cout << "Case "<<ncaso<<": "<<inc<<endl;
		
  	}
  return 0;
}
