#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    
    int ntest;
    int i,j,k;
    
    #ifndef ONLINE_JUDGE
        close (0); 
        open ("10098.in", O_RDONLY);
        close (1); 
        open ("10098.out", O_WRONLY | O_CREAT, 0600);
    #endif

    char temp;
    vector<char>::iterator start, end, it;
    int final_fichero=0;
    cin >> ntest;
    cin.get(temp);
    
    for(i=0;i<ntest;i++)
    {
        vector<char> v;
        
        temp=0;
        while(temp!='\n')
        {
            if(!cin.get(temp))
                        break;
            
            if(temp!='\n')
            {
                v.push_back(temp);
            }    
        }
        
        start = v.begin();
        end = v.end();
        sort(start,end);

        do {
                for(it=v.begin();it!=v.end();it++) 
                                cout << *it ;
                cout << endl;
        } while(next_permutation(start, end));

        cout << endl;
    }    

return 0;
    
}


