#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

char cadena [120];
int p,q,r,s,t;


/**
K AND
A OR
N NOT
C IMPLICES
E EQUALS
**/

int es_tautologia()
{
	stack<int> pila;
	int tam=strlen(cadena);
	int i,j;
	for(i=tam-1;i>=0;i--)
	{
		if(cadena[i]=='p')
		{
			pila.push(p);
		}
		else if(cadena[i]=='q')
		{
			pila.push(q);
		}	
		else if(cadena[i]=='r')
		{
			pila.push(r);
		}	
		else if(cadena[i]=='s')
		{
			pila.push(s);
		}	
		else if(cadena[i]=='t')
		{
			pila.push(t);
		}	
		else if(cadena[i]=='K')
		{
			int p1,p2;
			p1=pila.top();
			pila.pop();
			p2=pila.top();
			pila.pop();
			int res;
			res=p1 && p2;
			pila.push(res);
		}	
		else if(cadena[i]=='A')
		{

			int p1,p2;
			p1=pila.top();
			pila.pop();
			p2=pila.top();
			pila.pop();

			int res;
			res=p1 || p2;
			pila.push(res);
		}	
		else if(cadena[i]=='N')
		{

			int p1;
			p1=pila.top();
			pila.pop();

			int res;
			res=!p1;
			pila.push(res);
		}	
		else if(cadena[i]=='C')
		{

			int p1,p2;
			p1=pila.top();
			pila.pop();
			p2=pila.top();
			pila.pop();

			int res;
			if(p2>=p1)
			{
				res=1;
			}
			else
				res=0;
			pila.push(res);
		}	
		else if(cadena[i]=='E')
		{

			int p1,p2;
			p1=pila.top();
			pila.pop();
			p2=pila.top();
			pila.pop();
			int res;
			res=p1==p2;
			pila.push(res);
		}	
		
	}
	return pila.top();
}

int tautologia()
{
	for(p=0;p<=1;p++)
	{
		
		for(q=0;q<=1;q++)
		{

			for(r=0;r<=1;r++)
			{
		
				for(s=0;s<=1;s++)
				{
					for(t=0;t<=1;t++)
					{
						if(es_tautologia()==0)
							return 0;
					}
			
				}
			}
		}
		
	}	
	return 1;
}



int main()
{

	while(cin.getline(cadena,110))
	{
		if(strcmp(cadena,"0")==0)
			return 0;
			

		int sol=tautologia();
		if(sol==0)
		{
			cout << "not" << endl;
		}
		else
			cout << "tautology" << endl;
	}
	return 0;
}
