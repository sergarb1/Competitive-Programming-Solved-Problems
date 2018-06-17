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
    int i,j,k;
    #ifndef ONLINE_JUDGE
        //close (0);open ("10161.in", O_RDONLY);
        //close (1);open ("10161.out", O_WRONLY | O_CREAT, 0600);
    #endif
    
    int ith;
    int sentido;
    int posx,posy;
    while(cin >> ith)
    {
        if(ith==0)
        {
            return 0;
        }    
        sentido=0;
        for(i=1;((i)*2)-1<ith;i++)
        {
            ith-=(i*2)-1;
            sentido^=1;
        }     
        
        if(sentido==1)       {
                posx=1;
                posy=i;
                if(ith-i>0)
                {
                    ith-=i;
                    posx=i;
                    posy-=ith;
                }
                else
                {
                    posx=ith;    
                }             
        }    
        else
        {       posx=i;
                posy=1;
                
                if(ith-i>0)
                {
                    ith-=i;
                    posy=i;
                    posx-=ith;
                }
                else
                {
                    posy=ith;
                }      
         
        }       
        cout << posx << " " << posy << endl;
        continue; 
          
    }    
    
    
    
    return 0;
}
