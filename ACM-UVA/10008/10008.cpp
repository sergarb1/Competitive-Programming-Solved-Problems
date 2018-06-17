#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <iostream>
using namespace std;


    struct hash{
        char caracter;
        long long int repeticiones;
    }thash[257];
    

int compara(const void *a,const void *b);

int main()
{
    int i,j,k;
    
    char c;
    
    #ifndef ONLINE_JUDGE
        close (0); 
        open ("10008.in", O_RDONLY);
        close (1); 
        open ("10008.out", O_WRONLY | O_CREAT, 0600);
    #endif
    
    int ntest,tam;
    
    cin >> ntest;
    for(i=0;i<256;i++)
    {
        thash[i].caracter=0;
        thash[i].repeticiones=0;
    }    
    while(cin.get(c))
    {
        
            if(c>=65 && c<=90)
            {
                thash[c].repeticiones++;
                thash[c].caracter=c;
            }
            else if(c>=97 && c<=122)
            {   
                thash[c-32].repeticiones++;
                thash[c-32].caracter=c-32;
            }        
          
        
    }   
     
    qsort(thash,256,sizeof(thash[0]),compara);
    for(i=0;i<256;i++)
    {
        if(thash[i].caracter>=65 && thash[i].caracter<=90)
        {
            cout <<thash[i].caracter<< " " << thash[i].repeticiones << endl;
        }    
    }    
    return 0;
}

int compara(const void *a,const void *b)
{
    int res=(((struct hash *)b)->repeticiones) - (((struct hash *)a)->repeticiones);
    if(res==0)
    {
        return (((struct hash *)a)->caracter) - (((struct hash *)b)->caracter);
    }
    else 
        return res;    
    
}    
