#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdlib.h> 
#include <iostream>

using namespace std; 
int pila[1000];
int pos_pila=0;
int conf[1000];
int pos_conf=0;

int tam;
int es_posible()
{
    int i;
    pos_pila=0;
    pos_conf=0;
    for(i=1;i<=tam;i++)
    {
        while(pos_pila>0 && pila[pos_pila-1]==conf[pos_conf])
        {
            pos_pila--;
            pos_conf++;
        }
        if(conf[pos_conf]==i)
        {
            pos_conf++;
        }    
        else
        {
            pila[pos_pila++]=i;    
        }    
            
    }
     while(pos_pila>0 && pila[pos_pila-1]==conf[pos_conf])
     {
            pos_pila--;
            pos_conf++;
     }
    if(pos_conf==tam)    
        return 1;
    
    else
        return 0;
}    

int main() 
{ 
  int i,j,k;
  #ifndef ONLINE_JUDGE 
          close (0); open ("514.in", O_RDONLY); 
          close (1); open ("514.out", O_WRONLY | O_CREAT, 0600); 
  #endif
  cin >> tam;
  while(1)
  {
      if(tam==0)
            return 0;
      while(1)
      {
          cin >> conf[0];
          if(conf[0]==0)
          {
                cin >> tam;
                cout << endl;
                if(tam==0)
                      return 0;
                break;
          }     
          for(i=1;i<tam;i++)
          {
              cin >> conf[i];
          }    
          if(es_posible())
          {
              cout << "Yes" << endl;
          }    
          else
          {
              cout << "No" << endl;
          }    
      }    
  }    
  return 0;
}
