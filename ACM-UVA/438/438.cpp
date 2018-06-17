#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdlib.h> 
#include <iostream>

using namespace std; 

#define PI 3.141592653589793

#define DIMENSION 2

// Definicion de X e Y para puntos de dos dimensicones
#define X 0
#define Y 1

// Definicion de punto de varias dimensiones
typedef double point[DIMENSION];

//Distancia entre dos puntos
double distance(point a,point b)
{
       int i;
       double d=0.0;
       for(i=0;i<DIMENSION;i++)
       {
            d=d+(a[i]-b[i])*(a[i]-b[i]);
       }       
       return sqrt(d);
}


// Area del triangulo con signo (puede salir negativo)
double signed_triangle_area(point a,point b,point c)
{
       return((a[X]*b[Y] - a[Y]*b[X] + a[Y]*c[X] - a[X]*c[Y] + b[X]*c[Y] - c[X]*b[Y])/2.0);
}

// Area del triangulo
double triangle_area(point a,point b,point c)
{
       return fabs(signed_triangle_area(a,b,c));       
}





int main() 
{ 
  int i,j,k;

  #ifndef ONLINE_JUDGE 
          close (0); open ("438.in", O_RDONLY); 
          close (1); open ("438.out", O_WRONLY | O_CREAT, 0600); 
  #endif 
  point p1,p2,p3;
  while(scanf("%lf %lf %lf %lf %lf %lf",&p1[X],&p1[Y],&p2[X],&p2[Y],&p3[X],&p3[Y])>0)
  {
      
      double a,b,c;
  
      // Obtenemos los lados del triangulo
      a=distance(p1,p2);
      b=distance(p2,p3);
      c=distance(p3,p1);
      double area  = triangle_area(p1,p2,p3);
      double radio = (a*b*c)/(4*area);
      double res=2.0*PI*radio;
      printf("%.2lf\n",res);
  }
  return 0;
}
