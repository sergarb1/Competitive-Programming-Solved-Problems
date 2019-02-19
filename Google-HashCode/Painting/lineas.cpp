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


void imprimeInstrucciones()
{
	int i;
	cout << nInstru << endl;
	for(i=0;i<nInstru;i++)
	{
		if(instru[i]==1)
		{
			cout << "PAINT_LINE "<<instruA[i]<<" " <<instruB[i]<<" "<<instruC[i]<<" "<<instruD[i]<<endl;;
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
	
	imprimeInstrucciones();
	return 0;
}

