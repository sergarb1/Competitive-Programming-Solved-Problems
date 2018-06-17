#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>

#include <iostream>
using namespace std;

long long int  BitValue[101][101];

int main()
{
    int i,j;
    
    for(i=0;i<=100;i++)
    {
        BitValue[0][i]=1;
    }   
    
    for(i=1;i<=100;i++)
    {
        for(j=1;j<=100;j++)
        {
            BitValue[i][j]=(BitValue[i][j-1]+BitValue[i-1][j])%1000000;
           // cout << BitValue[i][j]<< " "; 
        }    
        //cout << endl;
    } 
    int N,K;
    #ifndef ONLINE_JUDGE
        //close (0); 
      //  open ("A.in", O_RDONLY);
       // close (1); 
        //open ("A.out", O_WRONLY | O_CREAT, 0600);
    #endif

    while(cin >> N >> K)
    {
      long long int res=0;
        if(N==0 && K==0)
                return 0;
     
            res=BitValue[N][K];
      
        cout << res << endl;
          
    }    
    
    return 0;
}

/*
003
030
300
012
102
120
021
111
*/
