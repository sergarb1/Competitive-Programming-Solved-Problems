#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_CADENA 2000000

int main()
{
    char cadena[MAX_CADENA];
    int i,tam;
    #ifndef ONLINE_JUDGE
        close (0); 
        open ("458.in", O_RDONLY);
        close (1); 
        open ("458.out", O_WRONLY | O_CREAT, 0600);
    #endif
    while(!feof(stdin))
    {
        fgets(cadena,MAX_CADENA,stdin);
        tam=strlen(cadena);
        if(feof(stdin))
            return 0;
        for(i=0;i<tam;i++)
        {
            if(cadena[i]!='\n')
                printf("%c",cadena[i]-7);
            else
                printf("%c",cadena[i]);
        }
    }       
    
    
    
    return 0;
}
