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
    int i,j,k,l,n_test;
    int A,F;
    
    #ifndef ONLINE_JUDGE
        close (0); 
        open ("488.in", O_RDONLY);
        close (1); 
        open ("488.out", O_WRONLY | O_CREAT, 0600);
    #endif
    
    cin >> n_test;
    
    for(i=0;i<n_test;i++)
    {
        cin >> A;
        cin >> F;
        for(j=0;j<F;j++)
        {
            for(k=1;k<=A;k++)
            {
                for(l=0;l<k;l++)
                {
                    cout << k;
                }    
                cout << endl;
            }
            for(k=A-1;k>=1;k--)
            {
                for(l=0;l<k;l++)
                {
                    cout << k;
                }    
                cout << endl;
            }    
            cout << endl;
            
        }    
    }    
    
    return 0;
}
