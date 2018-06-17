#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdlib.h> 
#include <iostream>

using namespace std; 

// Error EPSILON
#define EPSILON 0.000001
// Dimensiones de los puntos con los que trabajaremos
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


typedef struct 
{
        point p1;
        point p2;
        point p3;
        double r;
        char tipo;
}figura;


figura f[100];

int rec_dentro(figura ftmp,point ptmp)
{
    if(ftmp.p1[X]<ptmp[X] && ftmp.p2[X]>ptmp[X] && ftmp.p1[Y]>ptmp[Y] && ftmp.p2[Y]<ptmp[Y])
         return 1;
    return 0;                  
}

// Si la distancia entre el punto y el centro, es menor que el radio, esta dentro
int cir_dentro(figura ftmp,point ptmp)
{
    double dis=distance(ftmp.p1,ptmp);
    if(dis<ftmp.r)
                   return 1;
    return 0;
}


// Si esta dentro del triangulo, la suma del area de los triangulos k forma con los otros puntos,
//debe ser igual que el area del triangulo original. Si esta fuera, sera mayor

int tri_dentro(figura ftmp,point ptmp)
{
    double a1,a2,a3,a;
    
    
    a=triangle_area(ftmp.p1,ftmp.p2,ftmp.p3);
    a1=triangle_area(ptmp,ftmp.p2,ftmp.p3);
    a2=triangle_area(ftmp.p1,ptmp,ftmp.p3);
    a3=triangle_area(ftmp.p1,ftmp.p2,ptmp);
    
    if(fabs(a1+a2+a3-a)<=EPSILON)
           return 1;
    
    return 0;
}

int main() 
{ 
  int i,j,k;

  #ifndef ONLINE_JUDGE 
          close (0); open ("477.in", O_RDONLY); 
          close (1); open ("477.out", O_WRONLY | O_CREAT, 0600); 
  #endif 
  char tipo;
  i=0;
  do
  {
          scanf("%c",&tipo);
          //cin.get(tipo);
          if(tipo=='r')
          {       
                  //cin >> f[i].p1[X] >> f[i].p1[Y] >>f[i].p2[X]>>f[i].p2[Y];
                  
                  scanf(" %lf %lf %lf %lf\n",&f[i].p1[X],&f[i].p1[Y],&f[i].p2[X],&f[i].p2[Y]);
                  f[i].tipo=tipo;
                  //cout <<" Leo un rectangulo con puntos " << f[i].p1[X]<<" "<<f[i].p1[Y]<<" " <<f[i].p2[X]<<" " <<f[i].p2[Y]<<endl << endl;
                  i++;
          }
          else if(tipo=='c')
          {
                  //cin >> f[i].p1[X] >> f[i].p1[Y] >> f[i].r;
                  scanf(" %lf %lf %lf\n",&f[i].p1[X],&f[i].p1[Y],&f[i].r);
                  f[i].tipo=tipo; 
                  //printf("Leo un circulo con los puntos %llf %llf %llf\n\n",f[i].p1[X],f[i].p1[Y],f[i].r);
     
                  i++;
          }
          else if(tipo=='t')
          {
                  //cin >> f[i].p1[X] >> f[i].p1[Y] >>f[i].p2[X]>>f[i].p2[Y]>>f[i].p3[X]<<f[i].p3[Y];
                  
                  scanf(" %lf %lf %lf %lf %lf %lf\n",&f[i].p1[X],&f[i].p1[Y],&f[i].p2[X],&f[i].p2[Y],&f[i].p3[X],&f[i].p3[Y]);
                  f[i].tipo=tipo; 
                 
                  i++;
          }
          char tmp;
          //cin.get(tmp);
  }while(tipo!='*');
  
  
  point tmp;
  int npunto=1;
//  while(cin >> tmp[X] >> tmp[Y])
 while(scanf("%lf %lf\n",&tmp[X],&tmp[Y])>0)
  {
         if(tmp[X]==9999.9 && tmp[Y]==9999.9)
                            return 0;
         int encontrado=0;
         for(j=0;j<i;j++)
         {
               if(f[j].tipo=='r')
               {
                   if(rec_dentro(f[j],tmp))
                   {
                       encontrado=1;
                       printf("Point %d is contained in figure %d\n",npunto,j+1);
                   }
               }
               else if(f[j].tipo=='c')
               {
                    
                   if(cir_dentro(f[j],tmp))
                   {
                       encontrado=1;
                       printf("Point %d is contained in figure %d\n",npunto,j+1);
                   }
               }
               else if(f[j].tipo=='t')
               {
                    
                   if(tri_dentro(f[j],tmp))
                   {
                       encontrado=1;
                       printf("Point %d is contained in figure %d\n",npunto,j+1);
                   }
               }
               
         }
         if(encontrado==0)
         {
               printf("Point %d is not contained in any figure\n",npunto);
         }
         npunto++;
  }
  return 0;
}
