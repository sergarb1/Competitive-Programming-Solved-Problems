#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdlib.h> 
#include <iostream>

using namespace std; 
char matriz[810];
int main() 
{ 
  int i,j,k;
  int ntest;
  char num[20];
  char num_org[20];
  
  #ifndef ONLINE_JUDGE 
          //close (0); open (".in", O_RDONLY); 
          //close (1); open (".out", O_WRONLY | O_CREAT, 0600); 
  #endif 
  char tmp;
  cin >> ntest;
  cin.get(tmp);
  for(i=1;i<=ntest;i++)
  {
      cin.getline(num,20);
      strcpy(num_org,num);
      int tam=strlen(num);
      
      for(j=0;j<819;j++)
            matriz[j]=0;
      while(1)
      {
            long long int res=0;
            tam=strlen(num);
            for(j=0;j<tam;j++)
            {
                      res+=(num[j]-'0')*(num[j]-'0');
            }    
            if(res==1)
            {
                cout << "Case #"<<i<<": "<<num_org<<" is a Happy number." << endl;
                break;
            }
            if(matriz[res]==1)
            {
                cout << "Case #"<<i<<": "<<num_org<<" is an Unhappy number."<< endl;
                break;
            }    
            matriz[res]=1;
            sprintf(num,"%lld",res);
      }    
            
  }    
  return 0;
}
