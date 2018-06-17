#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdlib.h> 
#include <iostream>

using namespace std; 

int main() 
{ 
  int i,j;
  int k,m,c,r;
  int cursos[110];
  int marcado[110];
  int nccat;
  
  #ifndef ONLINE_JUDGE 
          close (0); open ("10919.in", O_RDONLY); 
          close (1); open ("10919.out", O_WRONLY | O_CREAT, 0600); 
  #endif 
  
  while(cin >> k)
  {
       if(k==0)
               return 0;
       cin >> m;
       for(i=0;i<k;i++)
       {
           cin >> cursos[i];
           marcado[i]=0;
       }
       int essol=1;
       for(int x=0;x<m;x++)
       {
            cin >> c;
            cin >> r;
            for(i=0;i<c;i++)
            {
                cin >> nccat;
                for(j=0;j<k && r>0 && essol==1;j++)
                {
                   if(cursos[j]==nccat && marcado[j]==0 )
                   {
                      r--;
                      marcado[j]=1;
                   }
                }
            }
            if(r>0)
               essol=0;
            
            for(i=0;i<k;i++)
            {
               marcado[i]=0;
            }
       }
       if(essol==1)
       {
           cout << "yes" << endl;
       }
       else
       {
           cout << "no" << endl;
       }
       
  }
  
  return 0;
}
