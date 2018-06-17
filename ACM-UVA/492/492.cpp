#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <ctype.h>
#include <math.h> 
#include <string.h>
#include <stdlib.h> 
#include <iostream>

using namespace std; 
int isvowel(char c)
{
	if(c=='A' || c=='a' || c=='E' || c=='e' || c=='I' || c=='i' || c=='O' || c=='o' || c=='U' || c=='u')
		return 1;
	else
		return 0;
}
int main() 
{ 
  int i,j,k;

  #ifndef ONLINE_JUDGE 
          close (0); open ("492.in", O_RDONLY); 
          close (1); open ("492.out", O_WRONLY | O_CREAT, 0600); 
  #endif 

	char c;
	int enpalabra=0;
	int hayconsonante=0;
	char cons;
	while(cin.get(c))
	{
		if(enpalabra==1)
		{
			if(isalpha(c))
			{
				cout << c;
			}
			else
			{
				enpalabra=0;
				if(hayconsonante==1)
				{
					cout << cons;
				}
				cout << "ay";
				cout << c;
			}

		}
		else
		{
			if(isalpha(c))
			{
				enpalabra=1;
				if(isvowel(c))
				{
					
					hayconsonante=0;
					cout << c;
				}
				else
				{
					cons=c;
					hayconsonante=1;
				}
			}
			else
			{
				cout << c;	
			}
		}
	}

  return 0;
}
