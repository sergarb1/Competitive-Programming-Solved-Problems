#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <iostream>

using namespace std;

char diccionario[100][257];
char regla[257];
int npal;
int nrel;
char regla_construida[(257*257)+258];

void interpreta_regla(int pos_regla,char *r);

int main()
{
	int i,j,k;
	#ifndef ONLINE_JUDGE
  		close (0); open ("628.in", O_RDONLY);
  		close (1); open ("628.out", O_WRONLY | O_CREAT, 0600);
	#endif 

	while(cin >>  npal)
	{
		cout << "--" << endl;
		for(i=0;i<npal;i++)
		{
			cin >> diccionario[i];
		}	
		cin >> nrel;
		for(i=0;i<nrel;i++)
		{
			cin >> regla;
			interpreta_regla(0,regla_construida);
		}
	}

	return 0;
}


void interpreta_regla(int pos_regla,char *r)
{
	int i;
	
	if(regla[pos_regla]=='0')
	{
		for(i='0';i<='9';i++)
		{
			r[0]=i;
			interpreta_regla(pos_regla+1,r+1);
		}
	}
	else if(regla[pos_regla]=='#')
	{
		for(i=0;i<npal;i++)
		{
			strcpy(r,diccionario[i]);
			interpreta_regla(pos_regla+1,r+strlen(diccionario[i]));
			
		}	
	}
	else
	{
		r[0]=0;
		cout << regla_construida<<endl;
	}
	
}
