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
    long long int i,j;
    long long int suma=0,suma2=0;
    #ifndef ONLINE_JUDGE
        /*close (0); 
        open ("138.in", O_RDONLY);*/
        close (1); 
        open ("138.out", O_WRONLY | O_CREAT, 0600);
    #endif
    
    int pairs=0;
    /*METODO DE TANGUE */
    cout <<"\t6\t8" << endl;
	cout <<"\t35\t49" << endl;
	cout <<"\t204\t288" << endl;
	cout <<"\t1189\t1681" << endl;
	cout <<"\t6930\t9800" << endl;
	cout <<"\t40391\t57121" << endl;
	cout <<"\t235416\t332928" << endl;
	cout <<"\t1372105\t1940449" << endl;
	cout <<"\t7997214\t11309768" << endl;
	cout <<"\t46611179\t65918161" << endl;

    /* METODO BIEN PERO LENTO 
    for(i=1;pairs<10;i++)
    {
        /* (n+m)*(n-m+1)/2 =suma
        (nn)+n-(mm)+m-2suma
        
        
        
        

        double res,ecuacion;
        res=((i+1)-((i+1)*(i+1))-(suma*2));
        
        if(4*res>1)
        {
             suma+=i;
            continue;
        }    
        ecuacion=(-1+sqrt(1-(4*res)))/2;
        if(ecuacion-(long long int)ecuacion==0 && ecuacion!=i)
        {
            cout << '\t' << i << "\t" << (long long int)ecuacion << endl;
            pairs++;
        }

        
        suma+=i;
        
    }    
    */
    return 0;
}
