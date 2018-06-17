#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{

	unsigned long int nmale=0,tmale=0;
	unsigned long int nfemale=1,tfemale=1;

/*
#ifndef ONLINE_JUDGE
  close (0); open ("11000.in", O_RDONLY);
  close (1); open ("11000.out", O_WRONLY | O_CREAT, 0600);
#endif 
*/
	int N;
	while(cin)
	{
		nmale=0;
		nfemale=1;
		cin >> N;
		if(N==-1)
			return 0;
		int i,j;
		
		for(i=0;i<N;i++)
		{
			tmale=nmale;
			tfemale=nfemale;
			nfemale=1+tmale;
			nmale=tfemale+tmale;
		}
	
		cout << nmale << " " <<nmale+nfemale << endl;
	}
	return 0;
}


<br />
<b>Notice</b>:  (null)(): [ALERT] Mailbox is at 84% of quota in <b>Unknown</b> on line <b>0</b><br />
