#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>


#include <iostream>
using namespace std;

double absoluto(double x)
{
    if(x<0)
        x*=-1;
    return x;
}    
double dist(double ax,double ay,double bx,double by)
{
    return (pow(ax-bx,2.0))+(pow(ay-by,2.0));
}    
#define INFINITO -1.0/0.0

int main()
{
    struct h
    {
        double x;
        double y;
    }hoyos[1000];
    double px,py,gx,gy,distp,distg;
    double mayordist=INFINITO;
    int i,j,k,menor;
    int nhoyos;
    
    while(cin >>nhoyos)
    {
        menor=-1;
        mayordist=INFINITO;
        cin >> gx >> gy >> px >> py;
        for(i=0;i<nhoyos;i++)
        {
            cin >> hoyos[i].x >> hoyos[i].y;
            distp=absoluto(dist(px,py,hoyos[i].x,hoyos[i].y));
            distg=absoluto(dist(gx,gy,hoyos[i].x,hoyos[i].y));
            if((distp) >=distg*4)
            {
                if((distp-(distg*4))>mayordist)
                {
                    mayordist=distp-(distg*4);
                    menor=i;
                }    
            }    
        }    
        if(menor==-1)
        {
            //cout << "The gopher cannot escape." << endl;
            printf("The gopher cannot escape.\n");
        }    
        else
        {
            //cout.precision(3);
            //cout << "The gopher can escape through the hole at (" << hoyos[menor].x<<"," << hoyos[menor].y<<")." << endl;
            printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n",hoyos[menor].x,hoyos[menor].y); 
                    
        }    
        
    }    
    
    
    return 0;
}
