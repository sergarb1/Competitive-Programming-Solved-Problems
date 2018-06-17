#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdlib.h> 
#include <iostream>

using namespace std;






int espalindromo(char pal[])
{
	int i,j;
	i=0;
	j=strlen(pal)-1;
	
	while(i<j)
	{
		if(pal[i]!=pal[j])
		{
			//cout << pal[i] << "$" << pal[j] << endl;
			return 0;
		}
		i++;
		j--;
	}
	return 1;
}



int esespejo(char pal[])
{/* Para espejo*/

char tabesp[200];
tabesp['A']='A';
tabesp['B']=0;
tabesp['C']=0;
tabesp['D']=0;
tabesp['E']='3';
tabesp['F']=0;
tabesp['G']=0;
tabesp['H']='H';
tabesp['I']='I';
tabesp['J']='L';
tabesp['K']=0;
tabesp['L']='J';
tabesp['M']='M';
tabesp['N']=0;
tabesp['O']='O';
tabesp['P']=0;
tabesp['Q']=0;
tabesp['R']=0;
tabesp['S']='2';

tabesp['T']='T';
tabesp['U']='U';
tabesp['V']='V';
tabesp['W']='W';
tabesp['X']='X';
tabesp['Y']='Y';
tabesp['Z']='5';
tabesp['1']='1';
tabesp['2']='S';
tabesp['3']='E';
tabesp['4']=0;
tabesp['5']='Z';
tabesp['6']=0;
tabesp['7']=0;
tabesp['8']='8';
tabesp['9']=0;
	int i,j;
	i=0;
	j=strlen(pal)-1;
	
	while(i<=j)
	{
		if(tabesp[pal[i]]!=pal[j])
		{
			//cout << pal[i] << "$" << tabesp[pal[i]] << "$" << pal[j] << endl;
			return 0;
		}
		i++;
		j--;
	}
	return 1;
}


int main() 
{ 
  int i,j,k;
  char palabra[200];
  #ifndef ONLINE_JUDGE 
          close (0); open ("401.in", O_RDONLY); 
          close (1); open ("401.out", O_WRONLY | O_CREAT, 0600); 
  #endif 
	int primero=1;

	while(cin.getline(palabra,100,'\n'))
	{
		if(primero==0)
			cout << endl;
		primero=0;
		int espal=espalindromo(palabra);
		int esmir=esespejo(palabra);
		//cout << palabra<<endl;
		if(espal==1)
		{
			if(esmir==1)
			{
				cout <<palabra<< " -- is a mirrored palindrome." << endl;
			}
			else
			{
				cout <<palabra<< " -- is a regular palindrome."<< endl;
			}
		}
		else if(esmir==1)
		{
			cout <<palabra<< " -- is a mirrored string."<< endl;
		}
		else
		{
			cout <<palabra<< " -- is not a palindrome." << endl;
		}
	}
  return 0;
}
