#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdlib.h> 
#include <iostream>

using namespace std;

struct maja{
    int x;
    int y;
}willy[100000];  

int sentido=0; // 0 bajar  1 subir
int nbajar,nsubir,nizq_b,nizq_a,nder_a,nder_b;

void calcular()
{
    int i=0,j=0,k=0;
    int xp,yp,pos;
    sentido=0;
    nsubir=3;
    nbajar=1;
    nder_a=1;
    nizq_a=1;
    nder_b=0;
    nizq_b=0;
    willy[0].x=0;
    willy[0].y=0;
    pos=1;
    while(1)
    {
        j=nizq_b;
        k=nder_b;
        for(i=0;i<nbajar;i++)
        {
            xp=willy[pos-1].x;
            yp=willy[pos-1].y;
            if(j>i)
            {
                 xp++;
                 yp--;     
            }
            if(nbajar-k<=i)
            {
                 xp--;
            }
            yp++;
            willy[pos].x=xp;
            willy[pos].y=yp;
            
            
            pos++;
            if(pos==100000)
                return;
        }    
        nbajar+=3;
        nizq_b++;
        nder_b++;
        
        
        
        j=nizq_a;
        k=nder_a;
        for(i=0;i<nsubir;i++)
        {
            xp=willy[pos-1].x;
            yp=willy[pos-1].y;
            if(j>i)
            {
                 xp--;  
                 yp++;  
            }
            if(nsubir-k<=i)
            {
                 xp++;
                     
            }
            yp--;
            willy[pos].x=xp;
            willy[pos].y=yp;
            pos++;
            
            if(pos==100000)
                return;
        }    
        nsubir+=3;
        nder_a++;
        nizq_a++;
        
    }    
  
}    

int main() 
{ 
  int i,j,k;
  int numero;

  
  
    calcular();
    
    while(cin>>numero)
    {
        cout << willy[numero-1].x << " " << willy[numero-1].y << endl;
    }    
  
  
  return 0;
}
