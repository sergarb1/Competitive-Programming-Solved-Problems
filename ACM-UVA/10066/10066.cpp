#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdlib.h> 
#include <iostream>

using namespace std; 


#define MAX 110

int N1,N2;

int X[MAX],Y[MAX];
int i,j,m,n,c[MAX][MAX],b[MAX][MAX];
int LCSlength();
int main() 
{ 
  int i,j,k;

  #ifndef ONLINE_JUDGE 
          close (0); open ("10066.in", O_RDONLY); 
          close (1); open ("10066.out", O_WRONLY | O_CREAT, 0600); 
  #endif 
  int ncaso=1;
  while(cin >> N1)
  {
            cin >> N2;
            if(N1==0 && N2==0)
                     return 0;
            for(i=0;i<N1;i++)
            {
                cin >> X[i];
            }
            for(i=0;i<N2;i++)
            {
                cin >> Y[i];
            }
            int res=LCSlength();
            //if(ncaso!=1)
            //            cout << endl;
            cout << "Twin Towers #"<<ncaso++<< endl;
            cout << "Number of Tiles : "<<res<< endl<<endl;
  }
  return 0;
}




int LCSlength() {
  m=N1;
  n=N2;

  for (i=1;i<=m;i++) c[i][0]=0;
  for (j=0;j<=n;j++) c[0][j]=0;

  for (i=1;i<=m;i++)
    for (j=1;j<=n;j++) {
      if (X[i-1]==Y[j-1]) {
        c[i][j]=c[i-1][j-1]+1;
        b[i][j]=1; /* from north west */
      }
      else if (c[i-1][j]>=c[i][j-1]) {
        c[i][j]=c[i-1][j];
        b[i][j]=2; /* from north */
      }
      else {
        c[i][j]=c[i][j-1];
        b[i][j]=3; /* from west */
      } 
    }

  return c[m][n];
}
