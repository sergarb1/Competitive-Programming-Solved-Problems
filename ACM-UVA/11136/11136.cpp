#include <stdio.h>

int cuentas[1000001];

int main()
{
	int i,j,k;
	int ndias;
	while(scanf("%d",&ndias)==1)
	{
		long long int gasto=0;
		if(ndias==0)
			return 0;
		for(i=0;i<=1000000;i++)
		{
			cuentas[i]=0;
		}
		for(i=0;i<ndias;i++)
		{
			int ncuentas;
			scanf("%d",&ncuentas);
			for(j=0;j<ncuentas;j++)
			{	
				int tmp;
				scanf("%d",&tmp);
				cuentas[tmp]++;
			}
			int mayor=0,menor=0;
			for(j=1000000;j>=0;j--)
			{
				if(cuentas[j]>0)
				{
					mayor=j;
					cuentas[j]--;
					break;
				}
			}
			for(j=0;j<=1000000;j++)
			{
				if(cuentas[j]>0)
				{
					menor=j;
					cuentas[j]--;
					break;
				}
			}
			gasto+=(mayor-menor);
		}
		printf("%lld\n",gasto);
	}
}
