#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <iostream>
using namespace std;

void sumar(char *a,char *b, char *r);

char n1[6000];
char n2[6000];
char calc[5001][6000];
int main()
{
    int i,j;
    int num;
    int calculado;
    #ifndef ONLINE_JUDGE
        close (0); 
        open ("495.in", O_RDONLY);
        close (1); 
        open ("495.out", O_WRONLY | O_CREAT, 0600);
    #endif
    calculado=1;
     n1[0]='0';
        n1[1]=0;
        n2[0]='1';
        n2[1]=0;
        strcpy(calc[0],n1);
        strcpy(calc[1],n2);
        
        for(i=2;i<=5000;i++)
        {
             sumar(n1,n2,calc[i]);
             strcpy(n1,n2);
             strcpy(n2,calc[i]);  
            // cout << i <<  endl; 
        } 
    
    while(cin >> num)
    {
          
        cout << "The Fibonacci number for " << num << " is " << calc[num] << endl;
            
        
    }    
    
    return 0;
}


void sumar(char *a,char *b, char *r)
{
    int carry;
	int tam1,tam2;
	char *aux;
	int ax;
	int diff,tam;
	
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
		r[i]=0;
	
	diff=tam2-tam1;
	
	carry=0;
	for(i=tam2-1;i>=0;i--)
	{
		int t1=0,t2=0;
		
		if(carry>0)
		{
			r[tam2-i-1]+=carry;
			carry=0;
		}
		if(i-diff>=0)
			t1=a[i-diff]-'0';
		else
			t1=0;
			
		t2=b[i]-'0';
		t2+=t1;
		
			
		r[tam2-i-1]+=t2;
		if(r[tam2-i-1]>9)
		{
			r[tam2-i-1]-=10;
			carry=1;
		}
		r[tam2-i-1]+='0';
	}
	if(carry>0)
	{
		r[tam2-i-1]=carry+'0';
	}
	
	tam=strlen(r);
	
	for(i=0;i<tam-i-1;i++)
	{
	    char tmp;
	    tmp=r[i];
	    r[i]=r[tam-i-1];
	    r[tam-i-1]=tmp;
	}    
	r[tam]=0;
	
}    
