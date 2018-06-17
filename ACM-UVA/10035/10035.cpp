#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

#include <iostream>
using namespace std;

#define MAX 11

int carry_ops(char *a,char *b);


int main()
{
	int i,j,k;
	char n1[MAX];
	char n2[MAX];
	int resultado;
	
	
	while(cin >> n1)
	{
		cin >> n2;
		
		if(strcmp(n1,"0")==0 && strcmp(n2,"0")==0)
			return 0;
		resultado=carry_ops(n1,n2);
		if(resultado==0)
			cout << "No carry operation." << endl;
		else if(resultado==1)
			cout << "1 carry operation." << endl;
		else
			cout << resultado << " carry operations." << endl;
		
	}
	
	return 0;
}


int carry_ops(char *a,char *b)
{
	int i;
	int c_ops=0;
	int carry;
	int res;
	
	int tama=strlen(a);
	int tamb=strlen(b);
	
	res=0;
	
	for(i=1;i<=tama && i<=tamb;i++)
	{
		res+=(int)((a[tama-i]-'0')+(b[tamb-i]-'0'));
		
		if(res>9)
		{
			c_ops++;
			res=1;
		
		}
		else
		{
			res=0;
		}
			
	}
	if(tama==tamb || res==0)
		return c_ops;
	else if(tama>tamb )
	{
		while(a[tama-i]=='9' && i<=tama)
		{
			c_ops++;
			i++;
		}
	}
	else
	{
		while(b[tamb-i]=='9' && i<=tamb)
		{
			c_ops++;
			i++;
		}
	}	
	return c_ops;
	
}
