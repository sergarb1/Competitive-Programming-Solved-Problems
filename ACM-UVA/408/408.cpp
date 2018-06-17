#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <iostream>
using namespace std;


#define MAX 100000

int STEP,MOD;
int n_num;
int matriz[MAX];


void seed(int x);

int main()
{
    
    
    
    #ifndef ONLINE_JUDGE
        close (0); 
        open ("408.in", O_RDONLY);
        close (1); 
        open ("408.out", O_WRONLY | O_CREAT, 0600);
    #endif
    
    while(cin >> STEP)
    {
        cin >> MOD;
        n_num=0;
        seed(0);
        cout << '\t' << STEP << '\t' << MOD << '\t';
        //cout << n_num << endl;
        
        if(n_num==MOD)
        {
            cout << "Good Choice" << endl;
        }
        else
        {
            cout << "Bad Choice" << endl;
        }    
        cout << endl;
        
    }    
    
    return 0;
}

void seed(int x)
{
    if(matriz[x]==0)
    {
        matriz[x]=1;
        n_num++;
    }    
    else
    {
        matriz[x]=0;
        return;
    }
    seed((x+STEP)%MOD);
    matriz[x]=0;        
}    
