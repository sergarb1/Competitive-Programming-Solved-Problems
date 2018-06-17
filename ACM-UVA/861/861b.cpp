#include <cstdio>

int datos[10][100];



int main(){
	
	int n,m;
	
	
	datos[1][0]= 1;
	datos[1][1]= 1;
	datos[2][0]= 1;
	datos[2][1]= 4;
	datos[2][2]= 4;
	datos[2][3]= 0;
	datos[3][0]= 1;
	datos[3][1]= 9;
	datos[3][2]= 26;
	datos[3][3]= 26;
	datos[3][4]= 8;
	datos[3][5]= 0;
	datos[4][0]= 1;
	datos[4][1]= 16;
	datos[4][2]= 92;
	datos[4][3]= 232;
	datos[4][4]= 260;
	datos[4][5]= 112;
	datos[4][6]= 16;
	datos[4][7]= 0;
	datos[5][0]= 1;
	datos[5][1]= 25;
	datos[5][2]= 240;
	datos[5][3]= 1124;
	datos[5][4]= 2728;
	datos[5][5]= 3368;
	datos[5][6]= 1960;
	datos[5][7]= 440;
	datos[5][8]= 32;
	datos[5][9]= 0;
	datos[6][0]= 1;
	datos[6][1]= 36;
	datos[6][2]= 520;
	datos[6][3]= 3896;
	datos[6][4]= 16428;
	datos[6][5]= 39680;
	datos[6][6]= 53744;
	datos[6][7]= 38368;
	datos[6][8]= 12944;
	datos[6][9]= 1600;
	datos[6][10]= 64;
	datos[6][11]= 0;
	datos[7][0]= 1;
	datos[7][1]= 49;
	datos[7][2]= 994;
	datos[7][3]= 10894;
	datos[7][4]= 70792;
	datos[7][5]= 282248;
	datos[7][6]= 692320;
	datos[7][7]= 1022320;
	datos[7][8]= 867328;
	datos[7][9]= 389312;
	datos[7][10]= 81184;
	datos[7][11]= 5792;
	datos[7][12]= 128;
	datos[7][13]= 0;
	datos[8][0]= 1;
	datos[8][1]= 64;
	datos[8][2]= 1736;
	datos[8][3]= 26192;
	datos[8][4]= 242856;
	datos[8][5]= 1444928;
	datos[8][6]= 5599888;
	datos[8][7]= 14082528;
	datos[8][8]= 22522960;
	datos[8][9]= 22057472;
	datos[8][10]= 12448832;
	datos[8][11]= 3672448;
	datos[8][12]= 489536;
	datos[8][13]= 20224;
	datos[8][14]= 256;
	datos[8][15]= 0;
	
	
	while(scanf("%d %d\n",&n,&m)){
		if(n==0 && m==0)
			break;
		
		printf("%d\n",datos[n][m]);
	}
	return 0;
}



