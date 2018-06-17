/*   @JUDGE_ID:   32131ZP   136   C   "Dynamic Programming"   */ 

#include <stdio.h>

#define MAX_UGLYS 1500
void main()
{
    int uglys[MAX_UGLYS];
    int ultimo_ugly_o2=0;
    int ultimo_ugly_o3=0;
    int ultimo_ugly_o5=0;
    int i=0;
    uglys[0]=1;
    int uglys_actual=1;
    
    int operacion2,operacion3,operacion5;
    
    operacion2=uglys[ultimo_ugly_o2]*2;
    operacion3=uglys[ultimo_ugly_o3]*3;
    operacion5=uglys[ultimo_ugly_o5]*5;
    
    while(uglys_actual<1500)
    {
        if(operacion2<operacion3)
        {
            if(operacion2<operacion5)
            {
                //operacion2 es menor
                for(i=0;i<uglys_actual;i++)
                {
                    if(uglys[i]==operacion2)
                            break;
                }    
                if(i==uglys_actual)
                {
                    uglys[uglys_actual]=operacion2;
                    uglys_actual++;
                }
                ultimo_ugly_o2++;
                operacion2=uglys[ultimo_ugly_o2]*2;
                
            }
            else
            {
                //operacion5 es menor
                for(i=0;i<uglys_actual;i++)
                {
                    if(uglys[i]==operacion5)
                            break;
                }    
                if(i==uglys_actual)
                {
                    uglys[uglys_actual]=operacion5;
                    uglys_actual++;
                }
                ultimo_ugly_o5++;
                operacion5=uglys[ultimo_ugly_o5]*5;
            }        
        }    
        else if(operacion3<operacion5)
        {
            //operacion3 es menor
            for(i=0;i<uglys_actual;i++)
                {
                    if(uglys[i]==operacion3)
                            break;
                }    
                if(i==uglys_actual)
                {
                    uglys[uglys_actual]=operacion3;
                    uglys_actual++;
                }
                ultimo_ugly_o3++;
                operacion3=uglys[ultimo_ugly_o3]*3;
        }
        else
        {
            //operacion5 es menor
                for(i=0;i<uglys_actual;i++)
                {
                    if(uglys[i]==operacion5)
                            break;
                }    
                if(i==uglys_actual)
                {
                    uglys[uglys_actual]=operacion5;
                    uglys_actual++;
                }    
                ultimo_ugly_o5++;
                operacion5=uglys[ultimo_ugly_o5]*5;
                
        }        
        
            
    }    
  
    printf("The 1500'th ugly number is %d.\n",uglys[MAX_UGLYS-1]);   

}

