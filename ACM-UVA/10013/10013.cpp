#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

#include <iostream>
using namespace std;


int main()
{
	int i,j,k;
	
	int s_a[1000001];
	int s_b[1000001];
	
	int temp;
	int acarreo;
	
	int N,M;
	
	#ifndef ONLINE_JUDGE
        close (0); 
        open ("10013.in", O_RDONLY);
        close (1);
        open ("10013.out", O_WRONLY | O_CREAT, 0600);
    	#endif
	
	cin >> N;
	
	for(i=0;i<N;i++)
	{
		cin >> M;
		
		for(j=0;j<M;j++)
		{
			cin >> s_a[j];
			cin >> s_b[j];
		}
		acarreo=0;
		for(j=M-1;j>=0;j--)
		{
			temp=s_a[j]+s_b[j]+acarreo;
			if(temp>=10)
			{
				acarreo=1;
				s_a[j]=temp-10;
			}
			else
			{
				acarreo=0;
				s_a[j]=temp;
			}
		}
		if(acarreo==1)
		{
			cout << '1';
		}
		for(j=0;j<M;j++)
		{
			cout << s_a[j];
		}
		cout << endl;
		cout << endl;
			
	}
	
	return 0;
}

