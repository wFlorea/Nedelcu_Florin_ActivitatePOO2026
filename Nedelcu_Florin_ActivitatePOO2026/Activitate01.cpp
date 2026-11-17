#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <cstring>

struct Casa {
	int nr;
	char* adresa;
	char* proprietar;
};

void afisareCasa(Casa c);

float calculMedieNumereIntregi(int vector[], int dim) {
	int suma = 0;
	for (int i = 0; i < dim; i++) {
		suma += vector[i];
	}
	if (dim > 0) {
		return suma / dim;
	}
}

int main() {
	cout << "Mata are mere";

	Casa mata;
	mata.nr = 7;
	mata.adresa = new char[strlen("Strada Bisericii") + 1];
	strcpy(mata.adresa, "Strada Bisericii");
	mata.proprietar = new char[strlen("Florea") + 1];
	strcpy(mata.proprietar, "Florea");

	afisareCasa(mata);

	delete[] mata.adresa;
	delete[] mata.proprietar;

	int vector[] = { 4, 5, 7, 2, 3 };
	int dim = 5;
	cout << endl << "Media este: " << calculMedieNumereIntregi(vector, dim);

	return 0;
}

void afisareCasa(Casa c) {
	cout << endl << "Casa se afla la adresa: " << c.adresa << ", numarul " << c.nr << " are proprietar pe " << c.proprietar << ".";
}