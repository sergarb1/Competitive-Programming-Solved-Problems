#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdlib.h> 
#include <iostream>

using namespace std; 

struct tareas
{
       int orden;
       int tiempo;
       int compensacion;
}
t[1002];

// Coste: Lo que tarda en hacerse una tarea, mas lo que tarda la otra mas el ratio coste/dias
// Como es coste el mismo (suma de las tareas) solo comparamos los ratios
int ordenar(const void *a,const void *b)
{
    struct tareas x=*(struct tareas*)a;
    struct tareas y=*(struct tareas*)b;
    // costeA/diasA>costeB/diasB equivale a costeA*diasB>costeB*diasA
    int peso_x=x.compensacion*y.tiempo;
    int peso_y=y.compensacion*x.tiempo;
    return peso_y-peso_x;
}
int main() 
{ 
  int i,j,k;

  
  int ntest;
  
  cin >> ntest;
  
  for(i=0;i<ntest;i++)
  {
          if(i>0)
                 cout << endl;
          int ntareas;
          cin >> ntareas;
          for(j=0;j<ntareas;j++)
          {
              t[j].orden=j;
              cin >> t[j].tiempo >> t[j].compensacion;
          }
          qsort(t,ntareas,sizeof(t[0]),ordenar);
          for(j=0;j<ntareas;j++)
          {
               if(j>0)
                  cout << " ";
               cout << (t[j].orden+1);
          }
          cout << endl;
          
  }
  
  return 0;
}
