#include <iostream>
using namespace std;

int N;
int A,B,C,res;
int main()
{
	int i;
	cin >> N;
	res=0;
	for(i=0;i<N;i++)
	{
		cin >> A >> B >> C;
		int tmp=0;
		if(A==1)
			tmp++;
		if(B==1)
			tmp++;
		if(C==1)
			tmp++;
		if(tmp>=2)
		{
			res++;
		}
	}
	cout << res << endl;
	return 0;
}
