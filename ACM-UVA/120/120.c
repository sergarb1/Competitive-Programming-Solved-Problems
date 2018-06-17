#include <stdio.h>
#define MAXPANCAKES 30
#define SIZE 2000

int pan[MAXPANCAKES] ;
int size = 6;

void flip(int n) {
	int i,j=size, tmp;
	/* n=size-n;
	
	for (i = n;i>n/2; i--) {
		tmp = pan[i];
		pan[i] = pan[n-i];
		pan[n-i] = tmp;
	}*/
	j--;
	
	for(i=n;i<j;i++,j--)
	{
		tmp=pan[i];
		pan[i]=pan[j];
		pan[j]=tmp;
	}
	
	
}

void p() { 
	int i;
	//printf("[");
	for (i = 0; i < size; i++) {
		printf("%d ", pan[i]);
	}
	printf("\n");
}

int main() {
	int i, max, s;
	char c;

	
	
	while (!feof(stdin)) {
		i = 0;
		while (1) {
			scanf("%d", &pan[i]);
			i++;
			scanf("%c", &c);
			if (c == '\n')
				break;
			if(feof(stdin)) 
				break;
		}

		size = i;
		p();
		flip(0);
		
		s = 0;
		while (s < size) {
			max = s;
			for (i = s; i < size; i++)
			{
				if (pan[i] > pan[max])
					max = i;
			}
			//printf("el maximo es: %d y s es : %d \n", pan[max],s);
			if(max != s)
			{		
				if (max+1 != size) {
					//printf("hago el flip %d \n", max+1);
					flip(max);
					printf("%d ", max+1);
				}
				
				//printf("hago el flip %d \n",s+1);
				flip(s);	
				printf("%d ", s+1);
			}
			//p();
			s++;
			
			
		}
		
		printf("0\n");
	}
	
	
}

