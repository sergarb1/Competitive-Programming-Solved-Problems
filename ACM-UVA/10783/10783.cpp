#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <iostream>
using namespace std;

int main()
{
    long long int i,j,ntest,caso;
    long long int a,b,aux,res;
    
    #ifndef ONLINE_JUDGE
        //close (0); 
        //open (".in", O_RDONLY);
        //close (1); 
        //open (".out", O_WRONLY | O_CREAT, 0600);
    #endif
    cin >> ntest;
    caso=1;
    while(ntest--)
    {
        cin >> a >> b;
        if(a>b)
        {
            aux=a;
            a=b;
            b=aux;
        }    
        res=0;
        if(a%2==0)
            a++;
            
        for(i=a;i<=b;i+=2)
        {
            res+=i;
        }    
        cout << "Case "<<caso<<": "<<res <<endl;
        caso++; 
    }    
    
    return 0;
}
