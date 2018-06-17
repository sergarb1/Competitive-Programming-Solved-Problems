#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <iostream>
using namespace std;

int main()
{
    double h,m,hAngle,mAngle,angle;
    
    /*#ifndef ONLINE_JUDGE
        close (0); 
        open (".in", O_RDONLY);
        close (1); 
        open (".out", O_WRONLY | O_CREAT, 0600);
    #endif
    */
    
    while(1)
    {
        char temp;
        scanf("%lf:%lf",&h,&m);
        
        if(h==0.0 && m==0.0)
                return 0;
        
        hAngle=h*30+(m/2); // OJO TENER EN CUENTA QUE LA MANECILLA DE LA HORA 
                               //SE MUEVE CUANDO PASAN MINUTOS AUNQUE SEA LA MISMA HORA        
        mAngle=m*6; 
        angle=hAngle-mAngle;
        if(angle<0)
                angle*=-1;
        
        if(angle>180)
                angle=360-angle;
        
        printf("%.3lf\n",angle);             
    }
    
    
    return 0;
}
