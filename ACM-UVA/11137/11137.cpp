#include <iostream>

using namespace std;

const int MAX=10201;
int nmon=0;

int mon[22];

unsigned long long dp[200][MAX];


int main()
{
	int i,j,k;
	long long int n;
	
	for(i=1;i<=21;i++)
	{
		mon[nmon++]=i*i*i;
	}
	
	for(i=0;i<MAX;i++)
		dp[0][i]=1;	

	for(i=1;i<nmon;i++)
	{
		for(j=0;j<mon[i];j++)
		{
			dp[i][j]=dp[i-1][j];
		}
	
		for(j=mon[i];j<MAX;j++)
		{
			dp[i][j]=dp[i-1][j]+dp[i][j-mon[i]];
		}
	}
	while(cin >> n)
	{
		cout << dp[20][n]<<endl;
	}
}
