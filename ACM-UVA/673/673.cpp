#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <iostream>
using namespace std;
#define MAX 300


char parentesis[MAX];
int inicio=0,fin=0;
int ncor=0;


int subarea();

int main()
{
    int i,j,k;
    int ntest,res;
    char temp[2];
    
    #ifndef ONLINE_JUDGE
        close (0); 
        open ("673.in", O_RDONLY);
        close (1); 
        open ("673.out", O_WRONLY | O_CREAT, 0600);
    #endif
    
    cin >> ntest ;
    cin.getline(temp,1);
    for(i=0;i<ntest;i++)
    {
        cin.getline(parentesis,MAX);
        //cout << parentesis << endl;
        ncor=0;
        inicio=0;
        fin=strlen(parentesis);
        
        res=subarea();
        
        //cout << ncor << endl;
        
        
        if(res!=1 || ncor!=0)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }        
        
    }    
    
    return 0;
}

int subarea()
{
    int npar=0;
    
while(inicio<fin)
{    
    if(parentesis[inicio]=='(')
    {
        npar++;
    }    
    else if(parentesis[inicio]==')')
    {
        npar--;
    }    
    else if(parentesis[inicio]=='[')
    {
        inicio++;
        ncor++;
        if(subarea()==0)
                return 0;
    }    
    else if(parentesis[inicio]==']')
    {
        if(ncor>0 && npar==0)
        {
            ncor--;
            return 1;
        }
        else
            return 0;    
    }
    
    if(npar<0)
    {
        return 0;
    }
    inicio++;
}
    if(npar==0)
        return 1;
    else
        return 0;   
}    

