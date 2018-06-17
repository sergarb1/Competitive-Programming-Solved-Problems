#include <iostream>
using namespace std;

#define N 9
#define K 65
#define MAXCAND 30
int tablero[N][K];
int datos[9][17];
int num_sol,lon;

void muestra(){
	for(int i=0;i<lon;i++){
		for(int j=0;j<lon;j++)
			cout<<tablero[i][j]<<" ";
		cout<<endl;
	}
	
}
void coloca_alfil(int f, int c){
	tablero[f][c]=-1;
	
	int i, j;
	
	i=f+1;j=c+1;	
	while(i<lon && j<lon ){
		tablero[i][j]++;
		i++;j++;
	}
	
	i=f+1;j=c-1;	
	while(i<lon && j>=0 ){
		tablero[i][j]++;
		i++;j--;
	}
	
	i=f-1;j=c+1;
	while(i>=0 && j<lon){
		tablero[i][j]++;
		i--;j++;
	}
	i=f-1;j=c-1;
	while(i>=0 && j>=0){
		tablero[i][j]++;
		i--;j--;
	}
}

void quita_alfil(int f, int c){
	tablero[f][c]=0;
	
	int i, j;
	
	i=f+1;j=c+1;	
	while(i<lon && j<lon ){
		tablero[i][j]--;
		i++;j++;
	}
	
	i=f+1;j=c-1;	
	while(i<lon && j>=0 ){
		tablero[i][j]--;
		i++;j--;
	}
	
	i=f-1;j=c+1;
	while(i>=0 && j<lon){
		tablero[i][j]--;
		i--;j++;
	}
	i=f-1;j=c-1;
	while(i>=0 && j>=0){
		tablero[i][j]--;
		i--;j--;
	}
}

void backtrack(int k, int i, int j){
	
	if(k==0){
		num_sol++;
		return;
	}

	if(i==lon)
		return;
	
	if(j==lon){
		backtrack(k,i+1,0);
		return;
	}
	
	if(tablero[i][j]==0){
		coloca_alfil(i,j);
// 		muestra();
// 		int pause;
// 		cin>>pause;
		backtrack(k-1,i,j+1);
		
		quita_alfil(i,j);
// 		muestra();
// 		cin>>pause;
		
	}
	backtrack(k,i,j+1);
}

int main(){
		
	for(int n=1;n<N;n++){
		for(int k=0;k<K;k++){
			if(k>=2*n){
				datos[n][k]=0;
				break;
			}
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					tablero[i][j]=0;
			lon=n;
			num_sol=0;
			backtrack(k,0,0);
			
			datos[n][k]=num_sol;
			cout<<"datos["<<n<<"]["<<k<<"]= "<<datos[n][k]<<endl;
		}
	}
	return 0;
}
