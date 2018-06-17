#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdlib.h> 
#include <iostream>

using namespace std; 


int reg[10];
char ram[1000][4];


int interpreta()
{
     
     
     int terminado=0;
     int ninstrucciones=0;
     int palabra=0;
     
     int hay_goto=0;
     
     while(!terminado && palabra<1000 && palabra>=0)
     {
        if(ram[palabra][0]=='1')
        {
           terminado=1;
        }
        else if(ram[palabra][0]=='2')
        {
             int nreg=ram[palabra][1]-'0';
             int nvalor=ram[palabra][2]-'0';
             reg[nreg]=nvalor;
        }
        else if(ram[palabra][0]=='3')
        {
             
             int nreg=ram[palabra][1]-'0';
             int nvalor=ram[palabra][2]-'0';
             reg[nreg]=(reg[nreg]+nvalor)%1000;
        }
        else if(ram[palabra][0]=='4')
        {
             
             int nreg=ram[palabra][1]-'0';
             int nvalor=ram[palabra][2]-'0';
             reg[nreg]=(reg[nreg]*nvalor)%1000;
        }
        else if(ram[palabra][0]=='5')
        {
             
             int nreg=ram[palabra][1]-'0';
             int nreg2=ram[palabra][2]-'0';
             reg[nreg]=(reg[nreg2])%1000;
        }
        else if(ram[palabra][0]=='6')
        {
             
             int nreg=ram[palabra][1]-'0';
             int nreg2=ram[palabra][2]-'0';
             reg[nreg]=(reg[nreg]+reg[nreg2])%1000;
        }
        else if(ram[palabra][0]=='7')
        {
             
             int nreg=ram[palabra][1]-'0';
             int nreg2=ram[palabra][2]-'0';
             reg[nreg]=(reg[nreg]*reg[nreg2])%1000;
        }
        else if(ram[palabra][0]=='8')
        {
             
             int nreg=ram[palabra][1]-'0';
             int nreg2=ram[palabra][2]-'0';
             int res=0;
             res=100*(ram[reg[nreg2]][0]-'0');
             res=10*(ram[reg[nreg2]][1]-'0');
             res=1*(ram[reg[nreg2]][2]-'0');
             reg[nreg]=res%1000;
        }
        else if(ram[palabra][0]=='9')
        {
             
             int nreg=ram[palabra][1]-'0';
             int nreg2=ram[palabra][2]-'0';
             char rtmp[4];
             
             itoa(reg[nreg],rtmp,10);
             //sprintf(rtmp,"%d",reg[nreg]);
             if(strlen(rtmp)==3)
             {
             
                  ram[nreg2][0]=rtmp[0];
                  ram[nreg2][1]=rtmp[1];
                  ram[nreg2][2]=rtmp[2];
             }
             else if (strlen(rtmp)==2)
             {
                  
                  ram[nreg2][0]='0';
                  
                  ram[nreg2][1]=rtmp[0];
                  ram[nreg2][2]=rtmp[1];
             }
             else if (strlen(rtmp)==1)
             {
                  ram[nreg2][0]='0';
                  ram[nreg2][1]='0';
                  ram[nreg2][2]=rtmp[0];
             }
             else if (strlen(rtmp)==0)
             {
                  ram[nreg2][0]='0';
                  ram[nreg2][1]='0';
                  ram[nreg2][2]='0';
             }
        }
        else if(ram[palabra][0]=='0')
        {
             
             int nreg=ram[palabra][1]-'0';
             int nreg2=ram[palabra][2]-'0';
             if(nreg2!=0)
             {
                 hay_goto=1;
                 palabra=reg[nreg]%1000;
             }
        }
        ninstrucciones++;
        if(hay_goto)
        {
            hay_goto=0;
        }
        else
        {
            palabra++;
        }
        
     }
     return ninstrucciones;
}

int main() 
{ 
  int i,j,k;
  int ncasos;
  char temp[4];
  #ifndef ONLINE_JUDGE 
          close (0); open ("10033.in", O_RDONLY); 
          close (1); open ("10033.out", O_WRONLY | O_CREAT, 0600); 
  #endif 
  
  cin >> ncasos;
  for(i=0;i<ncasos;i++)
  {
       for(j=0;j<10;j++)
              reg[j]=0;
       j=0;
       cin >> ram[j];
       while(strcmp(ram[j++],"")!=0)
       {
          cin >> ram[j];
       }        
       strcpy(ram[j-1],"000");
       for(;j<1000;j++)
       {

              strcpy(ram[j],"000");  
       }
       int res=interpreta();
       cout << res << endl;
                   
  }
  return 0;
}
