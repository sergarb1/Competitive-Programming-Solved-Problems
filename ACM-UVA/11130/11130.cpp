#include <iostream>
#include <cmath>

using namespace std;
const float PI = 2*acos(0.0);

int main()
{
	double horizontal,vertical,velocidad,angulo,tiempo;

	while(cin >> horizontal >> vertical >> velocidad >> angulo >> tiempo)
	{
		if(horizontal==0.00)
			return 0;
		double aceleracion=-velocidad/tiempo;
		double recorrido_t=velocidad*tiempo+0.5*aceleracion*tiempo*tiempo;
		double recorrido_v=sin(angulo*PI/180)*recorrido_t;
		double recorrido_h=cos(angulo*PI/180)*recorrido_t;
		int resh=0,resv=0;
		recorrido_h-=horizontal/2;
		if(recorrido_h>=0.0)
		{
			resh=1;
			resh+=(int)(recorrido_h/horizontal);
		}
		recorrido_v-=vertical/2;
		if(recorrido_v>=0.0)
		{
			resv=1;
			resv+=(int)(recorrido_v/vertical);
		}
		cout << resh << " " << resv<<endl;

	}
	
}
