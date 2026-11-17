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
	float suma = 0;
	for (int i = 0; i < dim; i++) {
		suma += vector[i];
	}
	if (dim > 0) {
		return suma / dim;
	}
	return 0; 
}

void afisareVector(int* vector, int dimensiune) {
	for (int i = 0; i < dimensiune; i++) {
		cout << endl << "Vector[" << i << "] = " << vector[i];
	}
}

int pozitieMaximInVector(int* vector, int dimensiune) {
	int pozitieMax = 0;
	for (int i = 1; i < dimensiune; i++) {
		if (vector[pozitieMax] < vector[i]) {
			pozitieMax = i;
		}
	}
	return pozitieMax;
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

	int* vectorNumereIntregi;
	int dimensiune;
	cout << endl << "Introdu dimensiunea: ";
	cin >> dimensiune;

	vectorNumereIntregi = new int[dimensiune];
	for (int i = 0; i < dimensiune; i++) {
		cout << endl << "Vector[" << i << "] = ";
		cin >> vectorNumereIntregi[i];
	}

	cout << endl << "Valorile din vector sunt: ";
	afisareVector(vectorNumereIntregi, dimensiune);

	cout << endl << "Pozitia maximului din vector este: " << pozitieMaximInVector(vectorNumereIntregi, dimensiune);
	delete[] vectorNumereIntregi;
	return 0;
}

void afisareCasa(Casa c) {
	cout << endl << "Casa se afla la adresa: " << c.adresa << ", numarul " << c.nr << " are proprietar pe " << c.proprietar << ".";
}