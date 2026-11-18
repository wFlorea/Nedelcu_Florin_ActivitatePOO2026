#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <cstring>
#include <string>

class Cofetarie {
private:
	const int id;
	string denumire;
	int nrProduse;
	float* preturi;
	int nrAngajati;
public:
	static int nrCofetarii;
	static int totalAngajati;
	Cofetarie() : id(++nrCofetarii) {
		this->denumire = "Cofetaria mea";
		this->nrProduse = 0;
		this->preturi = nullptr;
		this->nrAngajati = 3;
		totalAngajati += nrAngajati;
	}	
	Cofetarie(string denumire, int nrProduse, float* preturi, int nrAngajati) : id(++nrCofetarii) {
		this->denumire = denumire;
		this->nrProduse = nrProduse;
		this->preturi = new float[nrProduse];
		for (int i = 0; i < nrProduse; i++) {
			this->preturi[i] = preturi[i];
		}
		this->nrAngajati = nrAngajati;
		totalAngajati += nrAngajati;
	}
	void afisare() {
		
		cout << endl << "-----------------------------------------" << endl;
		cout << endl << "Cofetaria cu id-ul: " << this->id << endl;
		cout << endl << "Denumirea: " << this->denumire << endl;
		cout << endl << "Numarul de produse: " << this->nrProduse << endl;
		cout << endl << "Preturile produselor: " << endl;
		for (int i = 0; i < this->nrProduse; i++) {
			cout << endl << this->preturi[i] << " Lei" << endl;
		}
		cout << endl << "Numarul de angajati: " << this->nrAngajati << endl;
		cout << endl << "Numarul de cofetarii: " << nrCofetarii << endl;
		cout << endl << "Numarul total de angajati: " << totalAngajati << endl;
		cout << endl << "-----------------------------------------" << endl;
	}
};



int Cofetarie::nrCofetarii = 0;
int Cofetarie::totalAngajati = 0;


int main() {
	Cofetarie c1;
	float* preturi = new float[3] { 10.5, 12, 33.5};
	Cofetarie c2("Smecherescu", 3, preturi, 5);
	Cofetarie principala;
	c1.afisare();
	c2.afisare();
	principala.afisare();
	delete[] preturi;
	return 0;
}
