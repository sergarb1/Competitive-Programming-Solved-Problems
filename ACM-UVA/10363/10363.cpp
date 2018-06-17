#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

#include <iostream>
using namespace std;


int es_valido();

void tic_tac();

char partida[3][4];

int gana_c=0,gana_x=0;
int num_c=0,num_x=0;	

    int vic_x[3][3];
    
int main()
{

    
    int i,j,k;
    int n_casos;
    
 

    #ifndef ONLINE_JUDGE
        close (0); 
        open ("10363.in", O_RDONLY);
        close (1); 
        open ("10363.out", O_WRONLY | O_CREAT, 0600);
    #endif
    
    scanf("%d",&n_casos);
    
    for(i=0;i<n_casos;i++)
    {
    	for(j=0;j<3;j++)
	{
		scanf("%s",partida[j]);
	}
	
	gana_c=0,gana_x=0;
	num_c=0,num_x=0;
	
	if(es_valido())
		printf("yes\n");
	else
		printf("no\n");
    	
    }
    
    return 0;
    
}


int es_valido()
{

	int i,j;
	gana_c=0,gana_x=0;
	num_c=0,num_x=0;
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			vic_x[i][j]=0;
		}
	}
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(partida[i][j]=='X')
			{
				num_x++;
			}
			else if(partida[i][j]=='O')
			{
				num_c++;
			}
		}
	}
	
	if(num_c>num_x || (num_x-num_c>=2))
		return 0;
		
	
	tic_tac();
	if(gana_c>=1 && gana_x>=1)
		return 0;
		
	else if(gana_c>1 )
		return 0;
	else if(gana_c==1 && gana_x==0 && num_c==num_x)
		return 1;
	else if(gana_c==0 && gana_x==1 && num_c<num_x)
		return 1;
	else if(gana_x==2 )
	{
		if(num_c>=num_x)
			return 0;
			
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				if((vic_x[i][j]/2) == gana_x)
					return 1;
			}
		}
		return 0;
	}
		
	return 0;
}

void tic_tac()
{

	int i,j;
	char temp;
	/* primera, de 0,0 a 2,0 */
	temp=partida[0][0];
	if(partida[1][0]==temp && partida[2][0]==temp)
	{
		if(temp=='0')
		{
			gana_c++;	
		}
		else
		{
			gana_x++;
			vic_x[0][0]++;
			vic_x[2][0]++;
		}	
	}
	
	
	/* segunda, de 0,0 a 0,2 */
	temp=partida[0][0];
	if(partida[0][1]==temp && partida[0][2]==temp)
	{
		
		if(temp=='0')
		{
			gana_c++;
			
		}
		else
		{
			gana_x++;
			vic_x[0][0]++;
			vic_x[0][2]++;
		}	
			
	}
	
	/* tercera, de 0,0 a 2,2 */
	temp=partida[0][0];
	if(partida[1][1]==temp && partida[2][2]==temp)
	{
		
		if(temp=='0')
		{
			gana_c++;
		}
		else
		{
			gana_x++;
			vic_x[0][0]++;
			vic_x[2][2]++;
		}	
	}
	
	/* cuarta, de 0,2 a 2,0 */
	temp=partida[0][2];
	if(partida[1][1]==temp && partida[2][0]==temp)
	{
		if(temp=='0')
		{
			gana_c++;	
		}
		else
		{
			gana_x++;
			vic_x[0][2]++;
			vic_x[2][0]++;
		}	
	}
	
	/* quinta, de 0,2 a 2,2 */
	temp=partida[0][2];
	if(partida[1][2]==temp && partida[2][2]==temp)
	{
		if(temp=='0')
		{
			gana_c++;
		}
		else
		{
			gana_x++;
			vic_x[0][2]++;
			vic_x[2][2]++;
		}	
	}
	
	/* sexta, de 2,0 a 2,2 */
	temp=partida[2][0];
	if(partida[2][1]==temp && partida[2][2]==temp)
	{
		if(temp=='0')
		{
			gana_c++;	
		}
		else
		{
			gana_x++;
			vic_x[2][0]++;
			vic_x[2][2]++;
		}	
	}
	/* septima, de 1,0 a 1,2 */
	temp=partida[1][0];
	if(partida[1][1]==temp && partida[1][2]==temp)
	{
		if(temp=='0')
		{
			gana_c++;	
		}
		else
		{
			gana_x++;
			vic_x[1][0]++;
			vic_x[1][2]++;
		}	
	}
	/* octava, de 0,1 a 2,1 */
	temp=partida[0][1];
	if(partida[1][1]==temp && partida[2][1]==temp)
	{
		if(temp=='0')
		{
			gana_c++;
		}
		else
		{
			gana_x++;
			vic_x[0][1]++;
			vic_x[2][1]++;
		}	
	}

	
}
