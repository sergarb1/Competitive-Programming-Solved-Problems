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
	
	char caracter;
	int comillas=0;
	
	#ifndef ONLINE_JUDGE

        close (0); 

        open ("272.in", O_RDONLY);

       close (1); 

        open ("272.out", O_WRONLY | O_CREAT, 0600);

    	#endif
	
	while(1)
	{
		scanf("%c",&caracter);
		//printf("%c\n",caracter);
		if(feof(stdin))
			return 0;
		if(caracter=='"')
		{
			if(comillas==0)
			{
				comillas=1;
				printf("``");
			}
			else if(comillas==1)
			{
				comillas=0;
				printf("''");
			}
		}
		else
		{
			printf("%c",caracter);
		}
	}
	
	
	return 0;
}

