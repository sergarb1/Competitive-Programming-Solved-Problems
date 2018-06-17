#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <iostream>
using namespace std;

#define MAXN 50

int main()
{
    int bloques[MAXN];
    int N;
    int i;
    int num_test=1;
    int num_bloques;
    int num_mov;
    int pared;
    
    #ifndef ONLINE_JUDGE
        close (0); 
        open ("591.in", O_RDONLY);
        close (1); 
        open ("591.out", O_WRONLY | O_CREAT, 0600);
    #endif
    
    while(cin >> N)
    {
        if(N==0)
                return 0;
                
        num_bloques=0;
        num_mov=0;
        for(i=0;i<N;i++)
        {
            cin >> bloques[i];
            num_bloques+=bloques[i];
        }    
        pared=(int)(num_bloques/N);
        
        for(i=0;i<N;i++)
        {
            if(bloques[i]>pared)
            {
                num_mov+=(bloques[i]-pared);
            }    
        }    
        cout << "Set #" << num_test << endl;
        cout << "The minimum number of moves is " << num_mov << "." << endl;
        num_test++;
        cout << endl;
    }    
    return 0;
}
