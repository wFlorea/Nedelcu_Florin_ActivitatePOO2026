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
	return 0;

}

void afisareCasa(Casa c) {
	cout << endl << "Casa se afla la adresa: " << c.adresa << ", numarul " << c.nr << " are proprietar pe " << c.proprietar << ".";
}