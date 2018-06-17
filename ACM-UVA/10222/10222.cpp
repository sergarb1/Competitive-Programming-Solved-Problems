#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <iostream>
using namespace std;

char tabla[256];

void inicializa_tabla();


int main()
{
    char c;
    
    #ifndef ONLINE_JUDGE
        close (0); 
        open ("10222.in", O_RDONLY);
        close (1); 
        open ("10222.out", O_WRONLY | O_CREAT, 0600);
    #endif
    inicializa_tabla();   
    
    while(cin.get(c))
    {
        if(c>='a' && c<='z')
                c=(char)(c-32);
        if(c=='\n' || c==' ')
        {
            cout << c;
        }    
        else
        {
            if(tabla[c]>='A' && tabla[c]<='Z')
                        cout << (char)(tabla[c]+32);
            else
                        cout << tabla[c];
        }    
    }    
    
    
    return 0;
}

void inicializa_tabla()
{
    tabla['2']='`';
    tabla['3']='1';
    tabla['4']='2';
    tabla['5']='3';
    tabla['6']='4';
    tabla['7']='5';
    tabla['8']='6';
    tabla['9']='7';
    tabla['0']='8';
    tabla['-']='9';
    tabla['=']='0';
    tabla['E']='Q';
    tabla['R']='W';
    tabla['T']='E';
    tabla['Y']='R';
    tabla['U']='T';
    tabla['I']='Y';
    tabla['O']='U';
    tabla['P']='I';
    tabla['[']='O';
    tabla[']']='P';
    tabla['\\']='[';
    tabla['D']='A';
    tabla['F']='S';
    tabla['G']='D';
    tabla['H']='F';
    tabla['J']='G';
    tabla['K']='H';
    tabla['L']='J';
    tabla[';']='K';
    tabla['\'']='L';
    tabla['C']='Z';
    tabla['V']='X';
    tabla['B']='C';
    tabla['N']='V';
    tabla['M']='B';
    tabla[',']='N';
    tabla['.']='M';
    tabla['/']=',';
    
    
    
    
}    
