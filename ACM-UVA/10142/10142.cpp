#include<iostream>
#include<sstream>
#include<string.h>
#include<stdio.h>

using namespace std;

int main()
{
	int votos[25];
	int eliminado[25];
	char nombre[25][90];
	int papeletas[1500][25];

	int i,j;
	int ntest;
	int ncand;
	char temp;
	char linea[2000];
	cin >>  ntest;

	for(int x=0;x<ntest;x++)
	{
		cin >> ncand;
		cin.get(temp);
		for(i=0;i<ncand;i++)
		{
			votos[i]=0;
			eliminado[i]=0;
			cin.getline(nombre[i],87);
			//cout << "El nombre es " << nombre[i] <<endl;
		}
	
		cin.getline(linea,1990);
		//cout <<"linea es esto : "<< linea << endl;
		int npapel=0;
		do
		{
			//cout << "Papeleta : " ;
			int avance=0;
			istringstream n(linea);
			for(i=0;i<ncand;i++)
			{
				n >> papeletas[npapel][i];
				//cout << papeletas[npapel][i]<< " ";
			}
			//cout << endl;
			npapel++;
			cin.getline(linea,1990);
			//cout <<"linea es esto : "<< linea << endl;
		}while(strcmp("",linea)!=0);
		
		int ganador=-1;
		while(ganador==-1)
		{
			int nvo=0;
			for(i=0;i<ncand;i++)
			{
				votos[i]=0;
			}

			for(i=0;i<npapel;i++)
			{
				for(j=0;j<ncand;j++)
				{
					if(!eliminado[papeletas[i][j]-1])
					{
						votos[papeletas[i][j]-1]++;
						nvo++;
						//cout << "Le sumo voto a "<<papeletas[i][j]-1<<endl;
						break;
					}
				}
			}
			int menor=10000;
			int mayor=-110000;
			//cout << "Total de votos "<<nvo <<endl;
			for(i=0;i<ncand && ganador==-1;i++)
			{
				double res=(votos[i]*100)/nvo;
				//cout << " Votos de " << i << " " <<res <<endl;
				if(!eliminado[i] && votos[i]<menor)
				{
					menor=votos[i];
				}
				if(!eliminado[i] && votos[i]>mayor)
				{
					mayor=votos[i];
				}
				if(!eliminado[i] && res>50.0)
				{
					ganador=i;
				}
			}
			if(ganador==-1)
			{
				if(menor!=mayor)
				{
					for(i=0;i<ncand;i++)
					{
						if(votos[i]==menor)
							eliminado[i]=1;
					}
				}
				else
				{	
					for(i=0;i<ncand;i++)
					{
						if(!eliminado[i])
							cout << nombre[i] << endl;
					}
					ganador=0;
					
				}
			}
			else
			{
				cout << nombre[ganador] << endl;
		
			}

			
		}
		if(x+1<ntest)
			cout << endl;
	}
	
	return 0;
}
