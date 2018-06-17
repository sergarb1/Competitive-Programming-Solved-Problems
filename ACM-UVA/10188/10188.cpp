#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <ctype.h>
#include <stdlib.h> 
#include <iostream>

using namespace std; 

char s[100][122];
char ns[100002];
char r[100][122];
char nr[100002];


int aceptado(int ns,int nr)
{
    if(ns!=nr)
              return 0;
              
    for(int i=0;i<ns;i++)
    {
            if(strcmp(s[i],r[i])!=0)
               return 0;
    }
    return 1;
}

int presentationerror()
{
    if(strcmp(ns,nr)!=0)
               return 0;
    return 1;
}

int main() 
{ 
  int i,j,k;

  
  int nlinsol,nlinres;
  
  int nrun=0;
  while(cin >> nlinsol)
  {
            
            int posnr=0,posns=0;
            char tmp[122];
            cin.getline(tmp,120);
            nrun++;
            if(nlinsol==0)
                 return 0;
            for(i=0;i<nlinsol;i++)
            {
             //   cin.getline(s[i],120);
                cin.getline(tmp,120);
                strcpy(s[i],tmp);
                int tam=strlen(s[i]);
                for(j=0;j<tam;j++)
                {
                    if(s[i][j]>='0' && s[i][j]<='9')
                    {
                        ns[posns++]=s[i][j];
                    }
                }    
                
            }
            
            cin >> nlinres;
            cin.getline(tmp,120);
            for(i=0;i<nlinres;i++)
            {
                //cin.getline(r[i],120);
                cin.getline(tmp,120);
                strcpy(r[i],tmp);
                
                int tam=strlen(r[i]);
                for(j=0;j<tam;j++)
                {
                    if(r[i][j]>='0' && r[i][j]<='9')
                    {
                        nr[posnr++]=r[i][j];
                    }
                }    
            }
            
            ns[posns]=0;
            nr[posnr]=0;
            
            /** Accepted **/
            if(aceptado(nlinsol,nlinres))
            {
                 cout << "Run #"<<nrun<<": Accepted" << endl;
            }
            /** Presentation error **/
            else if(presentationerror())
            {
                 cout << "Run #"<<nrun<<": Presentation Error" << endl;
            }
            /** Wrong answer **/
            else
            {
                cout << "Run #"<<nrun<<": Wrong Answer" << endl;
            }
  }
  
  return 0;
}
