#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int esprimo(int num);
void generar_anillo(int num,int pos);

int anillo[16];
int utilizado[17];
int N;
int inicia_caso=0,ntest=1;

int main()
{
	int i,j;

	#ifndef ONLINE_JUDGE
 		close (0);
		 open ("524.in", O_RDONLY);
  		close (1); 
		open ("524.out", O_WRONLY | O_CREAT, 0600);
	#endif
	
	while(cin >> N)
	{
		inicia_caso=0;
		for(i=0;i<=N;i++)
		{
			utilizado[i]=0;
		}		
		generar_anillo(1,0);
		cout << endl;
		ntest++;
	}
	return 0;
}

int esprimo(int num)
{
	double limite;
	int i;
	if(num%2==0)
		return 0;
	limite=sqrt((double)num);
	for(i=3;i<=(int)limite;i+=2)
	{
		if(num%i==0)
			return 0;
	}
	return 1;
}

void generar_anillo(int num,int pos)
{
	int i;
	
	anillo[pos]=num;
	utilizado[num]=1;
	if(pos==N-1)
	{
		if(inicia_caso==0)
		{
			inicia_caso=1;
			cout << "Case "<<ntest<<":" << endl;
		}
		cout << anillo[0];
		for(i=1;i<N;i++)
		{
			cout << " " << anillo[i];
		}
		cout << endl;

		
	}
	else if(pos==N-2)
	{
		for(i=1;i<=N;i++)
		{
			if(utilizado[i]==0)
			{
				if(esprimo(i+1) && esprimo(i+anillo[pos]))
				{
					generar_anillo(i,pos+1);
				}
			}
		}	
	}
	else
	{
		for(i=1;i<=N;i++)
		{
			if(utilizado[i]==0)
			{
				if(esprimo(i+anillo[pos]))
				{
					generar_anillo(i,pos+1);
				}
			}
		}	
	}
	utilizado[num]=0;
	anillo[pos]=0;

}
