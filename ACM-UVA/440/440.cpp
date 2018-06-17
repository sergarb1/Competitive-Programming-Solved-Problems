#include <iostream>

using namespace std;


int resuelve(int m,int n);


int main()
{
	int N,M;	
	int i,ultimo;

	while(cin >> N)
	{
		if(N==0)
			return 0;

		for(i=1;;i++)
		{
			ultimo=resuelve(i,N);
			if(ultimo==2)
			{
				cout << i << endl;
				break;
			}
		}
	}
	
	return 0;
}

int resuelve(int m,int n)
{
	int vector[151];
	int apagadas=0;
	int i,j;

	for(i=0;i<=150;i++)
		vector[i]=0;

	vector[1]=1;
	apagadas++;
	j=0;

	for(i=1;apagadas<n;i++)
	{
        while(vector[i]==1)
        {
         i++;
         if(i>n)
                i=i-n;
        }
        if(i>n)
		{
			i=i-n;
		}
		if(vector[i]==0 && j<m)
			j++;
		
		if(j==m && vector[i]==0)
		{
			j=0;
			apagadas++;
			vector[i]=1;
		   // cout << i << " " << m << endl;
			if(apagadas==n)
				return i;
			else if(i==2)
				return -1;
		}
        
		
		
	}
	return 0;
}
/*
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17
1 0 0 0 0 1 0 1 0 0  0  0  0  0  1  0  0

*/
