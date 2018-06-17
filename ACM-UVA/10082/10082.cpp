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
    
    inicializa_tabla();   
    
    while(cin.get(c))
    {
        if(c=='\n' || c==' ')
        {
            cout << c;
        }    
        else
        {
            cout << tabla[c];
        }    
    }    
    
    
    return 0;
}

void inicializa_tabla()
{
    tabla['1']='`';
    tabla['2']='1';
    tabla['3']='2';
    tabla['4']='3';
    tabla['5']='4';
    tabla['6']='5';
    tabla['7']='6';
    tabla['8']='7';
    tabla['9']='8';
    tabla['0']='9';
    tabla['-']='0';
    tabla['=']='-';
    tabla['W']='Q';
    tabla['E']='W';
    tabla['R']='E';
    tabla['T']='R';
    tabla['Y']='T';
    tabla['U']='Y';
    tabla['I']='U';
    tabla['O']='I';
    tabla['P']='O';
    tabla['[']='P';
    tabla[']']='[';
    tabla['\\']=']';
    tabla['S']='A';
    tabla['D']='S';
    tabla['F']='D';
    tabla['G']='F';
    tabla['H']='G';
    tabla['J']='H';
    tabla['K']='J';
    tabla['L']='K';
    tabla[';']='L';
    tabla['\'']=';';
    tabla['X']='Z';
    tabla['C']='X';
    tabla['V']='C';
    tabla['B']='V';
    tabla['N']='B';
    tabla['M']='N';
    tabla[',']='M';
    tabla['.']=',';
    tabla['/']='.';
    
}    
