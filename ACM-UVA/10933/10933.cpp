#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

#define MAXN 21

struct equipo
{
	char nombre[MAXN];
	int vic;
	int der;
	int pf;
	int pc;
	int sf;
	int sc;

}equipos[1000];

char etemp[MAXN];
int neq,npart;

int num_eq(char *eq)
{
	int i;
	for(i=0;i<neq;i++)
	{
		if(strcmp(equipos[i].nombre,eq)==0)
		{
			return i;
		}
	}
	return -1;
}

int compara(const void *a,const void *b)
{
	struct equipo x=*(struct equipo *)a;
	struct equipo y=*(struct equipo *)b;
	
	if(x.vic>y.vic)
	{
		return -1;
	}
	else if(y.vic>x.vic)
	{
		return 1;
	}

	if((x.sf-x.sc)>(y.sf-y.sc))
	{
		return -1;
	}
	else if((x.sf-x.sc)<(y.sf-y.sc))
	{
		return 1;
	}


	if((x.pf)>(y.pf))
	{
		return -1;
	}
	else if((x.pf)<(y.pf))
	{
		return 1;
	}

	return strcmp(x.nombre,y.nombre);

}

int main()
{
	int i,j,k;
	#ifndef ONLINE_JUDGE
  		close (0); open ("10933.in", O_RDONLY);
//  		close (1); open ("10933.out", O_WRONLY | O_CREAT, 0600);
	#endif 
	char tmp;

	while(cin >> neq)
	{	
		cin.get(tmp);
		if(neq==0)
			return 0;
		for(i=0;i<neq;i++)
		{
			cin.getline(equipos[i].nombre,MAXN,'\n');
			//printf("Equipo leido %s\n",equipos[i].nombre);
			equipos[i].vic=0;
			equipos[i].der=0;
			equipos[i].pf=0;
			equipos[i].pc=0;
			equipos[i].sf=0;
			equipos[i].sc=0;

		}
		cin >> npart;
		cin.get(tmp);
		//printf("Numero de partidos %d\n",npart);
		for(i=0;i<npart;i++)
		{
			int eq1,eq2,s1=0,s2=0;
			cin.getline(etemp,MAXN,'-');
			//printf("eq1:%s\n",etemp);
			eq1=num_eq(etemp);
			cin.getline(etemp,MAXN,':');
			cin.get(tmp);
			//printf("eq1:%s\n",etemp);
			eq2=num_eq(etemp);	
			//printf("partido 1 entre %d y %d\n",eq1,eq2);
			while(s1<3 && s2<3)
			{
				int p1,p2;
				cin >> p1;
				cin.get(tmp);
				//printf("%c\n",tmp);
				cin >> p2;
				cin.get(tmp);
				//printf("%c\n",tmp);
				
				equipos[eq1].pf+=p1;
				equipos[eq2].pf+=p2;
				equipos[eq1].pc+=p2;
				equipos[eq2].pc+=p1;
				//printf("eq %d pf %d pc%d\n",eq1,equipos[eq1].pf,equipos[eq1].pc);
				//printf("eq %d pf %d pc%d\n",eq2,equipos[eq2].pf,equipos[eq2].pc);

				if(p1>p2)
				{
					s1++;
				}
				else
				{
					s2++;
				}
			}	
			equipos[eq1].sf+=s1;
			equipos[eq1].sc+=s2;
			equipos[eq2].sf+=s2;
			equipos[eq2].sc+=s1;
			if(s1==3)
			{
				equipos[eq1].vic++;
				equipos[eq2].der++;
			}
			else
			{
				equipos[eq2].vic++;
				equipos[eq1].der++;
			}
		}		
		qsort(equipos,neq,sizeof(equipos[0]),compara);

		for(i=0;i<neq;i++)
		{
			int tam=20-strlen(equipos[i].nombre);
			
			printf("%s",equipos[i].nombre);
			for(j=0;j<tam;j++)
				printf(" ");
			printf("%5d%5d%10d\n",equipos[i].vic,(equipos[i].sf-equipos[i].sc),(equipos[i].pf));
			//printf("Set a favor %d set en contra %d\n",equipos[i].sf,equipos[i].sc);
		}
		cin.getline(etemp,MAXN,'\n');

	}

	return 0;
}
