#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <iostream>

using namespace std;

long long int esprimo(long long int num);

int main()
{
	int primero=0;
	int i;

	#ifndef ONLINE_JUDGE
 		close (0);
		 open ("583.in", O_RDONLY);
  		close (1); 
		open ("583.out", O_WRONLY | O_CREAT, 0600);
	#endif

	long long int N,limite;

	while(cin >> N)
	{
		primero=0;
		if(N==0)
			return 0;
		
		cout << N << " =";
		if(N<0)
		{
			primero=1;
			cout << " -1";
			N*=-1;
		}
		while(N%2==0)
		{

			N/=2;
			if(primero==1)
			{
				cout <<" x 2";
			}
			else
			{
				cout <<" 2";
				primero=1;
			}
		}

		limite=(long long int)sqrt((double)N)+1;

		for(i=3;i<=limite;i+=2)
		{
			if(N%i==0 && esprimo(i))
			{
				while(N%i==0)
				{
					N/=i;
					if(primero==1)
					{
						cout <<" x "<< i;
					}
					else
					{
						cout <<" "<<i;
						primero=1;
					}
				}
				limite=(long long int)sqrt((double)N)+1;
			}
		}
		if(N!=1)
		{
			if(primero==1)
			{
				cout <<" x "<< N;
			}
			else
			{
				cout <<" "<<N;
				primero=1;
			}
		}
		cout << endl;
	}
	return 0;
}


long long int esprimo(long long int num)
{
	long long int limite;
	int i;
	if(num%2==0)
		return 0;
	limite=(long long int)sqrt((double)num)+1;
	for(i=3;i<=limite;i+=2)
	{
		if(num%i==0)
			return 0;
	}
	return 1;
}
