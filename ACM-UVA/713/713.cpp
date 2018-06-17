#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

#include <iostream>
using namespace std;


void sumar(char * a,char * b);

void revierte(char * cadena);

#define MAX 201
char num1[MAX];
char num2[MAX];
char suma[MAX];


int main()
{

    
    int i,j,k;
 
    int tam;
    
    int n_numeros;
    
    #ifndef ONLINE_JUDGE
        close (0); 
        open ("494.in", O_RDONLY);
        close (1); 
        open ("494.out", O_WRONLY | O_CREAT, 0600);
    #endif
    
    scanf("%d",&n_numeros);
    
    for(i=0;i<n_numeros;i++)
    {
    	scanf("%s",num1);
    	scanf("%s",num2);
	revierte(num1);
	revierte(num2);
	//printf("%s %s\n",num1,num2);
	sumar(num1,num2);
	
	
    }
    
    return 0;
     
}

void revierte(char * cadena)
{
	char temp;
	int tam;
	int i,j;
	tam=strlen(cadena);
	
	for(i=0,j=tam-1;i<j;i++,j--)
	{
		temp=cadena[i];
		cadena[i]=cadena[j];
		cadena[j]=temp;
	}
	

}

void sumar(char * a,char * b)
{
	int carry;
	int tam1,tam2;
	char *aux;
	int ax;
	int diff,tam;
	char *s=suma;
	
	int i,j;
	
	tam1=strlen(a);
	tam2=strlen(b);
	
	if(tam1>tam2)
	{
		ax=tam1;
		tam1=tam2;
		tam2=ax;
		aux=a;
		a=b;
		b=aux;
	}
	for(i=0;i<=tam2+1;i++)
		s[i]=0;
	
	diff=tam2-tam1;
	
	carry=0;
	for(i=tam2-1;i>=0;i--)
	{
		int t1=0,t2=0;
		
		if(carry>0)
		{
			s[tam2-i-1]+=carry;
			carry=0;
		}
		if(i-diff>=0)
			t1=a[i-diff]-'0';
		else
			t1=0;
			
		t2=b[i]-'0';
		t2+=t1;
		
			
		s[tam2-i-1]+=t2;
		if(s[tam2-i-1]>9)
		{
			s[tam2-i-1]-=10;
			carry=1;
		}
		s[tam2-i-1]+='0';
		//printf("%c\n",s[tam2-i-1]);
	}
	if(carry>0)
	{
		s[tam2-i-1]=carry+'0';
	}
	
	while((s[0]=='0'))
	{
		s++;
	}
	tam=strlen(s);
	
	i=tam-1;
	while(s[i]=='0')
	{
		s[i]=0;
		i--;
	}
	
	printf("%s\n",s);
}
