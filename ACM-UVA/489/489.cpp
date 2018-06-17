#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdlib.h> 
#include <iostream>

using namespace std; 

char hash[256];
char solucion[10000];
char intentos[10000];

int main() 
{ 
  int i,j,k;

  #ifndef ONLINE_JUDGE 
          close (0); open ("489.in", O_RDONLY); 
          close (1); open ("489.out", O_WRONLY | O_CREAT, 0600); 
  #endif 
  
  int ronda;
  
  while(cin >> ronda)
  {
            char tmp;
            cin.get(tmp);
            if(ronda==-1)
                         return 0;
                         
            for(i='a';i<='z';i++)
            {
                 hash[i]=0;
            }
            
            int nletras=0;
            int tamsol,tamint;
            int nfallos=0;
            cin.getline(solucion,9900);
            cin.getline(intentos,9900);
            tamsol=strlen(solucion);
            tamint=strlen(intentos);
            for(i=0;i<tamsol;i++)
            {
                 if(hash[solucion[i]]==0)
                 {
                       nletras++;
                       hash[solucion[i]]=1;
                 }
            }
            for(i=0;i<tamint && nfallos <7;i++)
            {
                 if(hash[intentos[i]]==0)
                 {
                     nfallos++;
                 }
                 else if(hash[intentos[i]]==1)
                 {
                      nletras--;
                      hash[intentos[i]]=2;
                 }
            }
            cout << "Round "<<ronda << endl;
            if(nletras==0)
            {
                cout << "You win." << endl;
            }
            else if(nfallos>=7)
            {
                cout << "You lose." << endl;
            }
            else
            {
                cout << "You chickened out." << endl;
            }
  }
  
  return 0;
}
