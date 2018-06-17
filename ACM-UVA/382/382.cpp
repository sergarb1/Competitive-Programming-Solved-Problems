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
    int i,j;
    int numero,num_temp,mayor,limite;
    
    #ifndef ONLINE_JUDGE
        close (0); 
        open ("382.in", O_RDONLY);
        close (1); 
        open ("382.out", O_WRONLY | O_CREAT, 0600);
    #endif
    
    cout << "PERFECTION OUTPUT" << endl;
            
    
    while(cin >> numero)
    {
        num_temp=0;
        mayor=0;
        if(numero==0)
        {
            cout << "END OF OUTPUT" << endl;
            return 0;
        }
        limite=(int)(numero/2);
        for(i=1;i<=limite && mayor==0;i++)
        {
            if(numero%i==0)
            {
                num_temp+=i;
                if(num_temp>numero)
                {
                    mayor=1;
                    cout << '\t' << numero << '\t' << "ABUNDANT" << endl;
              
                }    
            }    
        }   
             
        if(mayor==0)
        {
                if(num_temp==numero)
                {
                    cout << '\t' << numero << '\t' << "PERFECT" << endl;
                }   
                else
                {
                    cout << '\t' << numero << '\t' << "DEFICIENT" << endl;
                }         
        }    
    }    
    
    return 0;
}
