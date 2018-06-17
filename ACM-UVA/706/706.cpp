#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <iostream>
using namespace std;

    
void imprime_numero(int numero,int linea);


int amplitud,tam;
char numeros[15];
int main()
{
    
    int i,j,k;
    
    #ifndef ONLINE_JUDGE
        close (0); 
        open ("706.in", O_RDONLY);
        close (1); 
        open ("706.out", O_WRONLY | O_CREAT, 0600);
    #endif
    
    
    while(cin >> amplitud)
    {
        cin >> numeros;
        if(amplitud==0 && numeros[0]=='0')
                return 0;
        tam=strlen(numeros);
        
        for(i=0;i<((amplitud*2)+3);i++)
        {
            for(j=0;j<tam;j++)
            {
                imprime_numero(numeros[j]-'0',i); 
                if(j<tam-1)
                    cout << ' ';
            }  
            cout << endl; 
        } 
        cout << endl;   
    }    
    
    return 0;
}




void imprime_numero(int numero,int linea)
{
     int k;
     int enmedio=((amplitud*2)+2)/2;
     
     char c_lado_i,c_lado_d,c_dentro;
     
     if(linea==0 )
     {
         if(numero==1 || numero==4)
         {
             c_lado_i=' ';
             c_lado_d=' ';
             c_dentro=' ';
         }    
         else
         {
             c_lado_i=' ';
             c_dentro='-';
             c_lado_d=' ';
         }    
     }
     else if(linea==(amplitud*2)+2)
     {
         if(numero==1 || numero==4 || numero==7)
         {
             c_lado_i=' ';
             c_lado_d=' ';
             c_dentro=' ';
         }    
         else
         {
             c_lado_i=' ';
             c_dentro='-';
             c_lado_d=' ';
         }
     }    
     else if(linea<enmedio)
     {
         if(numero==1 || numero==2 ||numero==3 ||numero==7)
         {
             c_lado_i=' ';
             c_lado_d='|';
             c_dentro=' ';
         }    
         else if(numero==5 || numero==6)
         {
             c_lado_i='|';
             c_lado_d=' ';
             c_dentro=' ';
         }    
         else
         { 
             c_lado_i='|';
             c_lado_d='|';
             c_dentro=' ';
         }    
     }
     else if(linea==enmedio)
     {
         if(numero==1 || numero==7 || numero==0)
         {
             c_lado_i=' ';
             c_lado_d=' ';
             c_dentro=' ';
         }        
         else
         {
             c_lado_i=' ';
             c_lado_d=' ';
             c_dentro='-';
         
         }    
     
     }   
     else if(linea>enmedio)
     {
         if(numero==2)
         {   
             c_lado_i='|';
             c_lado_d=' ';
             c_dentro=' ';
         }    
         else if(numero==6 || numero==8 || numero==0)
         {
             c_lado_i='|';
             c_lado_d='|';
             c_dentro=' ';
         }
         else
         {
             
             c_lado_i=' ';
             c_lado_d='|';
             c_dentro=' ';
         }        
     }            
     
     
     cout << c_lado_i;
     for(k=0;k<amplitud;k++)
     {
           cout << c_dentro;
     }    
     cout << c_lado_d;    
} 


