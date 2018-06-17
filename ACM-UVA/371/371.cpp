#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <iostream>

using namespace std;

long long int funcion(long long int num);

int main()
{
	long long int i,j,k;
	#ifndef ONLINE_JUDGE
  		close (0); open ("371.in", O_RDONLY);
  		close (1); open ("371.out", O_WRONLY | O_CREAT, 0600);
	#endif 
	long long int a,b,res,aux,max,max_n;

	while(cin >> a)
	{
		max=0;
		cin >> b;

		if(a==0 && b==0)
			return 0;
		if(a>b)
		{
			aux=a;
			a=b;
			b=aux;
		}

		for(i=a;i<=b;i++)
		{
			res=funcion(i);
			if(res>max)
			{
				max=res;
				max_n=i;
			}
			
		}
		
		cout << "Between "<< a <<" and "<< b <<", "<< max_n <<" generates the longest sequence of "<< max <<" values." << endl;
	}

	return 0;
}

long long int funcion(long long int num)
{
	long long int vueltas=0;

	do 
	{
		if(num%2==0)
		{
			num/=2;
		}
		else
		{
			num=(3*num)+1;
		}
		vueltas++;
	}while(num!=1);

	return vueltas;
}
