#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdlib.h> 
#include <iostream>

using namespace std; 

char ficheros[200][180];

int ordenar(const void *a,const void *b)
{
    char *x=(char *)a;
    char *y=(char *)b;
    return strcmp(x,y);
}

int main() 
{ 
  int i,j,k;

  #ifndef ONLINE_JUDGE 
          close (0); open ("400.in", O_RDONLY); 
          close (1); open ("400.out", O_WRONLY | O_CREAT, 0600); 
  #endif 
  int n;
  while(cin >> n)
  {
            int tam=0,tammax=0;
            char tmp;
            int ncol=0;
            
            cin.get(tmp);
            for(i=0;i<n;i++)
            {
                            cin.getline(ficheros[i],80,'\n');
                            tam=strlen(ficheros[i]);
                            if(tam>tammax)
                                 tammax=tam; 
            }
            int tamcol=60-tammax;
            while(tamcol>=0)
            {
                 ncol++;
                 tamcol-=(tammax+2);
            }
            
            qsort(ficheros,n,sizeof(ficheros[0]),ordenar);
            int filxcol;
            if(n%ncol==0)
            {
                 filxcol=n/ncol;
            }
            else
            {
                 filxcol=(n/ncol)+1;
            }
            
            
            printf("------------------------------------------------------------\n");
            
            for(i=0;i<filxcol;i++)
            {
                 int salto=0;
                 for(j=0;j<ncol;j++)
                 {
                      if(j==ncol-1)
                      {
                          if(((filxcol)*j)+i<n)
                          {
                              tam=0;
                              tam=strlen(ficheros[(filxcol*j)+i]);
                              printf("%s",ficheros[(filxcol*j)+i]);
                              for(k=tam+((tammax)*(ncol-1))+(2*(ncol-1));k<60;k++)
                              {
                                   printf(" ");
                              }
                              salto=1;
                              printf("\n");
                          }
                      }
                      else
                      {    
                          if(((filxcol)*j)+i<n)
                          {
                              tam=strlen(ficheros[(filxcol*j)+i]);
                              printf("%s",ficheros[(filxcol*j)+i]);
                              for(k=tam;k<tammax+2;k++)
                              {
                                   printf(" ");
                              }
                          }
                      }
                 }
                 if(salto==0)
                 {
                             printf("\n");
                 }
            }
            
  }
  return 0;
}
