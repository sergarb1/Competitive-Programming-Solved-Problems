#include <iostream>

using namespace std;

long long int tamX,tamY;

char pintura[1022][1022];

int nInstru=0;

int instru[1022*1022];
int instruA[1022*1022];
int instruB[1022*1022];
int instruC[1022*1022];
int instruD[1022*1022];

int BnInstru=0;

int Binstru[1022*1022];
int BinstruA[1022*1022];
int BinstruB[1022*1022];
int BinstruC[1022*1022];
int BinstruD[1022*1022];



// Procesa lineas Y
void procesar()
{
	int i,j,k;
	int R1,R2,C1,C2;
	nInstru=0;
	
	for(i=0;i<tamX;i++)
	{
		R1=i;
		R2=R1;
		for(j=0;j<tamY;j++)
		{
			if(pintura[i][j]=='#')
			{
				C1=j;
				C2=C1;
				for(k=j+1;k<tamY;k++)
				{
					if(pintura[i][k]=='.')
					{
						break;
					}

					C2=k;
				}
				instru[nInstru]=1;
				instruA[nInstru]=R1;
				instruB[nInstru]=C1;
				instruC[nInstru]=R2;
				instruD[nInstru]=C2;
				nInstru++;
				
				j=k;
			}			
		}
	}
}
// Procesa lineas X
void procesarB()
{
	int i,j,k;
	int R1,R2,C1,C2;
	BnInstru=0;
	
	for(i=0;i<tamY;i++)
	{
		C1=i;
		C2=C1;
		for(j=0;j<tamX;j++)
		{
			if(pintura[j][i]=='#')
			{
				R1=j;
				R2=R1;
				for(k=j+1;k<tamX;k++)
				{
					if(pintura[i][k]=='.')
					{
						break;
					}

					R2=k;
				}
				Binstru[BnInstru]=1;
				BinstruA[BnInstru]=R1;
				BinstruB[BnInstru]=C1;
				BinstruC[BnInstru]=R2;
				BinstruD[BnInstru]=C2;
				BnInstru++;
				
				j=k;
			}			
		}
	}
}


void imprimeInstrucciones()
{
	int i;


	if(nInstru<BnInstru)
	{


		cout << nInstru << endl;
		for(i=0;i<nInstru;i++)
		{
			if(instru[i]==1)
			{
				cout << "PAINT_LINE "<<instruA[i]<<" " <<instruB[i]<<" "<<instruC[i]<<" "<<instruD[i]<<endl;;
			}
		}
	}
	else
	{

		cout << BnInstru << endl;
		for(i=0;i<BnInstru;i++)
		{
			if(Binstru[i]==1)
			{
				cout << "PAINT_LINE "<<BinstruA[i]<<" " <<BinstruB[i]<<" "<<BinstruC[i]<<" "<<BinstruD[i]<<endl;;
			}
		 }
	}
}



int main()
{
	int i=0;
	cin >> tamX;
	cin >> tamY;
	char tmp[3];
	cin.getline(tmp,3);
	
	while(cin.getline(pintura[i],1001))
	{
		//cout << pintura[i]<< endl;
		i++;	
	}
	

	procesar();
	procesarB();
	
	imprimeInstrucciones();
	return 0;
}

