#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int i,j,k;
	char binario[20000];
	#ifndef ONLINE_JUDGE
  		//close (0); open ("10931.in", O_RDONLY);
  		//close (1); open ("10931.out", O_WRONLY | O_CREAT, 0600);
	#endif 
	long long int num,ntemp,tam;

	long long int n1s=0;
	while(cin >> num)
	{
		n1s=0;
		if(num==0)
			return 0;
		ntemp=num;
		i=0;
		while(ntemp>1)
		{
			if(ntemp%2==1)
			{
				n1s++;
				ntemp--;
				binario[i]='1';
			}
			else
			{
				binario[i]='0';
			}
			ntemp/=2;
			i++;
		}
		binario[i]='1';
		binario[i+1]=0;
		
		n1s++;
		tam=strlen(binario);
		for(i=0,j=tam-1;i<j;i++,j--)
		{
			char tmp;
			tmp=binario[i];
			binario[i]=binario[j];
			binario[j]=tmp;
			
		}
		cout << "The parity of "<<binario<<" is "<<n1s<< " (mod 2)."<<endl;
	}

	return 0;
}
