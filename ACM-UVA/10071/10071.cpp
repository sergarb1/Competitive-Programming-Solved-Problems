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
	
	double velocidad,tiempo,aceleracion,espacio;
	#ifndef ONLINE_JUDGE

        close (0); 
        open ("10071.in", O_RDONLY);
        close (1);
        open ("10071.out", O_WRONLY | O_CREAT, 0600);

    	#endif
	
	while(cin >> velocidad)
	{
		cin >> tiempo;
		
		//printf("v=%lf t=%lf\n",velocidad,tiempo);
		if(tiempo==0)
		{
			cout <<'0' << endl;
		}
		else
		{
			aceleracion=velocidad/tiempo;
			espacio=aceleracion*(double)(tiempo*2)*(double)(tiempo*2)*(double)(0.5);
			cout << espacio << endl;
		}
	}
	return 0;
}

