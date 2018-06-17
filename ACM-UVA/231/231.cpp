#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <iostream>

using namespace std;

#define MAX 33000

int heigth[MAX];
int length[MAX];

int main()
{
	int i,j,k;
	#ifndef ONLINE_JUDGE
  		close (0); open ("231.in", O_RDONLY);
  		close (1); open ("231.out", O_WRONLY | O_CREAT, 0600);
	#endif 
	int ntest=0;
	long long int num,nnum,mayor;
	while(cin >> num)
	{
		ntest++;
		if(num==-1)
			return 0;
		heigth[0]=num;
		length[0]=1;
		num=0;
		nnum=0;
	

		num=0;
		for(nnum=1;num!=-1;nnum++)
		{
			cin >> num;
			if(num!=-1)
			{
				heigth[nnum]=num;
				length[nnum]=1;
			}
			else
				break;
			
			
		}
		for (i = 0 ;i<nnum-1;i++)
			for (j = i+1 ;j<nnum;j++)
				if (heigth[j] < heigth[i])
				{
					if (length[i] + 1 > length[j])
					{	
						length[j] = length[i] + 1;
					}
				}
		mayor=0;
		for(i=0;i<nnum;i++)
		{
			//cout << length[i] << endl;
			if(length[i]>length[mayor])
				mayor=i;
		}
		cout << "Test #"<<ntest<<":"<<endl;
		cout <<"  maximum possible interceptions: "<<length[mayor]<<endl<<endl;
		
		
	
	}
	

	return 0;
}
