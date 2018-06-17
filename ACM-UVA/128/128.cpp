#include <stdio.h>
#include <string.h>

#define g 34943


unsigned int calcular_crc(char * msg,int tam);


int main() {
  char line[1029];
  unsigned int blocks, result;

  while(1) {
    fgets(line, 1025, stdin);
    if(!strcmp(line, "#\n") || feof(stdin)) break;
    
    blocks = strlen(line);
    line[blocks-1]=0;
    line[blocks]=0;
    line[blocks+1]=0;


    result = calcular_crc(line, blocks);
    
    printf("%02X %02X\n", result >> 8, result & 0xFF);
  }

  return 0;
}

unsigned int calcular_crc(char * msg,int tam)
{
    char *ptr=msg;
    unsigned int i=0,d=0;
    int tope=tam-(tam%2);
    
    for(i=0;i<tope;i+=2)
    {
        d+=*ptr++;
        d<<=8;
        
        d+=*ptr++;
        d<<=8;
        
        d=d%g;
    }
    
    if(tam%2)
    {
        d+=*ptr++;
        d<<=8;
        d=d%g; 
    }    
        
    if(d)
        return g-d;
    else
       return 0;     
    
}    
