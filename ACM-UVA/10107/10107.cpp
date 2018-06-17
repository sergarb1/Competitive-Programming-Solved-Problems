#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int compara(const void *a,const void *b);

int main()
{
	int i,j,k;
	#ifndef ONLINE_JUDGE
  		close (0); open ("10107.in", O_RDONLY);
  		close (1); open ("10107.out", O_WRONLY | O_CREAT, 0600);
	#endif 
	
	int array[10000];
	int nel,res;

	nel=0;
	while(cin >> array[nel])
	{
		nel++;
		qsort(array,nel,sizeof(array[0]),compara);
		/*cout << endl;
		for(i=0;i<nel;i++)
		{
			cout <<array[i] <<endl;
		}
		cout << endl;*/

		if(nel%2==0)
		{
			res=(int)(array[(int)(nel/2)] + array[(int)((nel/2)-1)])/2;
		
		}
		else
		{
			res=array[(nel/2)];
		}
		cout << res << endl;
	}

	return 0;
}

int compara(const void *a,const void *b)
{
	return *(int *)a - *(int *)b;
}
