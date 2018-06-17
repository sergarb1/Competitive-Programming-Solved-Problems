#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <iostream>
using namespace std;

#define MAX 13

int k;
int res[6];
int S[MAX];

void genera(int pos,int posk);

int main()
{
    int i,j;
    #ifndef ONLINE_JUDGE
        close (0); 
        open ("441.in", O_RDONLY);
        close (1); 
        open ("441.out", O_WRONLY | O_CREAT, 0600);
    #endif
    
    while(cin >> k)
    {
        if(k==0)
                return 0;
                
        for(i=0;i<k;i++)
        {
            cin >> S[i];
        }    
        for(i=0;i<k;i++)
        {
                genera(0,i);
        }    
        cout << endl;
    }    
    
    
    return 0;
}

void genera(int pos,int posk)
{
    int i;
    
    res[pos]=S[posk];
    
    if(pos==5)
    {
        cout << res[0];
        for(i=1;i<6;i++)
        {
            cout << " " << res[i];
        }
        cout << endl;
        return;
    }
    
    if(pos+(k-posk)<5)
    {
        return;
    }    
    
    for(i=posk+1;i<k;i++)
    {
        genera(pos+1,i);
    }    
    return;    
        
}    
