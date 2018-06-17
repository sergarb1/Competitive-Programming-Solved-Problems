#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdlib.h> 
#include <iostream>

using namespace std; 

  int vector[2000];
  
            int res=0;
void intercambio_directo(int n)
{
   res=0;
   int i,j,aux;
   i=0;
   j= n-1;
     for(;j>0;j--)
       for(i=0;i<j;i++)                //recorre el arreglo de 0 a n-1
        {
           if (vector[i]>vector[i+1])        //si el elemento actual es mayor que el elemento siguiente
              {
                aux=vector[i];             //intercambio de elementos
                vector[i]=vector[i+1];
                vector[i+1]=aux;
                res++;
              }
        }
}


int main() 
{ 
  int i,j,k;

  #ifndef ONLINE_JUDGE 
         close (0); open ("10327.in", O_RDONLY); 
          close (1); open ("10327.out", O_WRONLY | O_CREAT, 0600); 
  #endif 
  
  int n;
  while(cin >> n)
  {
            int pos,val,aux;
            for(i=0;i<n;i++)
            {
                            cin >> vector[i];
            }
            /* Trolling sort 
            for(i=0;i<n-1;i++)
            {
                pos=-1;
                val=vector[i];
                for(j=i+1;j<n;j++)
                {
                       if(vector[j]<val)
                       {
                           val=vector[j];
                           pos=j;
                       }
                }
                if(pos!=-1)
                {
                           res++;
                           aux=vector[i];
                           vector[i]=vector[pos];
                           vector[pos]=aux;
                }
            }
            */
            intercambio_directo(n);
            
            
            cout << "Minimum exchange operations : "<<res << endl;
            
  }
  return 0;
}
