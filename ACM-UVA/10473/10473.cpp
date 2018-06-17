#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <iostream>
using namespace std;

   
#define MAX 3000

long long int hex_to_dec(char *cad)
{
    int i,j;
    int tam=strlen(cad);
    long long int exponencial=1;
    long long int res=0;
    for(i=tam-1;i>=2;i--) // Se ignoran 0 y x
    {
        int hval;
        if(cad[i]>='A' && cad[i]<='F')
        {
            hval=cad[i]-'A'+10;
        }    
        else if(cad[i]>='1' && cad[i]<='9')
        {
            hval=cad[i]-'0';
        }    
        else
        {
                exponencial*=16;
                continue;
        }    
        res+=exponencial*hval;
        exponencial*=16;
    }    
    return res;
    
}    

void dec_to_hex(long long int num,char *cad)
{
    int i,j;
    int pos=0,tam;
    while(num>=16)
    {
        cad[pos]=num%16;
        if(cad[pos]>=10)
        {
            cad[pos]-=10;
            cad[pos]+='A';
        }
        else
        {
            cad[pos]+='0';
        }        
        num/=16;
        pos++;
        
    }    
    cad[pos]=num;
    if(cad[pos]>=10)
    {
            cad[pos]-=10;
            cad[pos]+='A';
    }
    else
    {
           cad[pos]+='0';
    } 
    pos++;
    cad[pos]=0;
    tam=strlen(cad);
    for(i=0,j=tam-1;i<j;i++,j--)
    {
        char aux;
        aux=cad[i];
        cad[i]=cad[j];
        cad[j]=aux;
    }    
    
    
}    

int main()
{
    char num[MAX],cad[MAX];
    #ifndef ONLINE_JUDGE
        //close (0); 
        //open ("10473.in", O_RDONLY);
        //close (1); 
        //open ("10473.out", O_WRONLY | O_CREAT, 0600);
    #endif
    
    while(cin.getline(num,MAX))
    {
        if(num[0]=='-')
                return 0;
        if(num[1]=='x')
        {
            
            cout << hex_to_dec(num) << endl;
        }
        else
        {
            dec_to_hex(atol(num),cad);
            cout << "0x" << cad << endl;
        }        
    }    
    
    return 0;
}
