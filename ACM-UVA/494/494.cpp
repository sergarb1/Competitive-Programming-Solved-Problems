#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

#include <iostream>
using namespace std;

#define MAX 100000
char buffer[MAX];
char temp;

int main()
{

    
    int i,j,k;
 
    int tam;
    
    #ifndef ONLINE_JUDGE
        close (0); 
        open ("494.in", O_RDONLY);
        close (1); 
        open ("494.out", O_WRONLY | O_CREAT, 0600);
    #endif
    
    int num_pab=0;
    
    while(!feof(stdin))
    {
    	int i=0;
	num_pab=0;
	fgets(buffer,MAX,stdin);
	
	if(feof(stdin))
		return 0;
		
	tam=strlen(buffer);
	
	
	
	for(i=0;i<tam;i++)
	{
		if(isalpha(buffer[i]))
		{
			while(isalpha(buffer[i]))
			{
				i++;
			}
			num_pab++;
		}	
	}
	printf("%d\n",num_pab);
	
	
    }
    
    return 0;
     
}
