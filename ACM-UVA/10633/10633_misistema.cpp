#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#include <iostream>
using namespace std;

void   longlong_2_char(unsigned long long num,char buffer[])
{
       char tmp[1000];
       int i=0,j=0;
       while(num>0)
       {
                   tmp[i++]='0'+num%10;
                   num/=10;
       }
       tmp[i]=0;
       for(j=i-1;j>=0;j--)
       {
           buffer[i-1-j]=tmp[j];
       }
       
       buffer[i]=0;
       
       
}
int main()
{
    unsigned long long numero,num_temp;
    unsigned long long i;
    
    
    #ifndef ONLINE_JUDGE
        close (0); 
        open ("10633.in", O_RDONLY);
        close (1); 
        open ("10633.out", O_WRONLY | O_CREAT, 0600);
    #endif
    char buffer[1000];
    while(cin >> numero)
    {
        int primero=0;
        if(numero==0)
        {
            return 0;
        }    
        
        for(i=1;i<=10;i++)
        {
            num_temp=numero+i;
            longlong_2_char(num_temp,buffer);
           
            if((num_temp-(buffer[0]-'0')) == numero )
            {
               if(primero==0)
               {
                   primero=1;
                   cout << num_temp;
               }
               else
                   cout<< " "<< num_temp;
               
            }
           
        }  
        
               cout << endl;
   
    }    
    return 0;
}
