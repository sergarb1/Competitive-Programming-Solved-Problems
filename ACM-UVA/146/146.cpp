
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
const int MAX = 60;

int charcmp(const void *a, const void *b) {
	char *A;
	char *B;
	A = (char *) a;
	B = (char *) b;
	return (*A - *B);
}

int main() {
	char pal[60];
	cin >> pal;
	while (pal[0] != '#') {
		int s = strlen(pal);
		bool ok = false;
		for (int i = s-1; !ok and i > 0; i--) {
			for (int j = i-1; !ok and j >= 0; j--) {
				if (pal[j] < pal[i]) {
					char aux;
					aux = pal[i];
					pal[i] = pal[j];
					pal[j] = aux;
					//cout << " j: " << j << " i: "<< i ;
					qsort(pal+j+1, s-j-1 ,sizeof(char), charcmp);
					ok = true;
				}
			}
		}
		if (!ok)
			cout << "No Successor" << endl;
		else 
			cout << pal << endl;

		cin >> pal;
	}
}



