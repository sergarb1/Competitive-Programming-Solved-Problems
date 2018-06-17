#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>

#include <iostream>
using namespace std;

int main()
{
    int i,j;
    #ifndef ONLINE_JUDGE
        close (0); 
        open ("113.in", O_RDONLY);
        close (1); 
        open ("113.out", O_WRONLY | O_CREAT, 0600);
    #endif
    double p,n,k;
    
    while(scanf("%lf",&n)==1)
    {
        scanf("%lf",&p);
        k=exp(log(p)/n);
        printf("%.0lf\n", k);
    }    
    
    
    
    
    
    return 0;
}
