#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdlib.h> 
#include <iostream>

using namespace std; 

struct p
{
       int orden;
       char palabra[20];
}palabras[200];


int ordena_palabras(const void *a,const void *b)
{
    char *x=(char *)a;
    char *y=(char *)b;
    return strcmp(x,y);
}

int ordena_caracteres(const void *a,const void *b)
{
    char x=*(char *)a;
    char y=*(char *)b;
    return x-y;
}


char normales[200][20];

int main() 
{ 
  int i,j,k;

  #ifndef ONLINE_JUDGE 
          close (0); open ("642.in", O_RDONLY); 
          close (1); open ("642.out", O_WRONLY | O_CREAT, 0600); 
  #endif 
  char linea[20];
  int tam=0;
  while(cin.getline(linea,15,'\n'))
  {
      if(strcmp(linea,"XXXXXX")==0)
           break;
      strcpy(normales[tam++],linea);
  }
  
  qsort(normales,tam,sizeof(normales[0]),ordena_palabras);
  
  for(j=0;j<tam;j++)
  {
       strcpy(palabras[j].palabra,normales[j]);
       palabras[j].orden=j;
       qsort(palabras[j].palabra,strlen(palabras[j].palabra),sizeof(char),ordena_caracteres);
  }
  while(cin.getline(linea,15,'\n'))
  {
      if(strcmp(linea,"XXXXXX")==0)
           break;
      
       qsort(linea,strlen(linea),sizeof(char),ordena_caracteres);
       int encontrado=0;
       for(j=0;j<tam;j++)
       {
             if(strcmp(palabras[j].palabra,linea)==0)
             {
                 cout << normales[j]<<endl;
                 encontrado=1;
             }
       }
       if(encontrado==0)
       {
           cout << "NOT A VALID WORD" << endl;
       }
       cout << "******"<<endl;
  }
  
  
  
  return 0;
}
