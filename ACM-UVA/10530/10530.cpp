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
          close (0); open ("10530.in", O_RDONLY); 
          close (1); open ("10530.out", O_WRONLY | O_CREAT, 0600); 
  #endif 

	
  int respuestas[11];
  char linea[120];

  int n;
  while(cin >> n)
  {
  	for(i=0;i<11;i++)
		respuestas[i]=0;
  	int hamentido=0;
	int primero=0;
  	do
  	{
		char tmp;
		if(primero!=0)
			cin >> n;
		if(n==0)
			return 0;
		primero=1;
		cin.get(tmp);
		cin.getline(linea,100);
		//cout << n << endl;
		//cout << linea << endl;
		if(respuestas[n]!=0)
		{
			if(strcmp(linea,"too high")==0 && respuestas[n]==-1)
			{
				hamentido=1;
			}
			else if(strcmp(linea,"too low")==0  && respuestas[n]==1)
			{
				hamentido=1;
			}
		}
		if(strcmp(linea,"too high")==0)
		{
			respuestas[n]=1;
		}
		else if(strcmp(linea,"too low")==0)
		{
			respuestas[n]=-1;
		}
  	}while(strcmp(linea,"right on")!=0);
  	
	if(hamentido==1)
  	{
		cout << "Stan is dishonest"<< endl;
		continue;
  	}
	else
	{
		for(i=1;i<=10;i++)
		{
			if(respuestas[i]==-1)
			{
				if(n<=i)
				{
					hamentido=1;
					break;
				}
			}
			else if(respuestas[i]==1)
			{
				if(n>=i)
				{
					hamentido=1;
					break;
				}
			}
		}
	}
	if(hamentido==1)
  	{
		cout << "Stan is dishonest"<< endl;
  	}
	else
	{
		cout << "Stan may be honest"<< endl;

	}
  }
  return 0;
}
