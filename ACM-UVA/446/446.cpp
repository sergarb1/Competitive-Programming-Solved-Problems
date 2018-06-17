#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdlib.h> 
#include <iostream>

using namespace std; 

void pasar_a_binario(unsigned int n,char c[])
{
     char tmp[1000];
     int npos=0;
     while(n>=1)
     {
                if(n%2==0)
                {
                    n=n/2;
                    tmp[npos++]='0';
                }
                else
                {
                    n=n/2;
                    tmp[npos++]='1';
                }
                if(n==1)
                {
                    tmp[npos++]='1'; 
                    break;
                }
     }
     tmp[npos]=0;
     int i;
     for(i=0;i<13-(npos);i++)
     {
         c[i]='0';
     }
     for(i=13-npos;i<13;i++)
     {
          c[i]=tmp[npos-1];
          npos--;
     }
     c[i]=0;
     //printf("%s\n",&c);
}

int main() 
{ 
  int i,j,k;

  #ifndef ONLINE_JUDGE 
          close (0); open ("446.in", O_RDONLY); 
          close (1); open ("446.out", O_WRONLY | O_CREAT, 0600); 
  #endif 
  char cada[1000];
  char cadb[1000];
  unsigned int a,b,n;
  scanf("%d\n",&n);
  for(i=0;i<n;i++)
  {
            scanf("%x ",&a);
            
            char c;
            do{
                 scanf("%c",&c);
            }while(c!='+' && c!='-');
            scanf("%x\n",&b);
            pasar_a_binario(a,cada);
            pasar_a_binario(b,cadb);
            if(c=='+')
            {
                      printf("%s + %s = %d\n",cada,cadb,a+b);
            }
            else if(c=='-')
            {
                      printf("%s - %s = %d\n",cada,cadb,a-b);
            }
  }
  return 0;
}
