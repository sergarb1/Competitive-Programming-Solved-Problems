#include <iostream>
#include <cstring>
using namespace std;

int N;
char texto[2000];
long long int res;

int haySuma()
{
	int t=strlen(texto);
	int i;
	for(i=0;i<t;i++)
	{
		if(texto[i]=='+')
			return 1;
	}
	return 0;
}
int main()
{
	int i;
	char tmp[3];
	cin >> N;
	res=0;
	cin.getline(tmp,2);
	for(i=0;i<N;i++)
	{
		cin.getline(texto,1000);
		int tmp=0;
		if(haySuma())
		{
			res++;
		}
		else
		{
			res--;
		}
	}
	cout << res << endl;
	return 0;
}
