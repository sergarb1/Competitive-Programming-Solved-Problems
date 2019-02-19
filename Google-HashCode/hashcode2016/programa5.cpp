#include <iostream>
#include <cmath>
#include <time.h>
#include <stdlib.h>

using namespace std;

long long int tamX;
long long int tamY;
long long int drones;
long long int aDrones[1011];
long long int D;
long long int maxLoad;



long long int P;

long long int arrayP[10055];
long long int W;

long long int arrayWR[10055];
long long int arrayWC[10055];



long long int aWP[10055][10055];

long long int C;

long long int arrayCR[10055];
long long int arrayCC[10055];

long long int arrayCL[10055];
long long int aCL[10055][10055];


long long int nIns=0;
long long int insDrone[100000];
char insComando[100000];
long long int insPos[100000];
long long int insTipo[100000];
long long int insCant[100000];



int buscaCliente(int tPro)
{
	int i,j;
	
	for(i=0;i<C;i++)
	{
		if(aCL[i][tPro]>0)
		{
			
			return i;
		}
	}

	return -1;
}


void procesa()
{
	int i,j;
	int drone=0;
	// Solo primer almacen
	for(i=0;i<W;i++)
	{
		//cout << "Proceso W " << W << endl;
		for(j=P-1;j>=0;j--)
		{
	
			//cout << "Proceso producto " << j << endl;
		//	if(aWP[i][j]>0 && arrayP[j]<maxLoad)
		//	{
				int res=buscaCliente(j);
				if(res!=-1)
				{
					// Carga
				
						long long int maxCargaPD=maxLoad/arrayP[j];
						long long int cuantos=aCL[res][j];
						long long int cuantosW=aWP[i][j];
						
						long long int carga=cuantos;
						if (maxCargaPD<carga)
						{
							carga=maxCargaPD;
						}
						if (cuantosW<carga)
						{
							carga=cuantosW;
						}
						
						aCL[res][j]-=carga;
						
						if(carga==0)
						{
							continue;
						}
						
						//int mig_dr=rand()%drones;
						insDrone[nIns]=drone;

						
						insComando[nIns]='L';
						insPos[nIns]=i;
						insTipo[nIns]=j;
						insCant[nIns]=carga;
						nIns++;
				
					
					// Descarga
					insDrone[nIns]=drone;
					insComando[nIns]='D';
					insPos[nIns]=res;
					insTipo[nIns]=j;
					insCant[nIns]=carga;
					nIns++;


					drone++;

					if(drone==drones)
					{
						drone=0;
					}

					
					

				}
		//	}
		}
	}
	
}


void petarTiempo()
{
	int i,j,k;
	long long int dX,dY;
	long long int desX,desY;

	long long int tiempo=0,tmp;
	

	dX=arrayWC[0];
	dY=arrayWR[0];




	for(i=0;i<nIns;i++)
	{
		tmp=0;
		// Por la carga
		tmp++;
		
		if(insComando[i]=='L')
		{
			desX=arrayWC[insPos[i]];
			desY=arrayWR[insPos[i]];
		}
		if(insComando[i]=='D')
		{
			desX=arrayCC[insPos[i]];
			desY=arrayCR[insPos[i]];
		}

		double Result=0.0;
	        Result += pow(desX-dX, 2); 
                Result += pow(desY-dY, 2); 
                Result = ceil(sqrt(Result));
		
		tmp=tmp+(int)Result;
		
		tiempo+=tmp;
		
		if(tiempo>D)
		{
			nIns=i-1;
			return;
		}
		dX=desX;
		dY=desY;
		
		
				

		
		
	}


}


void reorganizar()
{
}


void imprime()
{
	int i;
	
	cout << nIns << endl;

	for(i=0;i<nIns;i++)
	{
		
		cout << insDrone[i]<<" " << insComando[i]<<" " << insPos[i]<<" " << insTipo[i]<<" "<< insCant[i]<<endl; 
		
		
	}

}



int main()
{
	int i,j;
	cin >> tamX;
	cin >> tamY;
	cin >> drones;
	cin >> D;
	cin >> maxLoad;

//cout << "Tamanyo "<<tamX << " " << tamY << " ndrones"<< drones << " Deadline "<<D<< " maxima carga " <<maxLoad<<endl;

	cin >> P;


	


//	cout << "P "  << P << endl;
	// Productos

	for(i=0;i<P;i++)
	{
		cin >> arrayP[i];
		//cout << arrayP[i]<<endl;
	}
	//cout << "------------------------------------" <<endl;
	
	// Warehouse
	cin >> W;

	//cout << "W "  << W << endl;
	

	for(i=0;i<W;i++)
	{
		cin >> arrayWR[i];
		cin >> arrayWC[i];

		//cout <<" X Y " <<arrayWR[i]<< " " <<arrayWC[i] <<endl;
		for(j=0;j<P;j++)
		{
			cin >> aWP[i][j];
			//cout << aWP[i][j] << endl;
		}
	}


//	cout << "------------------------------------" <<endl;

	// Orders


	cin >> C;

//	cout << "C "  << C << endl;
	

	for(i=0;i<C;i++)
	{
		cin >> arrayCR[i];
		cin >> arrayCC[i];
		cin >> arrayCL[i];

//		cout << " X Y L "<<arrayCR[i] << " " <<arrayCC[i]<< " " <<  arrayCL[i] << endl;
		for(j=0;j<P;j++)
		{
			aCL[i][j]=0;
		}
		for(j=0;j<arrayCL[i];j++)
		{
			long long int tipo;
			cin >> tipo;
			aCL[i][tipo]++;
			//cout << "Del tipo " << tipo << " hay " <<aCL[i][tipo]<< " productos" << endl;
		}
	}





	procesa();
	reorganizar();
	petarTiempo();
	imprime();







	return 0;
}
