#include <iostream>

using namespace std;


int diaPruebas[1001];
int periodoPruebas[1001];
int nPruebas;



int calcular(){
	int ultDia=diaPruebas[0];
	
	int i,j;

	for(i=1;i<nPruebas;i++){
		//cout << "Ultdia "<<ultDia<<endl;
		int ini,rep;

		ini=diaPruebas[i];
		rep=periodoPruebas[i];

		while(ini<=ultDia)
			ini=ini+rep;

		ultDia=ini;
	}


	return ultDia;
}


int main(){
	
	int res;
	cin >> nPruebas;


	for(int i=0;i<nPruebas;i++){

		cin >>diaPruebas[i];
		cin >>periodoPruebas[i];


	}

	res=calcular();
	cout << res << endl;
	

	return 0;
}
