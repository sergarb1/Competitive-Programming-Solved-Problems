#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdlib.h> 
#include <iostream>

using namespace std; 



// Dimensiones de los puntos con los que trabajaremos
#define DIMENSION 2 

// Definicion de X e Y para puntos de dos dimensicones
#define X 0
#define Y 1

//Tamaño maximo en puntos de un poligono
#define MAXPOLY 10000


// Definicion de punto de varias dimensiones
typedef long long int point[DIMENSION];

typedef struct 
{
        int n; // Numero de puntos del poligono
        point p[MAXPOLY];
}
polygon;

  
long long int absolute(long long int a)
{
     if(a<0)
            a*=-1;
     return a;
}


long long int gcd(long long int  a, long long int  b) {

  return !b ? a : gcd(b,a%b);

}




// Area de un poligono
long long int area(polygon *p)
{
       long long int total=0; // area total hasta el momento
       int i,j; // Contadores
       for(i=0;i<p->n;i++)
       {
            j=(i+1)%p->n;
            total+=(p->p[i][X]*p->p[j][Y])-(p->p[j][X]*p->p[i][Y]);
       }
       return absolute((long long int)total/2);
}




long long int point_in_frontier(point a,point b)
{
     long long int dx,dy,min,max;
     long long int res;
     dx=absolute(a[X]-b[X]);
     dy=absolute(a[Y]-b[Y]);

     res=gcd(dx,dy);
     return res;
}


int main() 
{ 
  int i,j,k;
  int n;
  polygon p;

  
  while(cin >> n)
  {
            if(n==0)
                return 0;
            p.n=n;
            for(i=0;i<n;i++)
            {
                 cin >> p.p[i][X] >> p.p[i][Y];
            }
            long long int areapol=area(&p);
            long long int pfront=0;
   
            for(i=0;i<n-1;i++)
            {
                 pfront+=point_in_frontier(p.p[i],p.p[i+1]);
            }
            
            pfront+=point_in_frontier(p.p[n-1],p.p[0]);

            long long int pint=areapol-(pfront/2)+1;
            cout << pint << endl;
  }
  return 0;
}
