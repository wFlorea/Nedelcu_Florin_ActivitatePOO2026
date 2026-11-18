#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <cstring>
#include <string>


class Elev {
private:
	string nume;
	int nrNote;
	int* note;
public:
	Elev(string nume, int nrNote, int* note) {
		this->nume = nume;
		this->nrNote = nrNote;
		this->note = new int[nrNote];
		for (int i = 0; i < nrNote; i++) {
			this->note[i] = note[i];
		}
	}
	void afisare() {
		cout << endl << this->nume << ": ";
		for (int i = 0; i < this->nrNote; i++) {
			cout << this->note[i] << " ";
		}
	}
	~Elev() {
		delete[] this->note;
	}
};

int main() {
	int* note = new int[3] { 10, 9, 8 };
	Elev e1("Ana", 3, note);
	delete[] note;
	e1.afisare();
	return 0;
}