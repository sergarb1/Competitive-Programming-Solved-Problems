#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	char numero[1000];
	int i,j,k;
	int b1,b2;
	long long int num,ntemp;
	int ntest;

	#ifndef ONLINE_JUDGE
 		close (0);
		 open ("10019.in", O_RDONLY);
  		close (1); 
		open ("10019.out", O_WRONLY | O_CREAT, 0600);
	#endif

	cin >> ntest;

	for(i=0;i<ntest;i++)
	{

		int limite=0,tam;
		b1=0;
		b2=0;
		cin >> num;
		ntemp=num;
		//cout << "Num leido es : " << num << endl;
		while(ntemp>1)
		{
			//cout << "Valor previo ntemp y unos " << ntemp << " " << b1<<endl;
			if(ntemp%2==1)
			{
				ntemp--;
				b1++;
			}
			ntemp/=2;
		}
		b1++;
		sprintf(numero,"%d",num);
		ntemp=0;
		tam=strlen(numero);
		for(j=0;j<tam;j++)
		{
			ntemp+=((int)pow((double)16,(double)tam-1-j)*(int)(numero[j]-'0'));
		}
		//cout << "num "<<num<< " en hexa es " << ntemp << endl;
		while(ntemp>1)
		{
			if(ntemp%2==1)
				b2++;
			ntemp/=2;
		}
		b2++;
		
		cout << b1 << " " << b2 << endl;
		
	}
	return 0;
}
