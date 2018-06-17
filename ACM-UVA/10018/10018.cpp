#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <iostream>
using namespace std;

int es_palindromo(char *buf);
long long int reverso(char *buf);

int main()
{
    char buffer[20];
    int N;
    long long int num;
    int i,j;
    
    
    cin >> N;
    for(i=0;i<N;i++)
    {
        
        cin >> num;
        j=0;
        while(j<=1200)
        {
                sprintf(buffer,"%lld",num);
                //cout << j << ' ' << buffer << endl;
                if(es_palindromo(buffer))
                {
                            cout << j << ' ' << buffer << endl;
                            break;
                } 
                num+=reverso(buffer);   
                j++;
        }    
    }    
    return 0;
}

long long  int reverso(char *buf)
{
    int i,j;
    int tam=strlen(buf);
    long long int res;
    char aux;
    
    for(i=0,j=tam-1;j>i;i++,j--)
    {
        aux=buf[i];
        buf[i]=buf[j];
        buf[j]=aux;
    }    
    res=atoi(buf);
    return res;
}    


int es_palindromo(char *buf)
{
    int i,j;
    int tam=strlen(buf);
    long int res;
    char aux;
    
    for(i=0,j=tam-1;j>i;i++,j--)
    {
        if(buf[i]!=buf[j])
                return 0;
    }    
    return 1;
}    
