#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int i,j,k;
	int I,V,X,L,C;

	int numero;
	#ifndef ONLINE_JUDGE
  		//close (0); open ("344.in", O_RDONLY);
  		//close (1); open ("344.out", O_WRONLY | O_CREAT, 0600);
	#endif 
	
	while(cin >> numero)
	{
		int ntemp=numero;
		
		if(numero==0)
			return 0;
		I=0;
		V=0;
		X=0;
		L=0;
		C=0;
		for(i=1;i<=numero;i++)
		{
			ntemp=i;
			while(ntemp>0)
			{
				if(ntemp>=100)
				{
					ntemp-=100;
					C++;
				}
				else if(ntemp>=50)
				{

					if(ntemp>=90)
					{
						ntemp-=40;
						L--;
						C++;
						X++;
					}
					ntemp-=50;
					L++;
				}
				else if(ntemp>=10)
				{
					if(ntemp>=40)
					{
						ntemp-=30;
						L++;
					}
					ntemp-=10;
					X++;
				}
				else if(ntemp>=5)
				{

					if(ntemp==9)
					{
						ntemp-=4;
						V--;
						I++;
						X++;
					}
					ntemp-=5;
					V++;
				}
				else if(ntemp>=1)
				{	
					if(ntemp==4)
					{
						ntemp-=3;
						V++;
					}
					ntemp-=1;
					I++;
				}
			}
		}
		
	
		cout << numero << ": " << I << " i, " << V << " v, " << X << " x, " << L << " l, " << C << " c" << endl;
		
	}

	return 0;
}
