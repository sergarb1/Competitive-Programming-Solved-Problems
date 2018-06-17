#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

#include <iostream>
using namespace std;


int construccion[5001][3];

int alturas[100000];

int main()
{
	int i,j,k;
	int n_const;
	int max_j;
	int inicio,actual;
	
	#ifndef ONLINE_JUDGE

        close (0); 

        open ("105.in", O_RDONLY);

      /*  close (1); 

        open ("105.out", O_WRONLY | O_CREAT, 0600);
*/
    	#endif
	
	n_const=0;
	
	while(cin >> construccion[n_const][0])
	{
		cin >> construccion[n_const][1];
		cin >> construccion[n_const][2];
		n_const++;
	}
	
	//qsort(construccion,n_const,sizeof(construccion[0]),comparar);
	max_j=0;
	
	for(i=0;i<n_const;i++)
	{
		for(j=construccion[i][0];j<construccion[i][2];j++)
		{
			if(construccion[i][1]>alturas[j])
				alturas[j]=construccion[i][1];
				
			if(j>max_j)
			{
				max_j=j;
			}
		}
	}
	//cout << max_j << endl;
	i=0;
	/*while(alturas[i]==0)
		i++;
	*/
	for(;i<max_j;i++)
	{
		
		if(i<max_j)
		{	
			actual=alturas[i]; 
			
			while(alturas[i]==actual)
			{
				i++;
				if(i>max_j)
				{	
				
					cout << max_j+1 << ' '<< '0' ;
					cout << endl;
					return 0;
				}
				
			}
			cout << i << ' '<< alturas[i] << ' ' ;
		}
	}
	
	cout << max_j+1 << ' '<< '0' ;
				
	cout << endl;
	return 0;
}

/*
int comparar(const void *arg1, const void *arg2);
{
	if(*(int *)arg1[0]>*(int *)arg1[0])
	{
		return -1;
	}
	else if(*(int *)arg1[0]<*(int *)arg1[0])
	{
		return 1;
	}
	else
	{
		return 0;
	}
	 
}
*/
