

#include <iostream>
using namespace std;

#define OVER 6227020800LL
#define UNDER 10000

int main()
{
    long long int i,j;
    long long int fact;
    long long int num;
    int d_over=0;
    #ifndef ONLINE_JUDGE
        close (0); 
        open ("10323.in", O_RDONLY);
        close (1); 
        open ("10323.out", O_WRONLY | O_CREAT, 0600);
    #endif
    while(cin >> num)
    {
        fact=1;
        d_over=0;
        if(num<0)
        {
            if(num%2!=0)
            {
                cout << "Overflow!" << endl;
            }    
            else
                cout << "Underflow!" << endl;
            continue;
        }    
        for(i=1;i<=num;i++)
        {
            fact=i*fact;
            if(fact>OVER)
            {
                d_over=1;
                break;
            }    
        }    
        if(d_over==1)
        {
                cout << "Overflow!" << endl;
        }    
        else
        {
            if(fact<UNDER)
            {
                cout << "Underflow!" << endl;
            }    
            else
            {
                cout << fact << endl;
            }    
        }    
    }    
    
    return 0;
}


