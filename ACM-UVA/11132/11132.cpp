#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>

using namespace std;
char tiradas[2000];

long long int calcular(int pos,int npilla)
{
	long long int res=0;
	long long int elevado=1;
	for(int i=0;i<npilla;i++)
	{
		if(tiradas[npilla+pos-i-1]=='T')
		{
			res+=elevado;
		}
		
		elevado*=2;
	}
	return res+1;
}

int main()
{
	long long int ndados,numeros;
	char tmp;
	while(cin >> ndados)
	//while(scanf("%d%c%d",&ndados,&tmp,&numeros)!=0)
	{
		if(ndados==0 || numeros==0)
			return 0;
		cin.get(tmp);
		cin >> numeros;
		cin.get(tmp);
		
		
		long long int res=0;
		//scanf("%s",tiradas);
		cin.getline(tiradas,1500,'\n');
		long long int npilla=(int)ceil((log((double)numeros)/log(2.0)));
		long long int nmonedas=strlen(tiradas);
		//printf("%d %d %d %d\n\n",ndados,numeros,npilla,nmonedas);
		for(int i=0;i+npilla<=nmonedas && ndados>0;i+=npilla)
		{
			long long int r=calcular(i,npilla);
			if(r<=numeros)
			{
				res+=r;
				ndados--;	
			}
		}
		if(ndados>0)
			res=-1;
		printf("%lld\n",res);
	}
	return 0;
}
