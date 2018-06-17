#include <stdio.h>
#define MAX 81

int size, nline;
int grid[MAX][MAX];


int pos(int n1, int n2)
{
	return (n1-1) * size + (n2-1);
}

int cuadrero(int tam)
{
	int res=0;
	int i, j, k;
	for(i=1; i <= size-tam; i++){
		for(j=1; j <= size-tam; j++){
			for(k=0; k<tam; k++){
				if(grid[pos(i,j+k)][pos(i,j+k+1)]==1 
				&& grid[pos(i+k,j)][pos(i+k+1,j)]==1
				&& grid[pos(i+tam,j+k)][pos(i+tam,j+k+1)]==1 
				&& grid[pos(i+k,j+tam)][pos(i+k+1,j+tam)]==1)
					;
				else
				{
					break;
				}	
			}
			if(k==tam){
				res++;
				//printf("%d %d\n", i, j);
			}
		}
	}
	return res;
}

void p()
{
	int i, j;
	
	for(i = 0; i < size*size; i++){
		for(j = 0; j < size*size; j++){
			printf("%d ", grid[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int i, j, k;
	int nAux1, nAux2,resultado=0,encontrado,caso=0;
	char c;
	
	while (scanf("%d\n%d\n", &size, &nline) == 2){
		for (i = 0; i < size*size; i++)
			for (j = 0; j < size*size; j++)
				grid[i][j] = 0;
	
		if(caso>0)
			printf("\n**********************************\n\n");
		caso++;
		for(i=0; i<nline; i++){
			scanf("%c %d %d\n", &c, &nAux1, &nAux2);
			/* printf("%c %d %d\n", c, nAux1, nAux2);
			/*  */
			if(c == 'H'){
				grid[pos(nAux1, nAux2)][pos(nAux1, nAux2+1)] = 1;			
				grid[pos(nAux1, nAux2+1)][pos(nAux1, nAux2)] = 1;
			}
			else if(c == 'V'){
				grid[pos(nAux2, nAux1)][pos(nAux2+1, nAux1)] = 1;
				grid[pos(nAux2+1, nAux1)][pos(nAux2, nAux1)] = 1;
			}
		}
		//p();
		encontrado=0;
		printf("Problem #%d\n\n",caso);
		
		for(i=1; i<=size; i++){
			resultado=cuadrero(i);
			if(resultado>0)
			{
				encontrado=1;
				printf("%d square (s) of size %d\n",resultado,i);
			}
		}
		if(encontrado==0)
			printf("No completed squares can be found.\n");
		
	}

	return 0;
}
