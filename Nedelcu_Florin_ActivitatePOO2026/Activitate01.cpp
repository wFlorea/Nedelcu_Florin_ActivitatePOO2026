#include <iostream>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

struct Casa {
	int nr;
	char* adresa;
	char* proprietar;
};

void afisareCasa(Casa c);

float calculMediuNumereIntregi(int vector[], int dim) {
	int suma = 0;
	for (int i = 0; i < dim; i++) {
		suma += vector[i];
	}
	if (dim > 0) {
		return suma / dim;
	}
}


