#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdlib.h> 
#include <iostream>

using namespace std; 

  char res[1002][30];
  char pabs[1002][30];
  char pabsord[1002][30];
  int esanagrama[1002];
  
  int ordena(const void *a,const void *b)
  {
      char x=*((char *)a);
      char y=*((char *)b);
      return x-y;
  } 
  int ordena_todo(const void *a,const void *b)
  {
      char *x=(char *)a;
      char *y=(char *)b;
      return strcmp(x,y);
  }
  
  
int main() 
{ 
  int i,j,k;
  char linea[90];
  #ifndef ONLINE_JUDGE 
          close (0); open ("156.in", O_RDONLY); 
          close (1); open ("156.out", O_WRONLY | O_CREAT, 0600); 
  #endif
  int npab=0; 
  while(cin.getline(linea,85))
  {
      int tam;
      int enpalabra;
      int posact;
      if(linea[0]=='#')
             break;
      tam=strlen(linea);
      enpalabra=0;
      posact=0;
      for(i=0;i<tam;i++)
      {
          if(linea[i]==' ' || linea[i]=='\n')
          {
              if(enpalabra==1)
              {
                  char pabtmp[30];
                  char pabtmp2[30];
                  strcpy(pabtmp,pabs[npab]);
                  pabs[npab][posact]=0;
                  pabsord[npab][posact]=0;
                  
                  
                  esanagrama[npab]=0;
                  qsort(pabsord[npab],posact,sizeof(pabsord[0][0]),ordena);
                  //cout << pabs[npab] << " " <<pabsord[npab]<< endl;
                  for(j=0;j<npab;j++)
                  {
                     strcpy(pabtmp2,pabs[j]);
                     if(strcmp(pabsord[j],pabsord[npab])==0)
                     {
                         esanagrama[npab]=1;
                         esanagrama[j]=1;
                         break;
                     }
                  }
                  npab++;
                  enpalabra=0;
                  posact=0;
                  
              }
              if(linea[i]=='\n')          
                    break;
          }
          else
          {
              enpalabra=1;
              pabs[npab][posact]=linea[i];
              if(linea[i]<97)
                           pabsord[npab][posact++]=linea[i]+32;
              else
                           pabsord[npab][posact++]=linea[i];
          }
          
      }
      if(enpalabra==1)
      {
                  char pabtmp[30];
                  char pabtmp2[30];
                  strcpy(pabtmp,pabs[npab]);
                  pabs[npab][posact]=0;
                  pabsord[npab][posact]=0;
                  
                  
                  esanagrama[npab]=0;
                  qsort(pabsord[npab],posact,sizeof(pabsord[0][0]),ordena);
                  //cout << pabs[npab] << " " <<pabsord[npab]<< endl;
                  for(j=0;j<npab;j++)
                  {
                     strcpy(pabtmp2,pabs[j]);
                     if(strcmp(pabsord[j],pabsord[npab])==0)
                     {
                         esanagrama[npab]=1;
                         esanagrama[j]=1;
                         break;
                     }
                  }
                  npab++;
                  enpalabra=0;
                  posact=0;
                  
      }
      
          
  }
  int num=0;
  for(i=0;i<npab;i++)
  {
      if(esanagrama[i]==0)
      {
          strcpy(res[num++],pabs[i]);
      }
  }
  qsort(res,num,sizeof(res[0]),ordena_todo);
  for(i=0;i<num;i++)
  {
      cout << res[i]<< endl;
  }
  return 0;
}
