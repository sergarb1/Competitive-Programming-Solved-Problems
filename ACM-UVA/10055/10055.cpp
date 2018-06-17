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
    
    #ifndef ONLINE_JUDGE
        close (0); 
        open ("10055.in", O_RDONLY);
        close (1); 
        open ("10055.out", O_WRONLY | O_CREAT, 0600);
    #endif
    
    long long int a,b,res;
    
    while(cin >> a)
    {
        cin >> b;
        
        res=a-b;
        if(res<0)
                res*=-1;
        cout << res << endl;
    }    
    
    return 0;
}
