#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>

using namespace std;


int esmayor(unsigned long long int n,unsigned long long int m,unsigned long long int n1,unsigned long long int m1)
{
	
	n=n*m1;
	n1=n1*m;
	if(n>n1)
		return 1;
	return 0;
}

int main()
{
	char paso[10000];
	int i;
	unsigned long long int n,m;
	unsigned long long int nactual,mactual,nantde,mantde,nantiz,mantiz;
	while(cin >> n)
	{
		cin >> m;
		if(n==1 && m==1)
			return 0;
		nantiz=1;
		mantiz=1;
		nantde=1;
		mantde=1;
		if(n>m)
		{
			paso[0]='R';
			
			nactual=2;
			mactual=1;
			nantiz=1;
			mantiz=1;
			nantde=1;
			mantde=0;
		}
		else
		{

			nactual=1;
			mactual=2;
			
			paso[0]='L';
			nantiz=0;
			mantiz=1;
			nantde=1;
			mantde=1;
		}
		i=1;
		while(nactual!=n || mactual!=m)
		{
			unsigned long long int niz,miz,niztmp,miztmp,nde,mde;
			niz=nactual+nantiz;
			miz=mactual+mantiz;
			nde=nactual+nantde;
			mde=mactual+mantde;
			/* Como decidir a cual ir*/
			niztmp=niz+nantiz;
			miztmp=miz+mantiz;
			if(esmayor(n,m,nactual,mactual))
			{
					paso[i++]='R';

					nantiz=nactual;
					mantiz=mactual;
					nactual=nde;
					mactual=mde;
					
					//cout << 'R' << " " << nactual<<" " << mactual<<endl;
	
			}	
			else
			{

				paso[i++]='L';
				nantde=nactual;
				mantde=mactual;
				nactual=niz;
				mactual=miz;

					//cout << 'L' << " " << nactual<<" " << mactual<<endl;
			}
		} 
		paso[i]=0;
		cout << paso << endl;
		
	}
	return 0;
}
