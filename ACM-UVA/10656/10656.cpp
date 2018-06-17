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
    int i,j;
    int n;
    int num;
    char temp[2];
    int hay_suma=0;
    
    int max_sub=-1;
    
    #ifndef ONLINE_JUDGE
        close (0); 
        open ("10656.in", O_RDONLY);
        close (1); 
        open ("10656.out", O_WRONLY | O_CREAT, 0600);
    #endif
    
    while(cin >> n )
    {
        hay_suma=0;
        temp[0]=0;
        if(n==0)
                return 0;
                
        for(i=0;i<n;i++)
        {
            
            cin >> num;
            if(num>0)
            {
                hay_suma=1;
                cout << temp << num;
                temp[0]=' ';
                temp[1]=0;
                
            }    
        }    
        if(hay_suma==0)
        {
            cout << '0';
        }    
        cout << endl;
    }    
    
    return 0;
}
